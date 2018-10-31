/*
 Exercise P7.3.
 Enhance the Employee class of Chapter 2 to include a pointer to a BankAccount.
 Read in employees and their salaries.
 Store them in a vector<Employee>.
 For each employee, allocate a new bank account on the heap, except that two consecutive employees with the same last name should share the same account.
 Then traverse the vector of employees and, for each employee, deposit 1/12th of their annual salary into their bank account.
 Afterwards, print all employee names and account balances.
 */

#include <iostream>
#include "empl.h"
#include "account.hpp"
#include <vector>

using namespace std;

bool last_name(Employee* a, Employee* b);
void remove_account(vector<BankAccount*>& v, int idx);
bool scan_last_names(Employee* a, int self, vector<Employee*>& v, vector<BankAccount*> bank);

int main(int argc, const char * argv[]) {
    vector<Employee*> employees;
    vector<BankAccount*> accounts;
    
    Employee* e0 = new Employee("Jim Fisher", 23455);
    Employee* e1 = new Employee("Bob Saget", 34562);
    Employee* e2 = new Employee("Cindy Saget", 93235);
    Employee* e3 = new Employee("Panera Bread", 101923);
    Employee* e4 = new Employee("Guy Fieri", 201324);
    Employee* e5 = new Employee("Liz Fisher", 72123);
    employees.push_back(e0);
    employees.push_back(e1);
    employees.push_back(e2);
    employees.push_back(e3);
    employees.push_back(e4);
    employees.push_back(e5);
    
    BankAccount* a0 = new BankAccount(10000);
    BankAccount* a1 = new BankAccount(64000);
    BankAccount* a2 = new BankAccount(0.0);
    BankAccount* a3 = new BankAccount(91823.5);
    BankAccount* a4 = new BankAccount(2045.95);
    BankAccount* a5 = new BankAccount(23493.2);
    accounts.push_back(a0);
    accounts.push_back(a1);
    accounts.push_back(a2);
    accounts.push_back(a3);
    accounts.push_back(a4);
    accounts.push_back(a5);
    
    
    for (int i = 0; (i < employees.size()) && (i < accounts.size()); i++){
        if (accounts.size() <= 0){
            exit;
        }
        if (scan_last_names(employees[i], i, employees, accounts)){
            //remove_account(accounts, i);
        } else {
            employees[i]->link_account(accounts[i]);
        }
    }

    for (int i = 0; i < employees.size(); i++){
        //cout << "employee[" << i << "]: " << endl;
        employees[i]->display_account();
        if (employees[i]->has_shared()){
            cout << "employee[" << i << "] (" << employees[i]->get_name() << ") shares account with " << employees[i]->get_shared_name() << endl;
        }
        cout << "\n";
    }
    
    return 0;
}

bool last_name(Employee* a, Employee* b){
    int count = 0;
    int i, j;
    string a_name = a->get_name();
    string b_name = b->get_name();
    string last_name = "";
    
    for (i = 0; i < a_name.size(); i++){
        for (j = 0; j < b_name.size(); j++){
            if (a_name[i] == b_name[j]){
                count++;
                last_name += a_name[i];
                //cout << "LETTER MATCH: " << a_name[i]  << last_name << endl;
                if (count >= 4){
                    //cout << "MATCH: " << "last name = " << last_name << endl;
                    return true;
                }
                ++i;
            } else{
                last_name = "";
                count = 0;
            }
        }
    }
    return false;
}
bool scan_last_names(Employee* a, int self_idx, vector<Employee*>& v, vector<BankAccount*> bank){
    int i = 0;
    if (a->get_account() != NULL){
        return true;
    }
    if ((self_idx+1) < v.size()){
        for (i = (self_idx+1); i < v.size(); i++){
            if (last_name(a, v[i])){
                //cout << "a has index " << self_idx << " : v has index " << i << endl;
                if ((a->get_account() == NULL) && (v[i]->get_account() == NULL)){
                    a->link_account(bank[self_idx]);
                    BankAccount* b = a->get_account();
                    //cout << "b->get_balance(): " << b->get_balance() << endl;
                    BankAccount** b_ptr = &b;
                    v[i]->link_shared(b_ptr, a);
                    //cout << "v[i]->get_account()->get_balance(): " << v[i]->get_account()->get_balance() << endl;
                    return true;
                }
                else if (v[i]->get_account() == NULL){
                    BankAccount* b = a->get_account();
                    BankAccount** b_ptr = &b;
                    v[i]->link_shared(b_ptr, a);
                    return true;
                } else if (v[i]->get_account() != NULL){
                    double add = v[i]->get_account()->get_balance();
                    BankAccount* b = v[i]->get_account();
                    BankAccount** b_ptr = &b;
                    a->link_shared(b_ptr, v[i]);
                    a->get_account()->deposit(add);
                    return true;
                } else{
                    cout << "bank account for v[" << i << "] is NULL";
                    return false;
                }
            }
        }
    }
    return false;
}
void remove_account(vector<BankAccount*>& v, int idx){
    for (int i = idx; i < v.size(); i++){
        v[i] = v[i+1];
    }
    v.pop_back();
}

/*
employees[1]->link_account(a0);
employees[2]->link_account(a1);
cout << "e1 ";
employees[1]->get_account()->print_balance();
cout << "e2 ";
employees[2]->get_account()->print_balance();

if (last_name(employees[1], employees[2])){
    BankAccount** b;
    BankAccount* e1 = employees[1]->get_account();
    b = &e1;
    employees[2]->link_shared(b, employees[1]);
}

cout << "e1 ";
employees[1]->get_account()->print_balance();
cout << "e2 ";
employees[2]->get_account()->print_balance();

employees[1]->get_account()->deposit(5000);

cout << "e1 ";
employees[1]->get_account()->print_balance();
cout << "e2 ";
employees[2]->get_account()->print_balance();

employees[2]->get_account()->deposit(800);

cout << "e1 ";
employees[1]->get_account()->print_balance();
cout << "e2 ";
employees[2]->get_account()->print_balance();
 */
