#include <iostream>
#include <vector>
using namespace std;

void print_array(const int *const array, const int &size);
int *apply_all(const int *array_one, const int &size_one, const int *array_two, const int &size_two);

int main(){
    // write two functions
    // write a c++ function named apply all,
    // expects two arrays, allocates a new array
    // of integers whose size is size 1 * size 2
    // loops through the second array, and multiplies each element
    // across each element of array 1 and stores the product
    // in the newly created array
    // function should return a pointer to the 
    // newly allocated array
    // also write a print function that displays all elements in an array
    int array1[] {1, 2, 3, 4, 5};
    int array2[] {10, 20, 30};
    print_array(array1, 5);
    print_array(array2, 3);
    int *new_arr_ptr {apply_all(array1, 5, array2, 3)};
    print_array(new_arr_ptr, 15);
    delete [] new_arr_ptr;
	return 0;
}

void print_array(const int *const array, const int &size){
    cout << "[ ";
    for (int i {0}; i < size; i++){
        cout << *(array+i) << " ";
    }
    cout << "]\n";
}

int *apply_all(const int *array_one, const int &size_one, const int *array_two, const int &size_two){
    int *new_arr = new int [size_one * size_two] {}; // HAVE to initialise variables to new within functions
    int counter {0};
    for (int i {0}; i < size_two; i++){
        for (int j {0}; j < size_one; j++){
            *(new_arr + counter) = *(array_one + j) * *(array_two + i);
            counter += 1;
        }
    }
    return new_arr;
}