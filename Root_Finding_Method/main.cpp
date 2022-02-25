/**
 * @file main.cpp
 * @author Hermo, Andrew Louis
 * @brief Performs the Root Finding Method using the Secant Method and Bisection Method, along with accelerating the results with Aitken's Method
 * @version 1.0
 * @date 2022-02-26
 * 
 * @copyright Copyright (c) 2022
 */

#include <iostream>
#include "util.h"
#include "calculations.h"

int main(){
	int choice = 0;

	while(1){
		std::cout << "\t---Root Finding Method using Bisection Method Simulation---\n" << std::endl;
		choice = chooseMethod();
		if(!choice){
			std::cout << "\nThank you!\n";
			break;
		} else if(choice == 1){
			doRootFinding(&doBisection);
		} else if(choice == 2){
			doRootFinding(&doSecant);
		} else if(choice == 3){
			doRootFinding(&doFalsePos);
		}

		std::cout << "\n\tRun program again?\n";
		std::cout << "\t[1] Yes\n";
		std::cout << "\t[0] No\n";
		std::cout << "\tChoice: ";
		if(runProgram()){
			std::system("cls");
		}else {
			std::cout << "\nThank you!\n";
			break;
		}
	}
}