#include <cstdlib>
#include <iostream>
#include <windows.h>
#include <fstream>

unsigned charToDigit(char ch)
{
    return ch - '0';
}

bool isDigit(char ch)
{
    return ch >= '0' && ch <= '9';
}

bool isValidNumber(const char* str)
{
    if (!str || !*str)
        return false; 

    if (*str == '-')
        str++;

    if (!*str)
        return false; 

    while (*str)
    {
        if (!isDigit(*str))
            return false;
        str++;
    }
    return true;
}

unsigned stringToNumber(const char* str)
{
    unsigned result = 0;

    while (*str)
    {
        if (isDigit(*str)) 
        {
            int digit = charToDigit(*str);
            (result *= 10) += digit;
        }
        str++;
    }
    return result;
}

int myAtoi(const char* str)
{
    if (!str)
        return 0;
    if (*str == '-')
        return -1 * stringToNumber(str + 1);

    return stringToNumber(str);
}

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
        energy = money = 60;
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
    int psycheGain = 40;
    if (energy < 80 && energy >= 40)
    {
        psycheGain = psycheGain * 0.75;
    }
    else if (energy > 0 && energy < 40)
    {
        psycheGain = psycheGain * 0.5;
    }
    psyche += psycheGain;
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
    int moneyGain = 40;
    if (energy < 80 && energy >= 40)
    {
        moneyGain = moneyGain * 0.75;
    }
    else if (energy > 0 && energy < 40)
    {
        moneyGain = moneyGain * 0.5;
    }
    money += moneyGain;
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
    if (money <= 0) {
        std::cout << "\n+--------------------------------------+\n";
        std::cout << "|             !GAME OVER!              |\n";
        std::cout << "|     You ran out of money and died    |\n";
        std::cout << "|             of hunger!               |\n";
        std::cout << "+--------------------------------------+\n";
    }
    else if (psyche <= 0) {
        std::cout << "\n+--------------------------------------+\n";
        std::cout << "|             !GAME OVER!              |\n";
        std::cout << "|    Your psyche couldn't handle it    |\n";
        std::cout << "|    and you left the university!      |\n";
        std::cout << "+--------------------------------------+\n";
    }
    else if (examsTaken == 5) {
        std::cout << "\n+--------------------------------------+\n";
        std::cout << "|          !CONGRATULATIONS!           |\n";
        std::cout << "|      You took all the exams and      |\n";
        std::cout << "|  survived the session of your life!  |\n";
        std::cout << "+--------------------------------------+\n";
    }
    else {
        std::cout << "\n+--------------------------------------+\n";
        std::cout << "|             !GAME OVER!              |\n";
        std::cout << "|   You failed to pass all the exams!  |\n";
        std::cout << "|     Better luck next summer/year!    |\n";
        std::cout << "+--------------------------------------+\n";
    }
}

void saveGame(int knowledge, int energy, int money, int psyche, int currentDay, int successfulExams, int dayOfFourthExam)
{
    std::ofstream file("savegame.txt");

    if (!file.is_open())
    {
        std::cout << "Could not open file for saving!\n";
        return;
    }

    file << knowledge << std::endl;
    file << energy << std::endl;
    file << money << std::endl;
    file << psyche << std::endl;
    file << currentDay << std::endl;
    file << successfulExams << std::endl;
    file << dayOfFourthExam << std::endl;

    file.close();
}

bool loadGame(int& knowledge, int& energy, int& money, int& psyche, int& currentDay, int& successfulExams, int& dayOfFourthExam)
{
    std::ifstream file("savegame.txt");

    if (!file.is_open())
    {
        std::cout << "Could not open file for loading!\n";
        return false;
    }

    if (file >> knowledge >> energy >> money >> psyche >> currentDay >> successfulExams >> dayOfFourthExam)
    {
        file.close();
        if (currentDay < 1) return false;
        return true;
    }

    file.close();
    return false;
}

void drawStats(int day, int money, int energy, int psyche, int knowledge, int exams) {
    std::cout << "\n";
    std::cout << "+-----------------------------+\n";
    std::cout << "| Day: " << day << " / 45                 |\n";
    std::cout << "+-----------------------------+\n";
    std::cout << "| Money:     " << money << "               |\n";
    std::cout << "| Energy:    " << energy << "               |\n";
    std::cout << "| Psyche:    " << psyche << "               |\n";
    std::cout << "| Knowledge: " << knowledge << "               |\n";
    std::cout << "| Exams:     " << exams << " / 5            |\n";
    std::cout << "+-----------------------------+\n";
}

const size_t LENGTH = 50;

