#include <iostream>

using namespace std;

extern int func();
int num = 10; // defined as global - extern in other .cpp

int main(int argc, const char * argv[]) {
    num += 5; // changed in local
    int n = func();
    cout << "n = " << n << endl;
}
