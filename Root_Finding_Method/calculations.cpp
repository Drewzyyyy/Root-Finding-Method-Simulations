#include <iostream>
#include <iomanip>
#include "util.h"
#include "calculations.h"

#define colWidth 20

/**
 * @brief The default static function used in the simulation
 * 
 * @param x The value of the variable x in the equation
 * @return The result of the equation on plugging in input
 */
double f(double x){
	return (x*x)-1;
}

/**
 * @brief Performs Bisection method using the left and right endpoints, within the set iterations
 * 
 * @param iterations The number of times bisection method is performed
 * @param leftEndPt The left endpoint of the interval
 * @param rightEndPt The right endpoint of the interval
 * @return double* Returns the array of results, incase the user wants to perform Aitken's Method
 */
double* doBisection(int iterations, double leftEndPt, double rightEndPt){
	double midpoint = 0.0, fMidpoint = 0.0;
	double* result = new double[iterations];
	std::cout << std::setw(colWidth) << "Iteration" << std::setw(colWidth) << "Approx" << std::setw(colWidth) << "Interval\n";
	for(int i = 0; i < iterations; i++){
		midpoint = (leftEndPt + rightEndPt) / 2;
		result[i] = midpoint;
		fMidpoint = f(midpoint);

		if(fMidpoint * f(leftEndPt) > 0){
			leftEndPt = midpoint;
		}else {
			rightEndPt = midpoint;
		}
		std::cout << std::setw(colWidth) << i << std::setw(colWidth) << midpoint << std::setw(colWidth-8) << "[" << leftEndPt << ", " << rightEndPt << "]\n";
		if(fMidpoint == 0 || !(rightEndPt - leftEndPt)) break;
	}
	return result;
}

/**
 * @brief Performs Secant method using the left and right endpoints, within the set iterations
 * 
 * @param iterations The number of times secant method is performed
 * @param leftEndPt The left endpoint of the interval
 * @param rightEndPt The right endpoint of the interval
 * @return double* Returns the array of results, incase the user wants to perform Aitken's Method
 */
double* doSecant(int iterations, double leftEndPt, double rightEndPt){
	double zero = 0.0, leftSecant = 0.0, rightSecant = 0.0, denominator = 0.0;
	double* result = new double[iterations];
	std::cout << "\n";
	std::cout << std::setw(colWidth) << "Iteration" << std::setw(colWidth) << "Approx" << std::setw(colWidth) << "Interval\n";
	for(int i = 0; i < iterations; i++){
		leftSecant = f(leftEndPt);
		rightSecant = f(rightEndPt);
		if((rightSecant - leftSecant) == 0){
			std::cout << "\tDivision by zero error. Exiting...\n";
			return result; 
		}
		zero = rightEndPt - (rightSecant * (rightEndPt - leftEndPt)) / (rightSecant - leftSecant);
		result[i] = zero;

		leftEndPt = rightEndPt;
		rightEndPt = zero;
		std::cout << std::setw(colWidth) << i << std::setw(colWidth) << zero << std::setw(colWidth-8) << "[" << leftEndPt << ", " << rightEndPt << "]\n";
	}
	return result;
}

/**
 * @brief Performs False Position method using the left and right endpoints, within the set iterations
 * 
 * @param iterations The number of times secant method is performed
 * @param leftEndPt The left endpoint of the interval
 * @param rightEndPt The right endpoint of the interval
 * @return double* Returns the array of results, incase the user wants to perform Aitken's Method
 */
double* doFalsePos(int iterations, double leftEndPt, double rightEndPt){
	double zero = 0.0, leftSecant = 0.0, rightSecant = 0.0, denominator = 0.0;
	double* result = new double[iterations];
	std::cout << "\n";
	std::cout << std::setw(colWidth) << "Iteration" << std::setw(colWidth) << "Approx" << std::setw(colWidth) << "Interval\n";
	for(int i = 0; i < iterations; i++){
		leftSecant = f(leftEndPt);
		rightSecant = f(rightEndPt);
		if((rightSecant - leftSecant) == 0){
			std::cout << "\tDivision by zero error. Exiting...\n";
			return result; 
		}
		zero = leftEndPt - (leftSecant * (rightEndPt - leftEndPt)) / (rightSecant - leftSecant);
		result[i] = zero;

		if(f(zero) * leftSecant < 0){
			rightEndPt = zero;
		}else {
			leftEndPt = zero;
		}
		std::cout << std::setw(colWidth) << i << std::setw(colWidth) << zero << std::setw(colWidth-8) << "[" << leftEndPt << ", " << rightEndPt << "]\n";
	}
	return result;
}

/**
 * @brief Performs Root Finding Method depending on the method used
 * 
 * @param method The specific method the user wants to perform
 */
void doRootFinding(double* (*method)(int iterations, double leftEndPt, double rightEndPt)){
	double pHat = 0.0, numerator = 0.0, denominator = 0.0;
	double leftEndPt = 0.0;
	double rightEndPt = 0.0;
	int iterations = 0;

	leftEndPt = getLeftEndPt();
	rightEndPt = getRightEndPt(leftEndPt);
	iterations = getIterations();

	double* result = method(iterations, leftEndPt, rightEndPt);
	if(iterations < 3 || !askAitken() || !result[0]){
		return;
	}

	std::cout << std::setw(colWidth) << "Iteration" << std::setw(colWidth) << "pHat\n";
	for(int i = 0; (i+2) < iterations; i++){
		numerator = result[i+1] - result[i];
		numerator *= numerator;
		denominator = ((-2 * result[i+1]) + result[i+2] + result[i]);
		pHat = result[i] - (numerator / denominator);
		std::cout << std::setw(colWidth) << i << std::setw(colWidth) << pHat << "\n";
	}
	delete[] result;
}