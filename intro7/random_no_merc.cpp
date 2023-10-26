#include <iostream>
#include <limits>
#include "Random.h"

int getGuess(int count){
    while (true)
    {
        std::cout<<"Guess #"<<count<<": ";
        int guess{};
        std::cin>>guess;
        
        if (std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            continue;
        }
        if (guess < 1 || guess > 100)
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        return guess;
    }
}

bool playGame(int guesses,int number){
    for (int count{1}; count <= guesses; ++count)
    {
        
        int guess{getGuess(count)};

        if (guess>number) std::cout<<"Your guess is too high.\n";
        else if (guess<number) std::cout<<"Your guess is too low.\n";
        else return true;// guess==number
    }
    return false;
}
bool playAgain(){
    while (true)
    {
        char ch{};
        std::cout<<"Would you like to play again (y/n) ? ";
        std::cin>>ch;
        switch (ch)
        {
        case 'y':
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            return true;
        case 'n':
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return false; 
        default:
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

int main(){
    constexpr int guesses{7};
    do
    {
        int number{Random::get(1,100)};
        std::cout<<"Let's play a game. I'm thinking of a number between 1 and 100. You have " << guesses << " tries to guess what it is.\n";
        bool won{playGame(guesses,number)};
        
        if (won) std::cout<<"Correct! you win!";
        else std::cout<<"You lose. The correct number was "<<number<<'\n';
    } while (playAgain());

    std::cout<<"Thank you for playing.\n";
    return 0;
    
}