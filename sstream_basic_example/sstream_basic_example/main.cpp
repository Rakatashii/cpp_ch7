//
//  main.cpp
//  sstream_basic_example
//
//  Created by Christian Meyer on 11/1/18.
//  Copyright © 2018 Christian Meyer. All rights reserved.
//

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <sstream>

using namespace std;

int main(int argc, const char * argv[]) {
    double salary = 2348999;
    int s_size = ceil(log10(salary));
    
    string s = to_string(salary);
    cout << "s = " << s << endl;
    
    ostringstream strs;
    strs << setprecision(s_size+1) << salary;
    string salary_str = strs.str();
    char* salary_chars = const_cast<char*>(salary_str.c_str());
    cout << "salary_str = " << salary_str << endl;
    cout << "salary_chars = " << salary_chars << endl;
    cout << "\n";
    
    ostringstream oss;
    oss << "100!" << 2498 << "true" << true << "\n" << "false" << false << '\0' << "\n";
    string oss_string = oss.str();
    cout << "oss_string = " << oss_string << endl;
    
    string values = "234 345 456 567 678";
    istringstream iss (values);
    for (int i = 0; i < 5; i++){
        int value;
        iss >> value;
        cout << "value" << i << " = " << value << endl;
    }
}
