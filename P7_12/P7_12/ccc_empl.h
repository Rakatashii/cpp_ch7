#ifndef CCC_EMPL_H
#define CCC_EMPL_H

/*
 Exercise P7.12. Add a member function
 void Employee::format(char buffer[], int buffer_maxlength)
 to the Employee class. The member function should fill the buffer with the name and salary of the employee. Be sure not to overrun the buffer. It can hold buffer_maxlength characters, not counting the '\0' terminator. (That is, the buffer has buffer_maxlength + 1 bytes available.) Be sure to provide a '\0' terminator.
 */

#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>

using namespace std;

/**
   A basic employee class that is used in many examples
   in the book "Computing Concepts with C++ Essentials"
*/
class Employee
{
public:
   /**
      Constructs an employee with empty name and no salary.
   */
    Employee();
   /**
      Constructs an employee with a given name and salary.
      @param employee_name the employee name
      @param initial_salary the initial salary
   */
    Employee(string employee_name, double initial_salary);
   /**
      Sets the salary of this employee.
      @param new_salary the new salary value
   */
    void set_salary(double new_salary);
   /**
      Gets the salary of this employee.
      @return the current salary
   */
    double get_salary() const;
   /**
      Gets the name of this employee.
      @return the employee name
   */
    string get_name() const;
    char* name_char_array();
    char* salary_char_array();
    void format(char buffer[], int buffer_maxlength, bool space = true);
private:
    string name;
    double salary;
};

#endif
