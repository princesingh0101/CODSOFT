#include <iostream>
#include <limits>
#include <string> 

int main() { double num1, num2; char operation; std::string continueChoice; 
    std::cout << "Hi! Together, let's do some math." << std::endl;

    do { std::cout << "----------------------------------" << std::endl;
         std::cout << "Please enter your first number: ";
          while (!(std::cin >> num1)) { std::cout << "Sorry! That number is invalid. Try again: ";
             std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); }

        std::cout << "Now, what action are you interested in carrying out? (+, -, *, /): "; 
        while (!(std::cin >> operation) || (operation!= '+' && operation!= '-' && operation!= '*' && operation!= '/')) { std::cout << "Well, that's not a legitimate operation. Please select from +, -, *, /: "; 
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
         }

        std::cout << "Excellent! What is your second number? : "; while (!(std::cin >> num2)) { std::cout << "Friend, it's not a number! Kindly input a valid number: "; 
            std::cin.clear();
                     std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                }
        
                double outcome;
        
               
                switch (operation) { case '+': outcome = num1 + num2; break; case '-': outcome = num1 - num2; break;

                        case '*':
                            outcome = num1 * num2;
                            break;
                        case '/':
                            if (num2 != 0)
                                outcome = num1 / num2;
                            else {
                                std::cout << "Error: Division by zero!" << std::endl;
                                continue;
                            }
                            break;
                    }
    
                    std::cout << "Result: " << outcome << std::endl;
    
                    std::cout << "Do you want to do one more calculation? (y/n): ";
                    std::cin >> continueChoice;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
                } while (continueChoice == "y" || continueChoice == "Y");
    
                std::cout << "Thank you for utilizing the calculator. Goodbye!" << std::endl;
                return 0;
            }