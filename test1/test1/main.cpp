#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    string h = "hello";
    //h <<= ' '; // no viable overload;
    cout << "h = " << h << endl;
    int i = 0;
    i <<= 2;
    cout << "i = " << i << endl;
    
    string* hell = &h;
    cout << "hell = " << (*hell) << endl;
    
    string** hello = &hell;
    cout << "hello = " << hello << endl;
    cout << "(*hello) = " << (*hello) << endl;
    cout << "(**hello) = " << (**hello) << endl;
    
    return 0;
}
