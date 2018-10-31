#include "person.hpp"

Person::Person(){
    name = "";
    friends = {};
    age = 0;
}
Person::Person(std::string n){
    name = n;
    friends = {};
    age = 0;
}
Person::Person(std::string n, int a){
    name = n;
    friends = {};
    age = a;
}
void Person::add_friend(Person* p){
    friends.push_back(p);
}
void Person::set_age(int i){
    age = i;
}
std::vector<Person*> Person::get_friends(){
    return friends;
}
unsigned long Person::get_friend_count() const{
    unsigned long size = friends.size();
    return size;
}
std::string Person::get_name() const{
    return name;
}
int Person::get_age() const{
    return age;
}
void Person::display_friends() const{
    int i;
    if (this->get_friend_count() != 0){
        std::cout << "  " << this->get_name() << " has " << this->get_friend_count() << " friends:" << std::endl;
    } else {
        std::cout << "  " << this->get_name() << " has no friends." << std::endl;
    }
    for (i = 0; i < friends.size(); i++){
        std::cout << "  " << std::setw(10) << std::setfill(' ') << "Friend " << i+1 << ": ";
        std::cout << "  " << std::setw(10) << std::setfill(' ') << (friends[i])->get_name() << std::endl;
    }
    if (age != 0){
        std::cout << "  " << "He/she is " << this->get_age() << " years old." << std::endl;
    } else {
        std::cout << "  " << "Age unknown" << std:: endl;
    }
}
/*
 private:
 std::vector<Person*> friends;
 std:: string name;
 */


