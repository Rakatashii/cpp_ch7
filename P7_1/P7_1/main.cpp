/*
 Exercise P7.1. Implement a class Person with the following fields:
 • the name
 • a pointer to the person’s best friend (a Person*)
 • a popularity counter that indicates how many other people have this person as their best friend
 Write a program that reads in a list of names, allocates a new Person for each of them, and stores them in a vector<Person*>. Then ask the name of the best friend for each of the Person objects. Locate the object matching the friend’s name and call
 */

#include <iostream>
#include "person.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    Person* p1 = new Person("D Ruff");
    Person* p2 = new Person("Sandy Long");
    Person* p3 = new Person("Guy Fieri");
    Person* p4 = new Person("Donald X");
    Person* p5 = new Person("C Meyer");
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
    vector<Person*> p1_friends = p1->get_friends();
    p1->display();
    cout << "\n";
    p2->display();
    cout << "\n";
    p3->display();
    cout << "\n";
    p4->display();
    cout << "\n";
    p5->display();
    cout << "\n";
    return 0;
}
