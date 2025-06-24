#include <iostream>
#include <limits>
#include <string> // For std::string to handle user's 'y/n' input

int main() {
    double num1, num2;
    char operation;
    std::string continueChoice; // To store user's choice to continue

    std::cout << "Greetings! Let's do some math together." << std::endl;

    do {
        std::cout << "\n-------------------------------------" << std::endl;
        std::cout << "Enter your first number, please: ";
        while (!(std::cin >> num1)) {
            std::cout << "Oops! That's not a valid number. Try again: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        std::cout << "Now, what operation would you like to perform? (+, -, *, /): ";
        while (!(std::cin >> operation) || (operation != '+' && operation != '-' && operation != '*' && operation != '/')) {
            std::cout << "Hmm, that's not a valid operation. Please pick one from +, -, *, /: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        std::cout << "Great! And what's your second number? : ";
        while (!(std::cin >> num2)) {
            std::cout << "Not a number, friend! Please enter a valid number: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        double result;

        switch (operation) {
            case '+':
                result = num1 + num2;
                std::cout << "Alright, " << num1 << " + " << num2 << " equals: " << result << std::endl;
                break;
            case '-':
                result = num1 - num2;
                std::cout << "So, " << num1 << " - " << num2 << " equals: " << result << std::endl;
                break;
            case '*':
                result = num1 * num2;
                std::cout << "Multiplying " << num1 << " by " << num2 << " gives us: " << result << std::endl;
                break;
            case '/':
                if (num2 != 0) {
                    result = num1 / num2;
                    std::cout << "Dividing " << num1 << " by " << num2 << " results in: " << result << std::endl;
                } else {
                    std::cout << "Oh dear! We can't divide by zero. Please try again with a different second number." << std::endl;
                }
                break;
            default:
                std::cout << "Something went unexpectedly wrong! My apologies." << std::endl;
                break;
        }

        std::cout << "\nWould you like to perform another calculation? (yes/no): ";
        std::cin.clear(); // Clear any potential error flags from previous input
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the buffer
        std::getline(std::cin, continueChoice); // Read the entire line

    } while (continueChoice == "yes" || continueChoice == "y" || continueChoice == "Yes" || continueChoice == "Y");

    std::cout << "\nThank you for using the calculator! Have a great day!" << std::endl;

    return 0;
}
