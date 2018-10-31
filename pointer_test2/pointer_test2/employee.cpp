#include "employee.hpp"

Employee::Employee(){
    name = "";
    salary = 0.0;
}
Employee::Employee(std::string n){
    name = n;
    salary = 0.0;
}
Employee::Employee(std::string n, double s){
    name = n;
    salary = s;
}
void Employee::set_name(std::string n){
    name = n;
}
void Employee::set_salary(double s){
    salary = s;
}
std::string Employee::get_name() const{
    return name;
}
double Employee::get_salary() const{
    return salary;
}

