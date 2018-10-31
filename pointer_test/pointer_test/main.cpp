//
//  main.cpp
//  pointer_test
//
//  Created by Christian Meyer on 10/28/18.
//  Copyright © 2018 Christian Meyer. All rights reserved.
//

#include <iostream>
#include "employee.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    // Good, now having trouble getting or setting e->@name
    unique_ptr<Employee> e1(new Employee());
    e1->set_name("Dandy");
    e1->set_salary(238949);
    string e1_name = e1->get_name();
    double e1_salary = e1->get_salary();
    cout << "e1_name: " << e1_name << endl;
    cout << "e1_salary: " << e1_salary << endl; // Working
    cout << "\n";
    
    //Employee* ptr2 = ptr; // NO - diff types
    
    /*
    unique_ptr<Employee> e3 = e1;
    string e3_name = e3->get_name();
    double e3_salary = e3->get_salary();
    cout << "e3_name: " << e3_name << endl;
    cout << "e3_salary: " << e3_salary << endl; // Working
    cout << "\n";
    */ // NO - the unique_ptr must be unique - the same resource cannot have multiple references.
    
    shared_ptr<Employee> e2(new Employee());
    e2->set_name("Sindra");
    e2->set_salary(232348);
    string e2_name = e2->get_name();
    double e2_salary = e2->get_salary();
    cout << "e2_name: " << e2_name << endl;
    cout << "e2_salary: " << e2_salary << endl; // Working
    cout << "\n";
    
    shared_ptr<Employee> e4 = e2;
    string e4_name = e4->get_name();
    double e4_salary = e4->get_salary();
    cout << "e4_name: " << e4_name << endl;
    cout << "e4_salary: " << e4_salary << endl; // Working
    cout << "\n";
    
    e2 = NULL;
    cout << "After deleting e2: " << endl;
    e4_name = e4->get_name();
    e4_salary = e4->get_salary();
    cout << "e4_name: " << e4_name << endl;
    cout << "e4_salary: " << e4_salary << endl; // Working
    cout << "\n";
    
    // So std::shared_ptr's e2 and e4 do not necessarily have the same value. They both, at one point, pointed to the new Employee object. And, even after e2 was set to NULL, e4 still pointed to the Employee obj with the name "Syndra".

    return 0;
}
