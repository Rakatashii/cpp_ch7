/*
 Exercise P7.5. Write a function that computes the average value of an array of float- ing-point data:
 double average(double* a, int a_size)
 In the function, use a pointer variable, and not an integer index, to traverse the array elements.
*/

#include <iostream>

// Passing an array into a function to show that when an array is passed in to a function, it acts as a pointer.
// This is bc when an array is passed into a function, only the starting address is passed, which can then be incremented for successive elements
double average(double* a, int a_size);

int main(int argc, const char * argv[]) {
    double a[5] = {0.1, 2.3, 5.6, 9.1, 12.6};
    int a_size = 5;
    double a_avg = average(a, a_size);
    std::cout << "a_avg = " << a_avg << std::endl;
    
    double b[3] = {4.2, 6.9, 7.4};
    double b1 = *(b+0);
    double b2 = *(b+1);
    double b3 = *(b+2);
    std::cout << "b1 = " << b1 << std::endl;
    std::cout << "b2 = " << b2 << std::endl;
    std::cout << "b3 = " << b3 << std::endl;
    
    return 0;
}

double average(double* a, int a_size){
    double avg = 0.0;
    for (int i = 0; i < a_size; i++){
        avg += *(a+i);
    }
    return (avg / (double)a_size);
}


