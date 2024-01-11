### CFAR10 in C++

The `cfar10.cpp` file is a simple C++ program that reads the CFAR10 binary files, which are available at here (https://www.cs.toronto.edu/~kriz/cifar.html).

-----
To compile and run the C++ code in Linux:
```bash
$ g++ cfar10.cpp -o cfar10
$ ./cfar10
```
-----
You have the flexibility to adjust the number of samples for the train, test, and validation datasets. However, the total number of samples in the train and validation datasets combined cannot exceed 50,000, and the maximum number of samples in the test dataset is 10,000.
```Cpp
unsigned int num_train = 5000;  // number of train samples
unsigned int num_test  = 1000;  // number of test samples
unsigned int num_val   = 1000;  // number of validation samples
 ```
 -----
 The object `cfa10` is an instance of the class `cfar`, it is assumed that the CFAR10 binary files are saved at the folder `"./cifar-10-binary/"`.
 The `cfar` class reads the binary files and creates three datasets: train, validation, and test. 
Each dataset contains three variables: `X`, `y`, and `cardinality`. These variables correspond to features, labels, and the length of the dataset, respectively.
```Cpp
std::string dir = "./cifar-10-binary/"; // the folder path for CAFAR10 files
uiuc::cfar cfar10(dir, num_train, num_test, num_val);
```
-----
To check the length of the read datasets:
```cpp
std::cout << "train samples:" << cfar10.train_dataset.cardinality <<std::endl;	
std::cout << "test samples:" << cfar10.test_dataset.cardinality <<std::endl;
std::cout << "validation samples:" << cfar10.val_dataset.cardinality <<std::endl;
```
Also, the dataset can be saved and shown in Python to check if the datasets are read correctly:
```cpp
file <uint8_t, uint8_t> cfile;	
cfile.write_binary(cfar10.train_dataset.X, "./X_train.bin");
cfile.write_binary(cfar10.train_dataset.y, "./y_train.bin");
```
then run the Python file `cfar10.py` to show images.
