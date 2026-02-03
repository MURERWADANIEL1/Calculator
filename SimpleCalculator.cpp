#include <iostream>
#include <limits>
#include <cmath>
#include <string>
#include <map>
#include <functional>


void displayWelcomeMessage(){
    std::cout << " ******** C++ Basic Calculator ******" <<std::endl;
}

void displayMainMenu();

// Module interfaces
#include "modules/basicmath.h"
#include "modules/trigonometry.h"
#include "modules/logarithms.h"
#include "modules/vectors.h"
#include "modules/matrices.h"
#include "modules/complexnumbers.h"
#include "modules/booleanalgebra.h"
#include "modules/integrals.h"
#include "modules/derivatives.h"
#include "modules/numericalmethods.h"

int main(){
    std::string choice;

    displayWelcomeMessage();

    std::map<std::string, std::function<void()>> menu = {
        {"1", performBasicMath},
        {"2", performTrigonometry},
        {"3", performLogarithms},
        {"4", performVectors},
        {"5", performMatrices},
        {"6", performComplexNumbers},
        {"7", performBooleanAlgebra},
        {"8", performIntegrals},
        {"9", performDerivatives},
        {"10", performNumericalMethods}
    };

    while (true){
        displayMainMenu();
        std::cin >> choice;

        if (std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            choice.clear();
        }

        if (choice == "q" || choice == "Q"){
            std::cout << "Exiting Calculator. GoodBye!" << std::endl;
            return 0;
        }

        auto it = menu.find(choice);
        if (it != menu.end()){
            it->second();
        } else {
            std::cout << "\n Invalid choice. Please select an Option from the menu" << std::endl;
        }
    }

    return 0;
}

void displayMainMenu(){
    std::cout<<"\n ----- Calculator Main Menu -----"<<std::endl;
    std::cout<<"1. Basic Arithmetic (+, -, *, /)"<<std::endl;
    std::cout<<"2. Trigonometry"<<std::endl;
    std::cout<<"3. Logarithms"<<std::endl;
    std::cout<<"4. Vectors"<<std::endl;
    std::cout<<"5. Matrices"<<std::endl;
    std::cout<<"6. Complex Numbers"<<std::endl;
    std::cout<<"7. Boolean Algebra"<<std::endl;
    std::cout<<"8. Integrals"<<std::endl;
    std::cout<<"9. Derivatives"<<std::endl;
    std::cout<<"10. Numerical Methods\n"<<std::endl;

    std::cout<<"'q' to Quit"<<std::endl;
    std::cout<<"Enter your choice: \n";
}

    
