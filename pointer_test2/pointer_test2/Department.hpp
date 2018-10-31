#ifndef Department_hpp
#define Department_hpp

#include <stdio.h>
#include "employee.hpp"

class Department{
public:
    Department(){
        employee_count = 0;
    }
    Department(std::string n){
        name = n;
        employee_count = 0;
    }
    void set_receptionist(Employee* e) { employee_count++; receptionist = e; };
    void set_secretary(Employee* e) { employee_count++; secretary = e; };
    void set_ceo(Employee* e) { employee_count++; ceo = e; };
    void set_cfo(Employee* e) { employee_count++; cfo = e; };
    void set_owner(Employee* e) { employee_count++; owner = e; };
    Employee* get_receptionist() const {return receptionist; };
    Employee* get_secretary() const {return secretary; };
    Employee* get_ceo() const {return ceo; };
    Employee* get_cfo() const {return cfo; };
    Employee* get_owner() const {return owner; };
    std::string get_name() const {return name; };
    int get_employee_count() const { return employee_count; };
private:
    std::string name;
    Employee* receptionist;
    Employee* secretary;
    Employee* ceo;
    Employee* cfo;
    Employee* owner;
    int employee_count;
};

#endif /* Department_hpp */
