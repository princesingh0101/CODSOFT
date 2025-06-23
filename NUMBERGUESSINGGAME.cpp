#include <iostream>
#include <cstdlib>
#include <ctime>

#include <limits>

int main() { std::srand(static_cast<unsigned int>(std::time(0)));

    const int MAX_NUM = 100; const int MIN_NUM = 1;

    int secretNumber = (std::rand() % (MAX_NUM - MIN_NUM + 1)) + MIN_NUM;

    int attempts = 0; int userGuess = 0;

    std::cout << "Welcome to the Number Guessing Game!" << std::endl; 
    std::cout << "I have selected a number between " << MIN_NUM << " and " << MAX_NUM << "." << std::endl;   std::cout << "Can you guess what it is?" << std::endl;

    while (userGuess!= secretNumber) { std::cout << " Enter your guess: ";

        while (!(std::cin >> userGuess)) { std::cout << "Invalid input. Kindly input a number: "; std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); }

        attempts++;

        if (userGuess < secretNumber) {
            std::cout << "Too low! Try again." << std::endl;
        } else if (userGuess > secretNumber) {
            std::cout << "Too high! Try again." << std::endl;
        } else {
            std::cout << "Congratulations! You correctly guessed the number " << secretNumber;
            std::cout << " in " << attempts << " attempts." << std::endl;
        }

    return 0; }