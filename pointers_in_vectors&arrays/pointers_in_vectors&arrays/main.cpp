#include <iostream>
#include <vector>
#include "test.hpp"

using namespace std;

double d_max(double* a, int size);
int d_max_index(double* a, int size);
double d_min(double* a, int size);
int d_min_index(double* a, int size);

int main(int argc, const char * argv[]) {
    const int a_size = 10;
    int a[a_size]; // So a is initialized as an array, not a pointer.
    // Yet can still inspect elements of a using *(a+i) syntax.
    int i;
    
    for (i = 0; i < a_size; i++){
        *(a+i) = i;
    }
    
    for (i = 0; i < a_size; i++){
        cout << "*(a+" << i << ") = " << *(a+i) << endl;
    }
    cout << "\n";
    
    const int b_size = 10;
    double b[b_size]; // So a is initialized as an array, not a pointer.
    // Yet can still inspect elements of a using *(a+i) syntax.
    
    for (i = 0; i < b_size-2; i++){
        *(b+i) = (i*6.9);
    }
    *(b+(b_size-2)) = 3.45;
    *(b+(b_size-1)) = 6.298;
    *b = 23.234;
    
    for (i = 0; i < b_size; i++){
        cout << "*(b+" << i << ") = " << *(b+i) << endl;
    }
    cout << "\n";
    
    double b_max = d_max(b, b_size);
    cout << "b_max = " << b_max << endl;
    int b_max_index = d_max_index(b, b_size);
    cout << "b_max_index = " << b_max_index << endl;
    cout << "\n";
    
    double b_min = d_min(b, b_size);
    cout << "b_min = " << b_min << endl;
    int b_min_index = d_min_index(b, b_size);
    cout << "b_min_index = " << b_min_index << endl;
    cout << "\n";
    
    return 0;
}

double d_max(double* a, int size){
    double max = *a;
    int i;
    for (i = 1; i < size; i++){
        if (*(a+i) > max){
            max = *(a+i);
        }
    }
    return max;
}
int d_max_index(double* a, int size){
    double max = *a;
    int max_index = 0;
    int i;
    for (i = 1; i < size; i++){
        if (*(a+i) > max){
            max = *(a+i);
            max_index = i;
        }
    }
    return max_index;
}
double d_min(double* a, int size){
    double min = *a;
    int i;
    for (i = 1; i < size; i++){
        if (*(a+i) < min){
            min = *(a+i);
        }
    }
    return min;
}
int d_min_index(double* a, int size){
    double min = *a;
    int min_index = 0;
    int i;
    for (i = 1; i < size; i++){
        if (*(a+i) < min){
            min = *(a+i);
            min_index = i;
        }
    }
    return min;
}
