/*
 Exercise P7.6.
 Write a function that returns a pointer to the maximum value of an array of floating-point data:
 double* maximum(double a[], int a_size) If a_size is 0, return NULL.
*/

#include <iostream>

using namespace std;

double* maximum(double a[], int a_size);

int main(int argc, const char * argv[]) {
    int a_size = 5;
    double* a = new double[a_size];
    *a = 5.9;
    
    // just making sure
    cout << "a[0] = " << *a << endl;
    cout << "a[0] = " << a[0] << endl;
    
    *(a+1) = 8.2;
    *(a+2) = 7.1;
    *(a+3) = 9.9;
    *(a+4) = 6.8;
    
    double* max = maximum(a, a_size);
    
    cout << "a_max = " << *max << endl;
    
    return 0;
}

double* maximum(double a[], int a_size){
    double* highest = a;
    if (a_size == 0){
        return NULL;
    }
    for (int i = 1; i < a_size; i++){
        if (*(a+i) > *highest){
            highest = (a+i);
        }
    }
    return highest;
}
