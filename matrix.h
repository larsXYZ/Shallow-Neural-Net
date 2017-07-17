
struct matrixObject{

	//Data
	int height;
	int width;
	double** matrix;

	//Constructors
	matrixObject();
	matrixObject(int h1, int w1);
	matrixObject(int h1, int w1, double k);
	
	//Utility
	void print(); //Prints the matrix in a naive way, *now an incredibly smart way
	void randomize(double MIN_val_rand, double MAX_val_rand); //Randomizes the element

	//Destructor
	~matrixObject();
	
};
