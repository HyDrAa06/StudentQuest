#include <cstdlib>
#include <iostream>
#include <windows.h>

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
    std::cout << "Mom and Dad are sending you money.! \n";
    money += 30;
}
void coffeeWithAFriend(int &psyche)
{
    std::cout << "A friend buys you coffee! \n";
    psyche += 10;
}
void getIll(int& energy)
{
    std::cout << "You got ill! \n";
    energy -= 20;
}

void electricityCutdown(int& currentDay)
{
    std::cout << "Тhe electricity at home went out! \n";
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
        std::cout << "|--------------------------------------|\n";
        std::cout << "| !GAME OVER!                          |\n";
        std::cout << "|                                      |\n";
        std::cout << "| You ran out of money and died        |\n";
        std::cout << "| of hunger!                           |\n";
        std::cout << "|--------------------------------------|\n";

        return;
    }
    if (psyche <= 0)
    {
        std::cout << "|--------------------------------------|\n";
        std::cout << "| !GAME OVER!                          |\n";
        std::cout << "|                                      |\n";
        std::cout << "| Your psyche couldn't handle          |\n"; 
        std::cout << "| it and you left the university!      |\n"; 
        std::cout << "|--------------------------------------|\n";

        return;
    }
    if (examsTaken == 5)
    {
        std::cout << "|--------------------------------------|\n";
        std::cout << "| !CONGRATULATIONS!                    |\n";
        std::cout << "|                                      |\n";
        std::cout << "| You took all the exams and           |\n";
        std::cout << "| survived the session of your life!   |\n";
        std::cout << "|--------------------------------------|\n";

        return;
    }
    if (examsTaken != 5)
    {
        std::cout << "|--------------------------------------|\n";
        std::cout << "| !GAME OVER!                          |\n";
        std::cout << "|                                      |\n";
        std::cout << "| You failed to pass all the exams!    |\n";
        std::cout << "| Better luck next summer/year!        |\n";
        std::cout << "|--------------------------------------|\n";
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
    knowledge = energy = money = psyche = luck  = successfulExams = 0;
    currentDay = 1;

    int difficulty;

    do 
    {
        std::cout << "Select difficulty (1-Easy, 2-Normal, 3-Hard)\n";
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
            std::cout << "Invalid command!\n";

        }
    } 
    while (difficulty != 1 && difficulty != 2 && difficulty != 3);
    
    int dayOfFourthExam = (rand() % 19) + 1;

    bool gameOver = 0;
    bool earlyExit = 0;

    while (currentDay < 46 && !gameOver)
    {
        int randomEventChance;
        randomEventChance = rand() % 30 + 1;

        if (randomEventChance == 1)
        {
            std::cout << "!!!RANDOM EVENT!!!";
            int randomEventType = rand() % 4 + 1;
            randomEvent(randomEventType, money, psyche, energy, currentDay);
        }

        std::cout << "--- DAY " << currentDay << " ---\n";
        std::cout << "Money: " << money << " Energy: " << energy << " Psyche: " << psyche << " Knowledge:" << knowledge
            << "\n";

        if (energy <= 0)
        {
            std::cout << "!!!FAINTED FROM FATIGUE!!! \n";
            faint(energy,currentDay,psyche);
        }

        else 
        {
            if (currentDay == 8 || currentDay == 17 || currentDay == 26
                || currentDay == 26 + dayOfFourthExam || currentDay == 45)
            {
                
                std::cout << "\n !EXAM! \n";
                int luck = (rand() % 100) + 1;
                gameOver = takingAnExam(successfulExams, money, knowledge, energy, psyche, luck);
                if (gameOver == 0)
                {
                    std::cout << "YOU PASSED! \n\n";
                    int randomKnowldegeLoss = (rand() % knowledge) + 1;
                    knowledge -= randomKnowldegeLoss;
                }
            }

            else
            {
                

                int action = 0;

                do
                {
                    std::cout << "Please slect an action: \n 1. Study \n 2. Eat \n 3. Go out \n 4. Sleep \n 5. Work \n 6. Exit \n Choice: ";
                    std::cin >> action;

                    if (action == 1)
                    {   
                        bool completeAction = 0;
                        do
                        {
                            int typeOfLearning;

                            std::cout << "1. Lectures, 2. Home, 3. With friends: \n";
                            std::cin >> typeOfLearning;

                            if (typeOfLearning == 1 || typeOfLearning == 2 || typeOfLearning == 3)
                            {
                                study(typeOfLearning, knowledge, psyche, energy);
                                completeAction = 1;
                            }
                            else std::cout << "Invalid command!";
                        } 
                        while (!completeAction);
                        
                    }
                    else if (action == 2)
                    {
                        eating(psyche, money, energy);
                        int randomPoison = (rand() % 20) + 1;
                        if (randomPoison == 1)
                        {
                            std::cout << "You got food poisoning!";
                            energy -= 30;
                            psyche -= 15;
                        }
                    }
                    else if (action == 3)
                    {
                        goOut(psyche, money, energy);
                        int randomRob = (rand() % 20) + 1;
                        if (randomRob == 1)
                        {
                            std::cout << "You got robbed!";
                            energy -= 10;
                            psyche -= 25;
                            if (money > 30)
                            {
                                money = 10;
                            }
                            else
                            {
                                std::cout << "The robber laughed at you!";
                                psyche -= 15;
                                money--;
                            }
                        }
                    }
                    else if (action == 4)
                    {
                        goToSleep(energy, psyche);
                        int randomSleepParalysis = (rand() % 20) + 1;
                        if (randomSleepParalysis == 1)
                        {
                            std::cout << "You got sleep paralysis!";
                            energy -= 10;
                            psyche -= 30;
                        }
                    }
                    else if (action == 5) 
                    {
                        work(psyche, money, energy); 
                        int randomBoss = (rand() % 20) + 1;
                        if (randomBoss == 1)
                        {
                            std::cout << "Your boss is in a bad mood!";
                            money - 10;
                            psyche - 10;
                        }
                    }
                    else if (action == 6)
                    {
                        std::cout << "Are you sure? (1. Yes | 2. No)\n";
                        int exitCommand;
                        do
                        {
                            std::cin >> exitCommand;
                            if (exitCommand == 1)
                            {
                                earlyExit = 1;
                                gameOver = 1;
                                std::cout << "|--------------------------------------|\n";
                                std::cout << "| !GAME OVER!                          |\n";
                                std::cout << "|                                      |\n";
                                std::cout << "| Thank you for playing!               |\n";
                                std::cout << "|--------------------------------------|\n";
                            }
                            else if (exitCommand == 2) currentDay--;
                            else std::cout << "Invalid command!\n";

                        }
                        while (exitCommand != 1 && exitCommand != 2);
                    }
                    else std::cout << "Invalid command!\n";
                } while (action < 1 || action > 6);


            }
            if (money <= 0 || psyche <= 0)
            {
                money = 0;
                psyche = 0;
                gameOver = 1;
            }
            if (energy < 0)
            {
                energy = 0;
            }
            if (psyche > 100) 
            {
                psyche = 100;
            }
            if (energy > 100)
            {
                energy = 100;
            }


            else currentDay++;

        }
        
    }
    if(earlyExit != 1)
    gameEnd(money, psyche, successfulExams);
    else 
    {
        earlyExit = 0;
    }
}
