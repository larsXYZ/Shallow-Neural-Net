#include "matrix.h"
#include "NN.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>


int main(){
	
	//Seeds the random engine
	srand(time(NULL));

	//Constants
	const int I = 10;
	const int H = 50;
	const int O = 1;

	//Create random inputVector
	double testInputs[I] = { 0 };
	for (int i = 0; i < I; i++) {
		testInputs[i] = rand() % 10;
		std::cout << testInputs[i] << "   ";
	}
	std::cout << std::endl;
	std::cout << std::endl;

	//Creates neural network
	NN NeuralNet(I, H, O);

	//Prints Input to hidden layer weights
	NeuralNet.I_H->print();
	std::cout << std::endl;

	//Calculate hidden layer values
	double* hiddenOutputs = NeuralNet.calculateHiddenValues(testInputs);

	//Print result
	for (int i = 0; i < H; i++) {
		std::cout << hiddenOutputs[i] << "   ";
	}
	std::cout << std::endl;
	std::cout << std::endl;

	//Prints hidden layer to output weights
	NeuralNet.H_O->print();
	std::cout << std::endl;
	std::cout << std::endl;

	//Calculate output layer values
	double* outputs = NeuralNet.calculateOutputValues(hiddenOutputs);

	//Print output
	for (int i = 0; i < O; i++) {
		std::cout << outputs[i] << "   ";
	}


	delete hiddenOutputs;
	delete outputs;
	std::cout << std::endl;
	system("PAUSE");
}
