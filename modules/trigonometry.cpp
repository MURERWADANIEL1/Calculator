#include "trigonometry.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>

constexpr double PI = std::acos(-1.0);

void performTrigonometry(){
    std::string unitChoice;
    std::string input;

    std::cout << "\n ******** Welcome to the Trigonometry Calculator ******\n\n";
    std::cout << "This Calculator supports sin, cos, tan and their inverses (asin, acos, atan).\n";

    while (true) {
        std::cout << "\nChoose unit and enter:\n"
                  << "  r - Radians\n"
                  << "  d - Degrees\n"
                  << "  b - Back to previous menu\n"
                  << "  q - Quit\n"
                  << "Choice: ";
        std::cin >> unitChoice;

        if (unitChoice == "b" || unitChoice == "B") return;
        if (unitChoice == "q" || unitChoice == "Q") { std::cout << "Exiting Calculator. GoodBye!\n"; exit(0); }

        bool useDegrees;
        if (unitChoice == "r" || unitChoice == "R") useDegrees = false;
        else if (unitChoice == "d" || unitChoice == "D") useDegrees = true;
        else { std::cout << "Invalid choice. Please enter r, d, b or q.\n"; continue; }

        while (true) {
            std::cout << "\nSelect operation:\n"
                      << "  1 - sin\n"
                      << "  2 - cos\n"
                      << "  3 - tan\n"
                      << "  4 - asin (inverse sine)\n"
                      << "  5 - acos (inverse cosine)\n"
                      << "  6 - atan (inverse tangent)\n"
                      << "  b - Back to previous menu\n"
                      << "  q - Quit\n"
                      << "Choice: ";
            std::cin >> input;

            if (input == "b" || input == "B") break; // go back to unit selection
            if (input == "q" || input == "Q") { std::cout << "Exiting Calculator. GoodBye!\n"; exit(0); }

            int op = 0;
            try {
                op = std::stoi(input);
            } catch (...) {
                std::cout << "Invalid selection. Please try again.\n";
                continue;
            }

            if (op >= 1 && op <= 3) {
                // Forward trig functions: need an angle
                std::cout << "Enter angle" << (useDegrees ? " (in degrees)" : " (in radians)")
                          << " or enter b to go back, q to quit: ";
                std::cin >> input;
                if (input == "b" || input == "B") continue;
                if (input == "q" || input == "Q") { std::cout << "Exiting Calculator. GoodBye!\n"; exit(0); }

                double angle;
                try { angle = std::stod(input); } catch (...) { std::cout << "Invalid angle input. Try again.\n"; continue; }
                double angleRad = useDegrees ? angle * PI / 180.0 : angle;

                double result = 0.0;
                if (op == 1) result = std::sin(angleRad);
                else if (op == 2) result = std::cos(angleRad);
                else result = std::tan(angleRad);

                std::cout << std::fixed << std::setprecision(8);
                std::cout << "Result: " << result << (useDegrees ? " (input in degrees)\n" : " (input in radians)\n");

            } else if (op >= 4 && op <= 6) {
                // Inverse trig functions: need a value
                std::cout << "Enter value for inverse function (e.g., -1 to 1 for asin/acos). Enter b to go back, q to quit: ";
                std::cin >> input;
                if (input == "b" || input == "B") continue;
                if (input == "q" || input == "Q") { std::cout << "Exiting Calculator. GoodBye!\n"; exit(0); }

                double value;
                try { value = std::stod(input); } catch (...) { std::cout << "Invalid numeric input. Try again.\n"; continue; }

                double angleRad = 0.0;
                if (op == 4) {
                    if (value < -1.0 || value > 1.0) { std::cout << "asin only accepts values in [-1,1].\n"; continue; }
                    angleRad = std::asin(value);
                } else if (op == 5) {
                    if (value < -1.0 || value > 1.0) { std::cout << "acos only accepts values in [-1,1].\n"; continue; }
                    angleRad = std::acos(value);
                } else {
                    angleRad = std::atan(value);
                }

                double outAngle = useDegrees ? angleRad * 180.0 / PI : angleRad;
                std::cout << std::fixed << std::setprecision(8);
                std::cout << "Result: " << outAngle << (useDegrees ? " degrees\n" : " radians\n");

            } else {
                std::cout << "Invalid selection. Please choose 1-6, b or q.\n";
            }
        }
    }

}


