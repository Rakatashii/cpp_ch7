/*
 Exercise P7.2. Implement a class Person with two fields name and age, and a class Car with three fields:
 • the model
 • a pointer to the owner (a Person*)
 • a pointer to the driver (also a Person*)
 Write a program that prompts the user to specify people and cars. Store them in a vector<Person*> and a vector<Car*>. Traverse the vector of Person objects and incre- ment their ages by one year. Finally, traverse the vector of cars and print out the car model, owner’s name and age, and driver’s name and age.
*/

#include <iostream>
#include "person.hpp"
#include "car.hpp"

int main(int argc, const char * argv[]) {
    std::vector<Person*> people;
    std::vector<Car*> cars;
    
    Person* p1 = new Person("D Ruff", 21);
    Person* p2 = new Person("Sandy Long", 34);
    Person* p3 = new Person("Guy Fieri", 68);
    Person* p4 = new Person("Donald X", 42);
    Person* p5 = new Person("C Meyer", 12);
    Person* p6 = new Person("Sid Viscious", 87);
    Person* p7 = new Person("Michael Scorn");
    
    people.push_back(p1);
    people.push_back(p2);
    people.push_back(p3);
    people.push_back(p4);
    people.push_back(p5);
    people.push_back(p6);
    people.push_back(p7);
    
    p1->add_friend(p2);
    p1->add_friend(p3);
    p1->add_friend(p4);
    p1->add_friend(p5);
    p2->add_friend(p3);
    p2->add_friend(p4);
    p2->add_friend(p5);
    p3->add_friend(p4);
    p3->add_friend(p5);
    p5->add_friend(p1);
    p5->add_friend(p3);
    p5->add_friend(p4);
    
    Car* c1 = new Car("Maserati", 1994);
    Car* c2 = new Car("Lamborghini", 1972);
    Car* c3 = new Car("Ford Focus", 1999);
    Car* c4 = new Car("Kia Soul", 2006);
    Car* c5 = new Car("Jeep Wrangler", 2014);
    
    cars.push_back(c1);
    cars.push_back(c2);
    cars.push_back(c3);
    cars.push_back(c4);
    cars.push_back(c5);
    
    c1->set_owner(p2);
    c1->set_driver(p2);
    c2->set_owner(p7);
    c2->set_driver(p3);
    c3->set_driver(p4);
    c4->set_owner(p4);
    c4->set_driver(p5);
    c5->set_driver(p6);
    
    int i;
    for (i = 0; i < people.size(); i++){
        int old_age = people[i]->get_age();
        people[i]->set_age(++old_age);
    }
    
    for (i = 0; i < cars.size(); i++){
        //std::cout << i << std::endl;
        if (i % 2 == 0 || i == 0 || i == 3 || i == 4){
            cars[i]->display_fields(true);
        } else if (i % 2 == 1){
            cars[i]->display_fields();
        }
        std::cout << "\n";
    }
    
    
    return 0;
}
