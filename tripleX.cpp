#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    std::cout << "\n\nYou are a secret agent breaking into a level " << Difficulty;
    std::cout << " secure server room.\nEnter the correct code to continue...\n\n";
}

bool PlayGame(int Difficulty, int Max)
{
    // Print the game setting to terminal
    PrintIntroduction(Difficulty);

    // generate three numbers for code breaking
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // print sum and product to terminal
    std::cout << "+ There are 3 numbers in the code\n";
    std::cout << "\n+ The codes add up to: " << CodeSum;
    std::cout << "\n+ The codes multiply to give: " << CodeProduct << std::endl;

    // get user input for code guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Check if the player guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        if (Difficulty >= Max)
        {
            return true;
        }
        else
        {
            std::cout << "\n***You made it past this hurdle! On to the next one.***\n";
            return true;
        }
    }
    else
    {
        std::cout << "\n***That wasn't it.. but keep pushing through!***\n";
        return false;
    }
}

int main()
{
    srand(time(NULL));
    const int MaxDifficulty = 5;
    int LevelDifficulty = 1;

    while (LevelDifficulty <= MaxDifficulty) // Loop until all levels are completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty, MaxDifficulty);
        std::cin.clear();  // Clears aby errors
        std::cin.ignore(); // Discards the buffer

        if (bLevelComplete)
        {
            /* Increase level difficulty */
            ++LevelDifficulty;
        }
    }

    std::cout << "\n***You're through the last door! Amazing work operative.***\n";
    return 0;
}