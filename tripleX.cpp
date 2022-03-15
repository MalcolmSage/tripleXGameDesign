#include <iostream>

void PrintIntroduction(int Difficulty)
{
    std::cout << "\n\nYou are a secret agent breaking into a level " << Difficulty;
    std::cout << " secure server room.\n Enter the correct code to continue...\n\n";
}

bool PlayGame(int Difficulty)
{
    // Print the game setting to terminal
    PrintIntroduction(Difficulty);

    // generate three numbers for code breaking
    const int CodeA = 4;
    const int CodeB = 3;
    const int CodeC = 2;

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
        std::cout << "You did it!\n";
        return true;
    }
    else
    {
        std::cout << "You didn't do it.\n";
        return false;
    }
}

int main()
{
    int LevelDifficulty = 1;
    while (LevelDifficulty < 10)
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); //Ckears aby errors
        std::cin.ignore();  // Discards the buffer

        if (bLevelComplete)
        {
            /* Increase level difficulty */
            ++LevelDifficulty;
        }
        
    }
    return 0;
}