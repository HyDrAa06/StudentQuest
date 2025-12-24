#include <iostream>

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

void takingAnExam(const int knowledge, int& energy)
{
    energy -= 20;
}

int main()
{
    int knowledge, energy, money, psyche, luck, examNumber;
    knowledge = energy = money = psyche = luck = 0;
}