int main()
{
    srand(time(nullptr));
    int randomNum = (rand() % 31) + 1;

    int knowledge, energy, money, psyche, luck, examNumber, currentDay, successfulExams, dayOfFourthExam;
    knowledge = energy = money = psyche = luck  = successfulExams = dayOfFourthExam = 0;
    currentDay = 1;

    bool gameLoad = false;
    
    int startChoice;
    char input[LENGTH];

    std::cout << "+--------------------------+\n";
    std::cout << "|!WELCOME TO STUDENT QUEST!|\n";
    std::cout << "+--------------------------+\n\n";
    std::cout << "1. New Game\n";
    std::cout << "2. Load Game\n";

    do {
        std::cin >> input; 

        if (isValidNumber(input)) {
            startChoice = myAtoi(input);
            if (startChoice < 1 || startChoice > 2) {
                std::cout << "Please enter 1 or 2!\n";
                startChoice = 0;
            }
        }
        else {
            std::cout << "Invalid input! Please enter a number.\n";
            startChoice = 0;
        }
    } while (startChoice == 0);

    if (startChoice == 2)
    {
        if (loadGame(knowledge, energy, money, psyche, currentDay, successfulExams, dayOfFourthExam))
        {
            std::cout << "Save file found! Loading...\n\n";
            gameLoad = true;
        }
        else
        {
            std::cout << "No save file found. Starting new game.\n\n";
            gameLoad = false;
        }
    }

    if (!gameLoad)
    {
        int difficulty;

        do
        {
            std::cout << "Select difficulty (1-Easy, 2-Normal, 3-Hard)\n";

            std::cin >> input;

            if (isValidNumber(input)) {
                difficulty = myAtoi(input);
                if (difficulty < 1 || difficulty > 3) {
                    std::cout << "Please enter 1, 2 or 3!\n";
                    difficulty = 0;
                }
            }
            else {
                std::cout << "Invalid input! Numbers only.\n";
                difficulty = 0;
            }
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
        } while (difficulty != 1 && difficulty != 2 && difficulty != 3);

        dayOfFourthExam = (rand() % 18) + 1;
    }

    bool gameOver = 0;
    bool earlyExit = 0;

    while (currentDay < 46 && !gameOver)
    {
        saveGame(knowledge, energy, money, psyche, currentDay, successfulExams, dayOfFourthExam);

        int randomEventChance;
        randomEventChance = rand() % 30 + 1;

        if (randomEventChance == 1)
        {
            std::cout << "!!!RANDOM EVENT!!!";
            int randomEventType = rand() % 4 + 1;
            randomEvent(randomEventType, money, psyche, energy, currentDay);
        }

        drawStats(currentDay, money, energy, psyche, knowledge, successfulExams);

        if (energy <= 0)
        {
            std::cout << "!!!FAINTED FROM FATIGUE (Day skipped) !!! \n";
            faint(energy,currentDay,psyche);
        }

        else 
        {
            if (currentDay == 8 || currentDay == 17 || currentDay == 26
                || currentDay == 26 + dayOfFourthExam || currentDay == 45)
            {
                
                std::cout << "\n |----- EXAM DAY! -----| \n";
                int luck = (rand() % 100) + 1;
                gameOver = takingAnExam(successfulExams, money, knowledge, energy, psyche, luck);
                if (gameOver == 0)
                {
                    std::cout << ">>> EXAM PASSED! Knowledge decreased. <<<\n";
                    int randomKnowldegeLoss = (rand() % knowledge) + 1;
                    knowledge -= randomKnowldegeLoss;
                }
            }

            else
            {
                int action = 0;

                do
                {
                    do {
                        std::cout << "\nChoose action:\n1. Study\n2. Eat\n3. Go out\n4. Sleep\n5. Work\n6. Save & Exit\nChoice: ";
                        std::cin >> input; 

                        if (isValidNumber(input)) {
                            action = myAtoi(input);
                            if (action < 1 || action > 6) {
                                std::cout << "Invalid number! Choose 1-6.\n";
                                action = 0;
                            }
                        }
                        else {
                            std::cout << "Invalid input! Numbers only.\n";
                            action = 0;
                        }
                    } while (action == 0);

                    if (action == 1)
                    {   
                            int typeOfLearning=0;

                            do 
                            {
                                std::cout << "  1. Lectures, 2. Home, 3. With friends: ";
                                std::cin >> input;
                                if (isValidNumber(input))
                                {
                                    typeOfLearning = myAtoi(input);
                                    if (typeOfLearning == 1 || typeOfLearning == 2 || typeOfLearning == 3)
                                    {
                                        study(typeOfLearning, knowledge, psyche, energy);
                                    }
                                    else std::cout << "Invalid command!\n";

                                }
                              
                            } while (typeOfLearning < 1 || typeOfLearning > 3);
                    }
                    else if (action == 2)
                    {
                        eating(psyche, money, energy);
                        int randomPoison = (rand() % 25) + 1;
                        if (randomPoison == 1)
                        {
                            std::cout << "You got food poisoning!\n";
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
                            std::cout << "You got robbed!\n";
                            energy -= 10;
                            psyche -= 25;
                            if (money > 30)
                            {
                                money = 10;
                            }
                            else
                            {
                                std::cout << "The robber laughed at you!\n";
                                psyche -= 15;
                                money--;
                            }
                        }
                    }
                    else if (action == 4)
                    {
                        goToSleep(energy, psyche);
                        int randomSleepParalysis = (rand() % 30) + 1;
                        if (randomSleepParalysis == 1)
                        {
                            std::cout << "You got sleep paralysis!\n";
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
                            money -= 10;
                            psyche -= 10;
                        }
                    }
                    else if (action == 6)
                    {
                        int exitCommand=0;
                        do
                        {
                            std::cout << "Are you sure? (1. Yes | 2. No)\n";

                            std::cin >> input;
                            if (isValidNumber(input))
                            {
                                exitCommand = myAtoi(input);
                                if (exitCommand == 1)
                                {
                                    saveGame(knowledge, energy, money, psyche, currentDay, successfulExams, dayOfFourthExam);
                                    earlyExit = 1;
                                    gameOver = 1;
                                    std::cout << "|--------------------------------------|\n";
                                    std::cout << "| !GAME OVER!                          |\n";
                                    std::cout << "|                                      |\n";
                                    std::cout << "| Thank you for playing!               |\n";
                                    std::cout << "|--------------------------------------|\n";
                                }
                                else if (exitCommand == 2) currentDay--;
                            }
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



        }
        currentDay++;

    }
    if(earlyExit != 1)
    gameEnd(money, psyche, successfulExams);
    else 
    {
        earlyExit = 0;
    }
}
