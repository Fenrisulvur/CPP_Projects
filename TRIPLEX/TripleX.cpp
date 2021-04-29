#include <iostream>
#include <ctime>


void PrintIntroduction(int LevelDifficulty)
{
    std::cout << "\n\nYou are a secret agent breaking into a [level - " << LevelDifficulty << "] secure server room...";
    std::cout << "\nYou need to enter the correct codes to continue...";
}

bool PlayGame(int LevelDifficulty)
{
    PrintIntroduction(LevelDifficulty);
    
    //Set the 3 codes
    const int CodeA = rand() % LevelDifficulty + LevelDifficulty;
    const int CodeB = rand() % LevelDifficulty + LevelDifficulty;
    const int CodeC = rand() % LevelDifficulty + LevelDifficulty;
    
    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    //Print Sum & Product
    std::cout << std::endl;
    std::cout << "+ There are 3 numbers in the code\n";
    std::cout << "\n+ The codes add up to: " << CodeSum;
    std::cout << "\n+ The codes multiply to give: " << CodeProduct;

    //Capture and display player Guess
    int GuessA, GuessB, GuessC;
    std::cout << "\nEnter a guess: ";
    std::cin >> GuessA >> GuessB >> GuessC;

    std::cout << "\n> You entered: " << GuessA << GuessB << GuessC;
    
    //Calc player Guess Sum & Product
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    //Output player Guess Sum & Product
    std::cout << "\n> Your Guess Sum: " << GuessSum;
    std::cout << "\n> Your Guess Product: " << GuessProduct;
    
    //Win condition
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\nYou win at level " << LevelDifficulty << "!";
        return true;
    } 
    else
    {
        std::cout << "\nYou lose! at level " << LevelDifficulty << "!";
        return false;
    }
}

int main()
{
    srand(time(NULL));
    int LevelDifficulty = 1;
    int const MaxDifficulty = 5;

    while (LevelDifficulty <= MaxDifficulty )
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();
        std::cin.ignore();

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
        
    }

    std::cout << "\nCongratulations on completing the game!";

    return 0;
}