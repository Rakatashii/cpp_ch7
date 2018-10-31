/*
 Exercise P7.2. Implement a class Person with two fields name and age, and a class Car with three fields:
 • the model
 • a pointer to the owner (a Person*)
 • a pointer to the driver (also a Person*)
 Write a program that prompts the user to specify people and cars. Store them in a vector<Person*> and a vector<Car*>. Traverse the vector of Person objects and incre- ment their ages by one year. Finally, traverse the vector of cars and print out the car model, owner’s name and age, and driver’s name and age.
*/

#ifndef car_hpp
#define car_hpp

#include <stdio.h>
#include "person.hpp"

class Car{
public:
    Car();
    Car(std::string m);
    Car(std::string m, int y);
    Car(std::string m, int y, Person* o, Person* d);
    void set_owner(Person* p);
    void set_driver(Person* p);
    Person* get_owner() const;
    Person* get_driver() const;
    std::string get_model() const;
    void display_fields(bool display_friends = false);
private:
    std::string model;
    int year;
    Person* owner;
    Person* driver;
};

#endif /* car_hpp */
