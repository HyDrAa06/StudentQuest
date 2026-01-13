#include <iostream>
#include <cstdlib>


void setStatsByDifficulty(const char* difficulty, int& knowledge, 
    int& psyche, int& energy, int& money)
{
    if (!difficulty)
    {
        return;
    }

    if (difficulty == "easy")
    {
        knowledge = 80;
        energy = money = psyche = 100;
    }
    else if (difficulty == "normal")
    {
        knowledge = 50;
        energy = money = psyche = 80;
    }
    else if (difficulty == "hard")
    {
        knowledge = 35;
        energy = money = 80;
        psyche = 40;
    }
}

void study(const char* type, int& knowledge,
    int& psyche, int& energy)
{
    if (!type)
    {
        return;
    }
    if (type == "Go to lectures")
    {
        knowledge += 20;
        energy -= 20;
        psyche -= 10;
    }
    else if (type == "Study home")
    {
        knowledge += 15;
        energy -= 15;
        psyche -= 20;
    }
    else if (type == "Study with friends")
    {
        knowledge += 5;
        energy -= 10;
        psyche += 10;
    }
    else 
    {
        return;
    }
}

void eating(int& psyche, int& money, int& energy)
{
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
    energy += 50;
    psyche += 10;
}

void work(int& psyche, int& money, int& energy)
{
    money += 40;
    energy -= 20;
    psyche -= 10;
}

void takingAnExam(int& successfulExams, const int money, int& knowledge, int& energy, int& psyche, int luck)
{                     //successfulExams + 1 - 1
    double penalty = (successfulExams) * 5;
    double success = (knowledge * 0.75) + (psyche * 0.1)
        + (energy * 0.1) + (luck *0.2) - penalty;
    energy -= 20;

    if (success >= 75)
    {
        successfulExams++;
        psyche+=20;
    }
    else 
    {
        psyche -= 30;
        gameEnd(money, psyche, successfulExams);
    }
}

void faint(int& energy, int& currentDay)
{
    currentDay++;
    energy = 40;
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

bool gameEnd(const int money, const int psyche, const int examsTaken)
{
    if (money == 0)
    {
        std::cout << "╔══════════════════════════════════════╗\n";
        std::cout << "║ 💥 ИГРАТА ПРИКЛЮЧИ!                  ║\n";
        std::cout << "║                                      ║\n";
        std::cout << "║ Остана без пари и умря от глад       ║\n";
        std::cout << "╚══════════════════════════════════════╝\n";         
        
        return 1;
    }
    if (psyche == 0)
    {
        std::cout << "╔══════════════════════════════════════╗\n"; 
        std::cout << "║ 💥 ИГРАТА ПРИКЛЮЧИ!                  ║\n"; 
        std::cout << "║                                      ║\n"; 
        std::cout << "║ Твоята психика не издържа            ║\n"; 
        std::cout << "║ и си напуснал университета           ║\n"; 
        std::cout << "╚══════════════════════════════════════╝\n"; 

        return 1;
    }
    if (examsTaken == 5)
    {
        std::cout << "╔══════════════════════════════════════╗\n";
        std::cout << "║ 🎓 ПОЗДРАВЛЕНИЯ!                     ║\n";
        std::cout << "║                                      ║\n";
        std::cout << "║ Взе всички изпити и оцеля            ║\n";
        std::cout << "║ в сесията на живота си!              ║\n";
        std::cout << "╚══════════════════════════════════════╝\n"; 

        return 1;
    }
    return 0;
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

    int dayOfFourthExam = (rand() & 19) + 1;

    while (currentDay < 46)
    {
        
        if (currentDay == 8 || currentDay == 17 || currentDay == 26
            || currentDay == 26 + dayOfFourthExam || 45)
        {       
            int luck = (rand() % 100) + 1;
            takingAnExam(successfulExams, money, knowledge, energy,psyche,luck);
        }
        
    }

    gameEnd(1, 0,0);
}
