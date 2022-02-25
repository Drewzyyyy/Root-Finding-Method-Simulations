/**
 * @file RFM-Secant_Method.cpp
 * @author Hermo, Andrew Louis
 * @brief Performs the Root Finding Method using the Secant Method on the static function (x^2 - 1)
 * @version 1.0
 * @date 2022-02-26
 * 
 * @copyright Copyright (c) 2022
 */

#include <iostream>
#include <limits>

double getInput(); // Performs immediate type checking on input
double getLeftEndPt();
double getRightEndPt(double leftEndPt);
int getIterations();
bool runProgram(); // Checks if the user wants to re-run the program

/**
 * @brief The default static function used in the simulation
 * 
 * @param x The value of the variable x in the equation
 * @return The result of the equation on plugging in input
 */
double f(double x){
	return (x*x)-1;
}

int main(){
	double zero = 0;
	double leftEndPt = 0.0, leftSecant = 0.0;
	double rightEndPt = 0.0, rightSecant = 0.0;
	int iterations = 0;

	while(1){
		std::cout << "Root Finding Method Simulation" << std::endl;
		leftEndPt = getLeftEndPt();
		rightEndPt = getRightEndPt(leftEndPt);
		iterations = getIterations();

		for(int i = 0; i < iterations; i++){
			leftSecant = f(leftEndPt);
			rightSecant = f(rightEndPt);
			zero = rightEndPt - (rightSecant * (rightEndPt - leftEndPt)) / (rightSecant - leftSecant);
			std::cout << "\nIteration : " << i << "\t|\tApprox : " << zero << "\n";

			leftEndPt = rightEndPt;
			rightEndPt = zero;
			std::cout << "New interval is [ " << leftEndPt << "," << rightEndPt << " ]" << "\n";
		}

		std::cout << "\n\tRun program again?\n";
		std::cout << "\t[1] Yes\n";
		std::cout << "\t[0] No\n";
		std::cout << "\tChoice: ";
		if(runProgram()){
			std::system("cls");
		}else {
			std::cout<<"\nThank you!\n";
			break;
		}
	}
}

/**
 * @brief Performs immediate type checking on input
 * 
 * @return The valid value needed by the user
 */
double getInput(){
	double val = 0.0;
	do{
		std::cin >> val;
		if(!std::cin.fail()){
			return val;
		}
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		std::cout << "Invalid input. Please try again.\n\n";	
	}while(1);
}

double getLeftEndPt(){
	std::cout << "Please input the left endpoint: \n";
	return getInput();
}

double getRightEndPt(double leftEndPt){
	std::cout << "Please input the right endpoint: \n";
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
	std::cout << "Please input the number of iterations: \n";
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