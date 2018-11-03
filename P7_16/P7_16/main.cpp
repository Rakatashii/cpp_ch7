#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

typedef double (*a)(double);
typedef double (*b)(double);

using namespace std;

void print_table(vector<double> v, a f1, b f2);
double square(double x) { return x * x; };
double square_root(double x) { return sqrt(x); };

int main(int argc, const char * argv[]) {
    vector<double> nums = { 8.23, 9.34, 4.00, 3.00, 5.00, 10.2349 };
    print_table(nums, square, square_root);
    return 0;
}

void print_table(vector<double> v, a f1, b f2){
    cout << setprecision(4) << setfill(' ') << left << setw(7) << "x" << left << setw(7) << "f1(x)" << left << setw(7) << "f2(x)" << endl;
    for (int i = 0; i < v.size(); i++){
        cout << setprecision(4) << left << setw(7) << v[i] << left << setw(7) << f1(v[i]) << left << setw(7) << f2(v[i]) << endl;
    }
}
