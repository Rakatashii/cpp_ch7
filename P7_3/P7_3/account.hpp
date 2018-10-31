/*
 Exercise P7.3.
 Enhance the Employee class of Chapter 2 to include a pointer to a BankAccount.
 Read in employees and their salaries.
 
 Store them in a vector<Employee>.
 
 For each employee, allocate a new bank account on the heap, except that two consecutive employees with the same last name should share the same account.
 
 Then traverse the vector of employees and, for each employee, deposit 1/12th of their annual salary into their bank account.
 
 Afterwards, print all employee names and account balances.
*/

#ifndef account_hpp
#define account_hpp

#include <iostream>
#include <stdio.h>
#include <iomanip>

class BankAccount{
public:
    //~BankAccount();
    BankAccount();
    BankAccount(double b);
    void deposit(double d);
    double get_balance();
    void print_balance();
private:
    double balance;
};

#endif /* account_hpp */
