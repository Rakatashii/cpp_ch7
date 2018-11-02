/*
 Exercise P7.7. Write a function that reverses the values of an array of floating-point data:
 void reverse(double a[], int a_size)
 In the function, use two pointer variables, and not integer indexes, to traverse the array elements.
*/

#include <iostream>

using namespace std;

void reverse(double a[], int a_size);

int main(int argc, const char * argv[]) {
    int a_size = 5;
    double a[5] = {2.2, 3.3, 4.4, 7.9, 1.3};
    
    reverse(a, a_size);
    
    cout << "a_size = " << a_size << endl;
    for (int i = 0; i < a_size; i++){
        cout << "a[" << i << "] = " << a[i] << endl;
    }
    cout << "\n";
    
    int b_size = 6;
    double b[6] = {8.2, 5.3, 1.4, 7.9, 0.3, 6.4};
    
    reverse(b, b_size);
    
    cout << "b_size = " << b_size << endl;
    for (int i = 0; i < b_size; i++){
        cout << "b[" << i << "] = " << b[i] << endl;
    }
    cout << "\n";
    
    return 0;
}

void reverse(double a[], int a_size){
    double* start = &*(a);
    double* end = &*(a+(a_size-1));
    double* reverse = new double[a_size];
    int stop = (a_size/2)+1;
    if (a_size % 2 == 1){
        for (int i = 0; i < stop; i++){
            if (i == stop-1){
                *(reverse+i) = *(start+i);
            } else {
                *(reverse+i) = *(end-i);
                *(reverse+((a_size-1)-i)) = *(start+i);
            }
        }
    }
    if (a_size % 2 == 0){
        --stop;
        for (int i = 0; i < stop; i++){
            *(reverse+i) = *(end-i);
            *(reverse+((a_size-1)-i)) = *(start+i);
        }
    }
    for (int i = 0; i < a_size; i++){
        *(a+i) = *(reverse+i);
        //cout << "reverse[" << i << "] = " << reverse[i] << endl;
    }
    start = NULL; end = NULL; // kept this after the program failed when trying to delete them.
    // Does this do anything AT ALL? or, since these variables are local, does the scope simply take care of them?
}
