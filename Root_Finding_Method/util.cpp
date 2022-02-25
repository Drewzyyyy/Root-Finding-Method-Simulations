#include <iostream>
#include <limits>
#include "util.h"

int chooseMethod(){
	int method = 0;

	std::cout << "\n\tChoose which method to use:\n";
	std::cout << "\t[1] Bisection Method\n";
	std::cout << "\t[2] Secant Method\n";
	std::cout << "\t[3] False Position Method\n";
	std::cout << "\t[0] Exit\n";
	std::cout << "\tChoice: ";

	while(1){
		method = getInput();
		if(method >= 0 || method <= 3){
			break;
		}
		std::cout << "Invalid input. Please try again.\n\n";
	}
	std::cout << "\n";
	return method;
}

/**
 * @brief Performs immediate type checking on input
 * 
 * @return The valid value needed by the user
 */
double getInput(){
	double val = 0.0;
	while(1){
		std::cin >> val;
		if(!std::cin.fail()){
			return val;
		}
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		std::cout << "Invalid input. Please try again.\n\n";	
	};
}

/**
 * @brief Checks if the user wants to accelerate the results via Aitken's method
 * 
 * @return true If the user wants to perform Aitken's method on the results 
 * @return false The user wants to exit to the main menu
 */
bool askAitken(){
	int doAitken = 0;

	std::cout << "\n\tAccelerate results using Aitken's method?\n";
	std::cout << "\t[1] Yes\n";
	std::cout << "\t[0] No\n";
	std::cout << "\tChoice: ";

	while(1){
		doAitken = getInput();
		if(doAitken == 0 || doAitken == 1){
			break;
		}
		std::cout << "Invalid input. Please try again.\n\n";
	}
	std::cout << "\n";
	return doAitken;
}

double getLeftEndPt(){
	std::cout << "\nPlease input the left endpoint: \n";
	return getInput();
}

double getRightEndPt(double leftEndPt){
	std::cout << "\nPlease input the right endpoint: \n";
	double rightEndPt = 0.0;
	while(1){
		rightEndPt = getInput();
		if(rightEndPt < leftEndPt){
			std::cout << "The right endpoint must be greater than the left endpoint.\n\n";
		} else if(leftEndPt == rightEndPt){
			std::cout << "The left and right endpoints must be different.\n\n";
		} else {
			break;
		}
	};
	return rightEndPt;
}

int getIterations(){
	std::cout << "\nPlease input the number of iterations: \n";
	int iterations = 0;
	while(1){
		iterations = getInput();
		if(iterations > 0) break;
		std::cout << "Please input a value greater than 0\n\n";
	};
	return iterations;
}

bool runProgram(){
	bool run = 0;
	while(1){
		run = getInput();
		if(run == 0 || run == 1){
			break;
		}
		std::cout << "Invalid input. Please try again.\n\n";	
	}
	return run;
}