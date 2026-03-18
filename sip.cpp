#include <iostream>  // for cout<< and cin>> operations
#include <cstdlib>  // for rand() and srand() functions
#include <ctime>    // for time() function (to seed random number generator)

int main() {
    // Seed the random number generator using the current time.
    // This ensures that a different sequence of random numbers is generated each time
    // the program runs, making the game more unpredictable.
    srand(static_cast<unsigned int>(time(0)));

    // Generate a random number between 1 and 100 (inclusive).
    // rand() % 100 generates a number from 0 to 99. Adding 1 shifts it to 1 to 100.
    int randomNumber = (rand() % 100) + 1;

    int userGuess = 0; // Variable to store the user's guess
    int attempts = 0;   // Variable to count the number of attempts

    // Game introduction
    std::cout << "Welcome to the Number Guessing Game!\n";
    std::cout << "I'm thinking of a number between 1 and 100.\n";
    std::cout << "Can you guess what it is?\n\n";

    // Loop continues until the user guesses the correct number
    do {
        // Prompt the user for their guess
        std::cout << "Enter your guess: ";
        std::cin >> userGuess; // Read the user's input

        // Input validation
        if (std::cin.fail()) {
            std::cout << "Invalid input! Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }

        // Increment the attempts counter
        attempts++;

        // Provide feedback based on the guess
        if (userGuess > randomNumber) {
            std::cout << "Too high! Try again.\n";
        } else if (userGuess < randomNumber) {
            std::cout << "Too low! Try again.\n";
        } else {
            // This block is executed when the user guesses correctly
            std::cout << "\nCongratulations! You guessed the number " << randomNumber;
            std::cout << " in " << attempts << " attempts!\n";
        }
    } while (userGuess != randomNumber); // Continue loop if the guess is not correct

    // End of the program
    return 0;
}


