#include "matrix.h"
#include "NN.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>



int main(){
	
	//Seeds the random engine
	srand(time(NULL));

	//Creates a matrix object
	matrixObject A(10,10, 0);
	A.randomize(-1, 1);

	A.print();

	system("PAUSE");
}
