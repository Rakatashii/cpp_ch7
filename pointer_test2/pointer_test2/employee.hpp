//
//  employee.hpp
//  pointer_test
//
//  Created by Christian Meyer on 10/28/18.
//  Copyright © 2018 Christian Meyer. All rights reserved.
//

#ifndef employee_hpp
#define employee_hpp

#include <stdio.h>
#include <string>

class Employee{
public:
    Employee();
    Employee(std::string n);
    Employee(std::string n, double s);
    void set_name(std::string n);
    void set_salary(double s);
    std::string get_name() const;
    double get_salary() const;
    
private:
    std::string name;
    double salary;
};

#endif /* employee_hpp */
