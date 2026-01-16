#include <iostream>
#include <cstdlib>

int myStrcmp(const char* str1, const char* str2)
{
    if (!str1 || !str2)
        return 0;

    while (*str1 && *str2 && *str1 == *str2)
    {
        str1++;
        str2++;
    }

    return *str1 - *str2;
}

void setStatsByDifficulty(const char* difficulty, int& knowledge, 
    int& psyche, int& energy, int& money)
{
    if (!difficulty)
    {
        return;
    }

    if (myStrcmp(difficulty, "easy")==0)
    {
        knowledge = 80;
        energy = money = psyche = 100;
    }
    else if (myStrcmp(difficulty, "normal")==0)
    {
        knowledge = 50;
        energy = money = psyche = 80;
    }
    else if (myStrcmp(difficulty, "hard")==0)
    {
        knowledge = 35;
        energy = money = 80;
        psyche = 40;
    }
}

void study(int type, int& knowledge,
    int& psyche, int& energy)
{
    if (type > 3 || type < 1)
    {
        return;
    }

    int knowledgeGain = 0;
    int startEnergy = energy;

    if (type == 1)
    {
        knowledgeGain += 20;
        energy -= 20;
        psyche -= 10;
    }
    else if (type == 2)
    {
        knowledgeGain += 15;
        energy -= 15;
        psyche -= 20;
    }
    else if (type == 3)
    {
        knowledgeGain += 5;
        energy -= 10;
        psyche += 10;
    }
    else 
    {
        return;
    }

    if (startEnergy < 80 && startEnergy >= 40)
    {
        knowledgeGain = knowledgeGain * 0.75;
    }
    else if (startEnergy < 40 && startEnergy > 0)
    {
        knowledgeGain = knowledgeGain * 0.5;
    }

    knowledge += knowledgeGain;
}

void eating(int& psyche, int& money, int& energy)
{
    if (energy + 20 > 100)
        energy = 100;
    else
        energy += 20;
    money -= 10;
    psyche += 5;
}

void goOut(int& psyche, int& money, int& energy)
{
    psyche += 40;
    money -= 25;
    energy -= 15;
}

void goToSleep(int& energy, int& psyche) 
{
    if (energy + 50 > 100)
        energy = 100;
    else
        energy += 50;
    psyche += 10;
}

void work(int& psyche, int& money, int& energy)
{
    money += 40;
    energy -= 20;
    psyche -= 10;
}

bool takingAnExam(int& successfulExams, const int money, int& knowledge, int& energy, int& psyche, int luck)
{                     //successfulExams + 1 - 1
    double penalty = (successfulExams) * 5;
    double success = (knowledge * 0.75) + (psyche * 0.1)
        + (energy * 0.1) + (luck *0.2) - penalty;
    energy -= 20;

    if (success >= 75)
    {
        successfulExams++;
        psyche += 20;
        if(successfulExams==5)
        return true;

        return false;
    }
    else
    {
        psyche -= 30;
        return true;
    }
}

void faint(int& energy, int& currentDay, int& psyche)
{
    currentDay++;
    energy = 40;
    psyche -= 10;
}

void getMoneyFromParents(int &money)
{
    money += 30;
}
void coffeeWithAFriend(int &psyche)
{
    psyche += 10;
}
void getIll(int& energy)
{
    energy -= 20;
}

void electricityCutdown(int& currentDay)
{
    currentDay++;
}

void randomEvent(const int random, int& money, int& psyche, int& energy, int& currentDay)
{
    if (random == 1)
        getMoneyFromParents(money);
    if (random == 2)
        coffeeWithAFriend(psyche);
    if (random == 3)
        getIll(energy);
    if (random == 4)
        electricityCutdown(currentDay);
}

void gameEnd(const int money, const int psyche, const int examsTaken)
{
    if (money <= 0)
    {
        std::cout << "╔══════════════════════════════════════╗\n";
        std::cout << "║ 💥 ИГРАТА ПРИКЛЮЧИ!                  ║\n";
        std::cout << "║                                      ║\n";
        std::cout << "║ Остана без пари и умря от глад       ║\n";
        std::cout << "╚══════════════════════════════════════╝\n";         
        
        return;
    }
    if (psyche <= 0)
    {
        std::cout << "╔══════════════════════════════════════╗\n"; 
        std::cout << "║ 💥 ИГРАТА ПРИКЛЮЧИ!                  ║\n"; 
        std::cout << "║                                      ║\n"; 
        std::cout << "║ Твоята психика не издържа            ║\n"; 
        std::cout << "║ и си напуснал университета           ║\n"; 
        std::cout << "╚══════════════════════════════════════╝\n"; 

        return;
    }
    if (examsTaken == 5)
    {
        std::cout << "╔══════════════════════════════════════╗\n";
        std::cout << "║ 🎓 ПОЗДРАВЛЕНИЯ!                     ║\n";
        std::cout << "║                                      ║\n";
        std::cout << "║ Взе всички изпити и оцеля            ║\n";
        std::cout << "║ в сесията на живота си!              ║\n";
        std::cout << "╚══════════════════════════════════════╝\n"; 

        return;
    }
    if (examsTaken != 5)
    {
        std::cout << "╔══════════════════════════════════════╗\n";
        std::cout << "║ 💥 ИГРАТА ПРИКЛЮЧИ!                  ║\n";
        std::cout << "║                                      ║\n";
        std::cout << "║ Не успя да вземеш всички             ║\n";
        std::cout << "║ изпити!                              ║\n";
        std::cout << "╚══════════════════════════════════════╝\n";
    }
    return;
}

