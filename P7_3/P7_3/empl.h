#ifndef CCC_EMPL_H
#define CCC_EMPL_H

#include <string>
#include "account.hpp"
#include <vector>

using namespace std;

/**
   A basic employee class that is used in many examples
   in the book "Computing Concepts with C++ Essentials"
*/
class Employee
{
public:
    Employee();
    Employee(string employee_name, double initial_salary);
    void set_salary(double new_salary);
    void link_account(BankAccount* a);
    void link_shared(BankAccount** b, Employee* = NULL);
    BankAccount* get_account();
    double get_salary() const;
    void set_shared_name(string n);
    string get_name();
    string get_shared_name();
    void display_account();
    bool has_shared();
private:
    string name;
    double salary;
    BankAccount* account;
    BankAccount** family_linked;
    string shared_name;
};

#endif
