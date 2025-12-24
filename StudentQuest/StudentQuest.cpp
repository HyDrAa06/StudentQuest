#include <iostream>

void setStatsByDifficulty(const char* difficulty, int& knowledge, 
    int& psyche, int& energy, int& luck, int& money)
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

int main()
{
    
}
