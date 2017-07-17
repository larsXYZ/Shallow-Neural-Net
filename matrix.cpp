#include "matrix.h"

#include <iostream>

matrix::matrix(int h1, int w1){
	
	//Sets size
	h = h1;
	w = w1;
	
	//Creates number matrix
	double** m = new double*[w];
	for (int i = 0; i < w; i++) m[i] = new double[h];

}

matrix::matrix(int h1, int w1, double k){
	
	//Sets size
	h = h1;
	w = w1;
	
	//Creates number matrix
	double** m = new double*[w];
	for (int i = 0; i < w; i++) m[i] = new double[h];
	
	//Initializes numbers
	for(int i = 0; i < w; i++){
		for (int q = 0; q < h; q++){
			m[i][q] = k;
		}
	}

}

void matrix::print(){

	for (int i = 0; i < w; i++){
		for (int q = 0; q < h; q++){
			std::cout << m[i][q] << " ";
		}
		std::cout << std::endl;
	}
}

matrix::~matrix(){
	
	for (int i = 0; i < w; i++) delete m[i];
	delete m;	
}
