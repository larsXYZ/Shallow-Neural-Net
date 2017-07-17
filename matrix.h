
struct matrix{

	int h;
	int w;
	
	double** m;

	//Constructors
	matrix(int h1, int w1);
	matrix(int h1, int w1, double k);
	
	//Utility
	void print();

	//Destructor
	~matrix();
	
};
