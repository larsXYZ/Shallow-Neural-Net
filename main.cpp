#include "matrix.h"
#include "NN.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <string>

/*	I USE XOR FUNCTION AS A TEST DATASET, THEREFORE I CAN CREATE MY OWN RANDOMIZED DATASET OF CHOSEN SIZE (VERY HANDY) */

struct XORdata {

	int* i_1 = nullptr;
	int* i_2 = nullptr;
	int* o_1 = nullptr;

	~XORdata() {
		delete i_1;
		delete i_2;
		delete o_1;
	}

};

void createXORdataset(int DATASET_SIZE) {

	//Creates file variables
	std::ofstream XOR_dataset;

	//Create text files
	XOR_dataset.open("XOR_DATASET.txt"); // Formatted line by line like this: i_1 i_2 o_1 /n 

	//Working variable
	int i_1;
	int i_2;
	int o_1;

	//Create dataset
	for (int i = 0; i < DATASET_SIZE; i++) {

		i_1 = rand() % 2;
		i_2 = rand() % 2;

		if ((i_1 && i_2) || (!i_1 && !i_2)) o_1 = 0;
		else o_1 = 1;

		XOR_dataset << i_1 << " " << i_2 << " " << o_1 << std::endl;
	}

	//Close files
	XOR_dataset.close();
	
}

XORdata* readXORdataset(int DATASET_SIZE) { //REMEMBER TO DELETE XORDATA POINTER WHEN DONE
	
	//Open file
	std::ifstream XOR_dataset;
	XOR_dataset.open("XOR_DATASET.txt");
	std::string inputString = "";
	
	//Create result
	XORdata* result = new XORdata;
	result->i_1 = new int[DATASET_SIZE];
	result->i_2 = new int[DATASET_SIZE];
	result->o_1 = new int[DATASET_SIZE];

	//Filling in data
	int line = 0;
	while (std::getline(XOR_dataset, inputString)) {
		
		result->i_1[line] = (inputString[0] == '1');
		result->i_2[line] = (inputString[2] == '1');
		result->o_1[line] = (inputString[4] == '1');
		line++;
	}

	return result;

}

int main(){
	
	//DATASET variables
	int datasetSIZE = 10000;

	//Neural net variables
	const int I = 2; //Input layer size
	const int H = 50; //Hidden layer size
	const int O = 1; //Output layer size

	//Seeds the random engine
	srand(time(NULL));

	//Create XOR datavector
	createXORdataset(datasetSIZE);

	//Read XOR datavector
	XORdata* XOR_data;
	XOR_data = readXORdataset(datasetSIZE);

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
	delete XOR_data;
	std::cout << std::endl;
	system("PAUSE");
}
