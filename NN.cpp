#include "NN.h"
#include "matrix.h"
#include <cmath>



NN::NN(){

	input_layer_number = 0;
	hidden_layer_number = 0;
	output_layer_number = 0;

	I_H = nullptr;
	H_O = nullptr;

}

NN::NN(int il, int hl, int ol){

	input_layer_number = il;
	hidden_layer_number = hl;
	output_layer_number = ol;

	I_H = new matrixObject(input_layer_number, hidden_layer_number, 0);
	H_O = new matrixObject(hidden_layer_number, output_layer_number, 0);

	I_H->randomize(-1, 1);
	H_O->randomize(-1, 1);

}

double* NN::calculateHiddenValues(double* input)
{
	double* result = new double[hidden_layer_number]; //Creates memory for result vector
	
	for (int i = 0; i < hidden_layer_number; i++) { //Calculates output from perceptron

		double inputStrength = 0;

		for (int q = 0; q < input_layer_number; q++) {

			inputStrength += input[q] * I_H->matrix[i][q];
		}

		result[i] = activationFunc(inputStrength); //Applies activation function (sigmoid function)
	}

	return result; //Returns result , lol
}

double* NN::calculateOutputValues(double * hidden)
{
	double* result = new double[output_layer_number]; //Creates memory for result vector

	for (int i = 0; i < output_layer_number; i++) { //Calculates output from perceptron

		double inputStrength = 0;

		for (int q = 0; q < hidden_layer_number; q++) {

			inputStrength += hidden[q] * H_O->matrix[i][q];
		}

		result[i] = activationFunc(inputStrength); //Applies activation function (sigmoid function)
	}

	return result; //Returns result , lol
}

double NN::activationFunc(double input)
{
	return 1/(1+pow(2.71828182846,(-input)));
}

double* NN::predict(double * input)
{
	double* hiddenLayerVal = calculateHiddenValues(input);
	double* output = calculateOutputValues(hiddenLayerVal);

	delete hiddenLayerVal;
	return output;
}


NN::~NN(){

	delete I_H;
	delete H_O;
}
