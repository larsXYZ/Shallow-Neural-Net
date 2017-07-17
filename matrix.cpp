#include "matrix.h"

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <cmath>
#include <string>

matrixObject::matrixObject() {

	//Sets size
	height = 0;
	width = 0;

	//Creates number matrix
	matrix = NULL;

}

matrixObject::matrixObject(int h1, int w1){
	
	//Sets size
	height = h1;
	width = w1;
	
	//Creates number matrix
	matrix = new double*[width];
	for (int i = 0; i < width; i++) matrix[i] = new double[height];

}

matrixObject::matrixObject(int h1, int w1, double k){
	
	//Sets size
	height = h1;
	width = w1;

	//Creates number matrix
	matrix = new double*[width];
	for (int i = 0; i < width; i++) matrix[i] = new double[height];

	//Initializes numbers
	for(int i = 0; i < width; i++){
		for (int q = 0; q < height; q++){
			matrix[i][q] = k;
		}
	}

}

void matrixObject::print(){

	std::cout.precision(3); //Sets print precision

	for (int i = 0; i <width; i++){
		for (int q = 0; q < height; q++){

			//Needed working variables
			double val = matrix[i][q];
			double abs_val = std::abs(matrix[i][q]);
			std::string seperator = "    ";

			//Corrects for signed numbers
			std::string sign_corr;
			if (val < 0) sign_corr = "";
			else sign_corr = " ";

			//Adjusts seperator size
			while (abs_val > 1) {

				abs_val = abs_val / 10;
				seperator.pop_back();
				if (seperator.length() <= 1) break;
			}

			//Prints
			std::cout << std::fixed << sign_corr << matrix[i][q] << seperator;
		}

		//Changes line
		std::cout << std::endl;
	}
}

void matrixObject::randomize(double MIN_val_rand, double MAX_val_rand)
{
	
	for (int i = 0; i < width; i++) {
		for (int q = 0; q < height; q++) {
			
			double VAR_part = ((double)rand() / RAND_MAX)*(MAX_val_rand - MIN_val_rand);
			matrix[i][q] = VAR_part + MIN_val_rand;
		}
	}
}

matrixObject::~matrixObject(){
	
	for (int i = 0; i < width; i++) delete[] matrix[i];
	delete[] matrix;
}
