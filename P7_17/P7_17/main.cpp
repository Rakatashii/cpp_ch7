/*
 Exercise P7.17. Implement a function
 void fill_with_values(int[] a, int size, IntFunPointer f)
 that sets the ith element of the array to f(i). Here IntFunPointer is a typedef for a pointer to a function that consumes an int and yields an int. Provide a main func- tion in which you call the fill_with_values function so that an array of ten integers is filled with 1, 4, 9, 16, 25, ..., 100.
 */

#include <iostream>

#define ARR_SIZE 5
typedef int (*FunPointer)(int);

using namespace std;

void fill_with_values(int a[], int size, FunPointer f);

int square(int n){return n*n;};

int main(int argc, const char * argv[]) {
    int c[ARR_SIZE];
    c[0] = 4;
    c[1] = 6;
    c[2] = 8;
    c[3] = 10;
    c[4] = 12;
    fill_with_values(c, ARR_SIZE, square);
    
    for (int i = 0; i < ARR_SIZE; i++){
        cout << "c[" << i << "] = " << c[i] << endl;
    }
    
    return 0;
}

void fill_with_values(int a[], int size, FunPointer f){
    for (int i = 0; i < size; i++){
        *(a+i) = f(*(a+i));
    }
}
