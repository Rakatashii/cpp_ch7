/*
 Exercise P7.1.
 Implement a class Person with the following fields:
 • the name
 • a pointer to the person’s best friend (a Person*)
 • a popularity counter that indicates how many other people have this person as their best friend
 Write a program that reads in a list of names, allocates a new Person for each of them, and stores them in a vector<Person*>. Then ask the name of the best friend for each of the Person objects. Locate the object matching the friend’s name and call
 */

#ifndef person_hpp
#define person_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

class Person{
public:
    Person();
    Person(std::string n);
    void add_friend(Person* p);
    std::vector<Person*> get_friends();
    int get_friend_count() const;
    std::string get_name() const;
    void display() const;
private:
    std::vector<Person*> friends;
    std::string name;
};

#endif /* person_hpp */
