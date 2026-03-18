                       // Task 1 | Number Guessing Game  | Prince Kumar
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    // Initialize random seed with current time
    std::srand(std::time(nullptr));

    // generate random number between (1-100)
    const int secret_number = std::rand() % 100 + 1;
    int user_guess;
    int attempts = 0;

    std::cout << "Welcome to the Number Guesser Challenge!\n";
    std::cout << "I've picked a number between 1 and 100.\n\n";

    // game loop
    do {
        std::cout << "Enter your guess: ";
        std::cin >> user_guess;
        attempts++;

        if (user_guess < secret_number) {
            std::cout << "Too low! Aim higher.\n";
        } else if (user_guess > secret_number) {
            std::cout << "Too high! Try a smaller number.\n";
        }
    } while (user_guess != secret_number);

    // victory message
    std::cout << "\nCongratulations! You guessed the number "
              << secret_number << " in " << attempts << " attempts.\n";

    return 0;
}