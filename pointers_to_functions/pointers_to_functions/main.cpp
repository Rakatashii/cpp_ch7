#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

typedef double (*funk)(double);

double square(double n);
void print_table(double (*f)(double), vector<double> v);
void print_table2(double (*f)(double), vector<double> v);

int main(int argc, const char * argv[]) {
    vector<double> nums1 = {1, 2, 3, 4, 5, 6};
    print_table(square, nums1);
    cout << "\n";
    
    vector<double> nums2 = {4, 5, 6, 7, 8};
    print_table(square, nums2);
    cout << "\n";

    return 0;
}

double square(double n){
    return n*n;
}
void print_table(double (*f)(double), vector<double> v){
    cout << "TABLE" << endl;
    cout << setw(5) << "x" << setw(5) << "f(x)" << endl;
    for (int i = 0; i < v.size(); i++){
        cout << setw(5) << v[i] << setw(5) << f(v[i]) << endl;
    }
}
void print_table2(funk f, vector<double> v){
    cout << "TABLE" << endl;
    cout << setw(5) << "x" << setw(5) << "f(x)" << endl;
    for (int i = 0; i < v.size(); i++){
        cout << setw(5) << v[i] << setw(5) << f(v[i]) << endl;
    }
}
