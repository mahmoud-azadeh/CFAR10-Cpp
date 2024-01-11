
#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <ctime>
#include <cstdint>

// $ g++ cfar10.cpp -o cfar10
// $ ./cfar10

// reference: https://cs231n.github.io/classification/

#include "dataset.h"
#include "file.h"

int main()
{
    unsigned int num_train = 5000;  // number of train samples
	unsigned int num_test  = 1000;  // number of test samples
	unsigned int num_val   = 1000;  // number of validation samples
	
	std::cout << "\nloading datasets ...";

	std::string dir = "./cifar-10-binary/"; // the folder path of the datasets
	uiuc::cfar cfar10(dir, num_train, num_test, num_val);

	std::cout << "\n-------------"<< std::endl;
	std::cout << "train samples:" << cfar10.train_dataset.cardinality <<std::endl;	
	std::cout << "test samples:" << cfar10.test_dataset.cardinality <<std::endl;
	std::cout << "validation samples:" << cfar10.val_dataset.cardinality <<std::endl;

	
	// write the datasets into files to check and plot in Python [optional]
	file <uint8_t, uint8_t> cfile;	
	cfile.write_binary(cfar10.train_dataset.X, "./X_train.bin");
	cfile.write_binary(cfar10.train_dataset.y, "./y_train.bin");	

	//cfile.write_binary(cfar10.val_dataset.X, "./X_val.bin");
	//cfile.write_binary(cfar10.val_dataset.y, "./y_val.bin");

	//cfile.write_binary(cfar10.test_dataset.X, "./X_test.bin");
	//cfile.write_binary(cfar10.test_dataset.y, "./y_test.bin");

	

	return 0;
}