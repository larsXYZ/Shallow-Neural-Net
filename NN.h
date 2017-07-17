struct matrixObject;

struct NN{
	
	//Data
	int input_layer_number; //Number of input nodes
	int hidden_layer_number; //Number of hidden layer nodes
	int output_layer_number; //Number of output layer nodes

	matrixObject* I_H; //Input layer to hidden layer weigths
	matrixObject* H_O; //Hidden layer to output layer weigths
	
	//Constructor
	NN();
	NN(int il, int hl, int ol);

	//Working functions
	double* calculateHiddenValues(double* input); //Return vector of size hidden_layer_number of doubles, takes in vector of size input_layer_number, REMEMBER TO DELETE WHEN DONE
	double* calculateOutputValues(double* hidden); //Return result vector of size output_layer_number, takes in vector of size hidden_layer_number, REMEMBER TO DELETE WHEN DONE
	double activationFunc(double input); //I use sigmoid function
	double* predict(double* input); //Predicts result by using input vector of size input_layer_number, REMEMBER TO DELETE WHEN DONE
	//Destructor
	~NN();
};

