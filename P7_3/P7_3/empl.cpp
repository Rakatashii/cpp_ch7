#include "empl.h"

Employee::Employee()
{
    //name = "";
    //shared_names = {};
    salary = 0;
    account = NULL;
    family_linked = NULL;
}
Employee::Employee(string employee_name, double initial_salary) {  
    name = employee_name;
    //shared_names = {};
    salary = initial_salary;
    account = NULL;
    family_linked = NULL;
}
void Employee::link_account(BankAccount* a){
    account = a;
    family_linked = &a;
}
void Employee::link_shared(BankAccount** b, Employee* e){
    family_linked = b;
    account = *b;
    
    string name = this->get_name();
    string e_name;
    
    if (e != NULL){
        e_name = e->get_name();
        this->set_shared_name(e_name);
        e->set_shared_name(name);
    }

    if (e != NULL){
        e->link_shared(b, NULL);
    }
    
end2: {}
}
BankAccount* Employee::get_account(){
    return account;
}
void Employee::set_salary(double new_salary)
{  
    salary = new_salary;
}
double Employee::get_salary() const{
   return salary;
}
string Employee::get_name(){  
   return name;
}
string Employee::get_shared_name(){
    return shared_name;
}
void Employee::display_account(){
    if (account != NULL){
        string name = this->get_name();
        std::cout << "Employee " << name << " has balance $" << this->get_account()->get_balance() << std::endl;
    } else{
        std::cout << "Employee " << name << " has no account registered. " << std::endl;
    }
}
bool Employee::has_shared(){
    if (shared_name.size() == 0){
        return false;
    }
    return true;
}
void Employee::set_shared_name(string n){
    shared_name = n;
}
