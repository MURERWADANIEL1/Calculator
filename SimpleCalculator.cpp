//basic calculator to add and subtract two numbers
#include<iostream>
//using namespace std;
#include <limits>  
#include <cmath>


void displayWelcomeMessage(){
    std::cout << " ******** C++ Basic Calculator ******" <<std::endl;
}
void displayMainMenu();
void performBasicMath();
void performTrigonometry();
void performLogarithms();

int main(){  
    char choice;

    displayWelcomeMessage();

    while (true){
        displayMainMenu();
        std::cin>>choice;

        if (std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            choice = ' '; //force defult case for invalid input
        }
        switch (choice){
            case '1':
            performBasicMath();
            break;

            case '2':
            performTrigonometry();
            break;

            case '3':
            performLogarithms();
            break;

            case 'q':
            case 'Q':
                std::cout<<"Exiting Calculator. GoodBye!"<<std::endl;
                return 0;
            default:
                std::cout<< "\n Invalid choice. Please select an Option from the menu"<<std::endl;
                if (choice != '\n'){
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                }
                break;
        }
    }
    return 0;
}

void displayMainMenu(){
    std::cout<<"\n ----- Calculator Main Menu -----"<<std::endl;
    std::cout<<"1. Basic Arithmetic (+, -, *, /)"<<std::endl;
    std::cout<<"2. Trigonometry"<<std::endl;
    std::cout<<"3. Logarithms"<<std::endl;
    std::cout<<"'q' to Quit"<<std::endl;
    std::cout<<"Enter your choice: ";
}
void performBasicMath(){
    char operation;
    double result,nextNum;

    std::cout << "\n ******** Basic Arithmetic ******" <<std::endl;
    std::cout << "1. Enter an Operator (+, -, *, /)" << std::endl;
    std::cout<<"2. Enter First Number"<<std::endl;
    std::cout<<"3. Enter subsequent numbers or number one by one"<<std::endl;
    std::cout<<"4. Enter '=' when you are done to see the result\n"<<std::endl;
    std::cout <<"5. Enter 'b' as the operator to go back to the main menu "<<std::endl;
    std::cout <<"6. Enter 'q' as the operator to quit the calculator "<<std::endl;

    //Loop for REPL(Read-Eval-Print Loop)
    while (true){
        std::cout<<"\nEnter operation (+, -, *, /) or command (b, q): ";
        std::cin>>operation;

        if (operation=='b' || operation=='B'){
            return;
        }else if (operation=='q' || operation=='Q'){
            std::cout<<"Exiting Calculator. GoodBye!"<<std::endl;
            exit(0);
        }
        if (operation != '+' && operation !='-' && operation !='/' && operation !='*'){
            std::cout<<"Invalid Operator, please try again"<<std::endl;

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue; 
        }
        std::cout<<"Enter First Number"<<std::endl;
        if (!(std::cin>>result)){
            std::cout<<"Invalid Input. Calculation aborted."<<std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        /*std::cin>>num1;
        std::cout<<"Enter Subsequent Number or Numbers"<<std::endl;
        std::cin>>num2;
        
        if (std::cin.fail()){
            std::cout<<"Invalid Input. Please enter numbers values only."<<std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
            
        }*/
       //double result =0.0;
        bool calculation_error=false;
        while (true){
            std::cout<<"Enter next number or '=' to finish\n";

            // Try to read a number
            if (std::cin>>nextNum){ 
                // It's a number, perform the operation
                switch (operation){
                    case '+':
                        result +=nextNum;
                        break;
                    case '-':
                        result -=nextNum;
                        break;
                    case '*':
                        result*=nextNum;
                        break;
                    case '/':
                        if (nextNum==0){
                            std::cout <<"Error! Division by zero. Calculation aborted."<<std::endl;
                            calculation_error=true;
                        }else {
                            result/=nextNum;
                        }
                        break;
                }
                if (calculation_error){
                    break; // Exit the inner loop on error
                }
            } else {
                // It's not a number, check if it's the '=' character
                std::cin.clear(); // Clear the error state from the failed read
                char endChar;
                std::cin>>endChar;

                if (endChar=='='){
                    break; // User is done, break the inner loop to print the result
                } else{
                    std::cout<<"Invalid Input. Please enter a number or '='."<<std::endl;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            }
        }
        // Clear the rest of the line to prevent issues on the next outer loop iteration
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (!calculation_error){
            std::cout<<"Final Result: "<<result<<std::endl;
        }
    }
}
void performTrigonometry(){
    std::cout<<" Trigonometry function is under development. Coming Soon!"<<std::endl;
}
void performLogarithms(){
    std::cout<<" Logarithm function is under development. Coming Soon!"<<std::endl;
}
    
