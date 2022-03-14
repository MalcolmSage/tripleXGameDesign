#include <iostream>

int main()
{
    // Print the game setting to terminal
    std::cout << "You are a secret agent breaking into a secure server room\n";
    std::cout << "Enter the correct code to continue...\n\n";

    // generate three numbers for code breaking
    const int CodeA = 4;
    const int CodeB = 3;
    const int CodeC = 2;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // print sum and product to terminal
    std::cout << "+ There are 3 numbers in the code\n";
    std::cout << "\n+ The codes add up to: " << CodeSum;
    std::cout << "\n+ The codes multiply to give: " << CodeProduct;

    // get user input for code guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Check if the player guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "You did it!\n";
    }   
    else 
    {
        std::cout << "You didn't do it.\n";

    }
 
    return 0;
}