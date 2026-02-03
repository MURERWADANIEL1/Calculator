#include "basicmath.h"
#include <iostream>
#include <limits>

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
        
        bool calculation_error=false;
        while (true){
            std::cout<<"Enter next number or '=' to finish\n";

            if (std::cin>>nextNum){ 
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
                    break;
                }
            } else {
                std::cin.clear();
                char endChar;
                std::cin>>endChar;

                if (endChar=='='){
                    break;
                } else{
                    std::cout<<"Invalid Input. Please enter a number or '='."<<std::endl;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            }
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (!calculation_error){
            std::cout<<"Final Result: "<<result<<std::endl;
        }
    }
}
