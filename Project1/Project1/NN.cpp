#include "NN.h"
#include "matrix.h"



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

	I_H = new matrixObject(input_layer_number, output_layer_number, 0);
	H_O = new matrixObject(hidden_layer_number, output_layer_number, 0);

	I_H->randomize(-1, 1);
	H_O->randomize(-1, 1);

}


NN::~NN(){



}
