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

int main()
{
    int knowledge, energy, money, psyche, luck, examNumber;
    knowledge = energy = money = psyche = luck = 0;
}