void startNewGame(const int input)
{
    if (input == 1)
    {

    }
    else 
    {

    }
}

int main()
{
    srand(time(nullptr));
    int randomNum = (rand() % 31) + 1;

    int knowledge, energy, money, psyche, luck, examNumber, currentDay, successfulExams;
    knowledge = energy = money = psyche = luck = currentDay = successfulExams = 0;

    int difficulty;

    do 
    {
        std::cout << "Изберете трудност (1-Easy, 2-Normal, 3-Hard)\n";
        std::cin >> difficulty;

        if (difficulty == 1)
        {
            setStatsByDifficulty("easy", knowledge, psyche, energy, money);
        }
        else if (difficulty == 2)
        {
            setStatsByDifficulty("normal", knowledge, psyche, energy, money);
        }
        else if (difficulty == 3)
        {
            setStatsByDifficulty("hard", knowledge, psyche, energy, money);
        }
        else
        {
            std::cout << "Невалидна команда!\n";

        }
    } 
    while (difficulty != 1 && difficulty != 2 && difficulty != 3);
    
    int dayOfFourthExam = (rand() % 19) + 1;

    bool gameOver = 0;

    while (currentDay < 46 && !gameOver)
    {
        std::cout << "--- ДЕН " << currentDay << " ---\n";
        std::cout << "Пари: " << money << "Енергия: " << energy << "Психика: " << psyche << "Знания" << knowledge
            << "\n";

        if (energy <= 0)
        {
            std::cout << "!!!ПРИПАДНА ОТ УМОРА!!! \n";
            faint(energy,currentDay,psyche);
        }

        else 
        {
            if (currentDay == 8 || currentDay == 17 || currentDay == 26
                || currentDay == 26 + dayOfFourthExam || currentDay == 45)
            {
                std::cout << "ИЗПИТ \n";
                int luck = (rand() % 100) + 1;
                gameOver = takingAnExam(successfulExams, money, knowledge, energy, psyche, luck);
                if (gameOver == 0)
                {
                    std::cout << "ВЗЕ ИЗПИТА! \n";
                }
            }

            else
            {
                int randomEventChance;
                randomEventChance = rand() % 30+1;

                if (randomEventChance == 1)
                {
                    std::cout << "!!!СЛУЧАЙНО СЪБИТИЕ!!!";
                    int randomEventType = rand() % 4 + 1;
                    randomEvent(randomEventType,money,psyche,energy,currentDay);
                }

                int action = 0;

                do
                {
                    std::cout << "Моля изберете действие: \n 1. Учене \n 2. Хранене \n 3. Излизане \n 4. Сън \n 5. Работа \n Избор: ";
                    std::cin >> action;

                    if (action == 1)
                    {   
                        bool completeAction = 0;
                        do
                        {
                            int typeOfLearning;

                            std::cout << "1. Лекции, 2. Вкъщи, 3. С приятели: \n";
                            std::cin >> typeOfLearning;

                            if (typeOfLearning == 1 || typeOfLearning == 2 || typeOfLearning == 3)
                            {
                                study(typeOfLearning, knowledge, psyche, energy);
                                completeAction = 1;
                            }
                            else std::cout << "Невалидна команда!";
                        } 
                        while (!completeAction);
                        
                    }
                    else if (action == 2) eating(psyche, money, energy);
                    else if (action == 3) goOut(psyche, money, energy);
                    else if (action == 4) goToSleep(energy, psyche);
                    else if (action == 5) work(psyche, money, energy);
                    else std::cout << "Невалидна команда!\n";
                } while (action < 1 || action > 5);


            }
            if (money <= 0 || psyche <= 0)
            {
                gameOver = 1;
            }
            else currentDay++;

        }
        
    }

    gameEnd(money, psyche, successfulExams);
}
