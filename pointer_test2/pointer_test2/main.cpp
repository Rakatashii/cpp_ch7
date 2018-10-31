#include <iostream>
#include "employee.hpp"
#include "department.hpp"

using namespace std;

void raise_salary(Employee* e, double by) {
    double new_salary = e->get_salary() * (1 + by / 100);
    e->set_salary(new_salary);
}

int main(int argc, const char * argv[]) {
    Employee* receptionist = new Employee("Sindra Ahri", 23842);
    Employee* secretary = receptionist;
    Employee* ceo = new Employee("Daniel Jones", 192324);
    Employee* cfo = new Employee("Jake Doss", 59234);
    Employee* owner = ceo;
    
    Department d("Research");
    d.set_receptionist(receptionist);
    d.set_secretary(secretary);
    d.set_ceo(ceo);
    d.set_cfo(cfo);
    d.set_owner(owner);
    
    cout << "Receptionist for department " << d.get_name() << ": " << d.get_receptionist()->get_name() << endl;
    cout << "Secretary for department " << d.get_name() << ": " << d.get_secretary()->get_name() << endl;
    cout << "CEO of department " << d.get_name() << ": " << d.get_ceo()->get_name() << endl;
    cout << "CFO of department " << d.get_name() << ": " << d.get_cfo()->get_name() << endl;
    cout << "Owner of department " << d.get_name() << ": " << d.get_owner()->get_name() << endl;
    cout << "\n";
    cout << "Owner " << d.get_owner()->get_name() << " earned $" << d.get_owner()->get_salary() << " last year." << endl;
    cout << "After a 5% increase in profits, ";
    double by = 5.0;
    raise_salary(d.get_owner(), by);
    cout << "Owner " << d.get_owner()->get_name() << " makes $" << d.get_owner()->get_salary() << endl;
    cout << "\n";
    cout << "VERIFY: " << "Owner " << d.get_owner()->get_name() << " earns $" << d.get_owner()->get_salary() << endl;
    // So even by changing the salary of the employee object in the non-member void helper function, the salary of the employee object 'owner' in the department class is changed.
    return 0;
}
