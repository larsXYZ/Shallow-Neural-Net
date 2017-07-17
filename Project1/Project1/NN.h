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

	//Destructor
	~NN();
};

