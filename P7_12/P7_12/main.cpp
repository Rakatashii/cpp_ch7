/*
 Exercise P7.12. Add a member function
 void Employee::format(char buffer[], int buffer_maxlength)
 to the Employee class. The member function should fill the buffer with the name and salary of the employee. Be sure not to overrun the buffer. It can hold buffer_maxlength characters, not counting the '\0' terminator. (That is, the buffer has buffer_maxlength + 1 bytes available.) Be sure to provide a '\0' terminator.
 */

#include <iostream>
#include "ccc_empl.h"
#include <cmath>
#include <sstream>
#include <iomanip>

int main(int argc, const char * argv[]) {
    string name = "Jack Spade";
    double salary = 2348999;
    Employee e = Employee(name, salary);
    
    char* name_chars = e.name_char_array();
    char* salary_chars = e.salary_char_array();
    cout << "name_chars (in main): " << name_chars << endl;
    cout << "salary_chars (in main): " << salary_chars << endl;
    
    int name_size = strlen(name_chars);
    int salary_size = strlen(salary_chars);
    
    int buffer_size = name_size+salary_size+1;
    
    char s1[buffer_size];
    e.format(s1, buffer_size);
    cout << "s1 = " << s1 << endl;

    char s2[buffer_size];
    e.format(s2, buffer_size, false);
    cout << "s2 = " << s2 << endl;

    /*
    ostringstream strs;
    strs << setprecision(digits_in_s+1) << salary;
    string salary_str = strs.str();
    char* salary_chars = const_cast<char*>(salary_str.c_str());
    cout << "salary_str = " << salary_str << endl;
    cout << "salary_chars = " << salary_chars << endl;
    
    cout << "n_size: " << n_size << endl;
    cout << "s_Size: " << digits_in_s << endl;
     */
    
    cout << "\n";
    return 0;
}
