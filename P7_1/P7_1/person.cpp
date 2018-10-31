#include "person.hpp"

Person::Person(){
    name = "";
    friends = {};
}
Person::Person(std::string n){
    name = n;
    friends = {};
}
void Person::add_friend(Person* p){
    friends.push_back(p);
}
std::vector<Person*> Person::get_friends(){
    return friends;
}
int Person::get_friend_count() const{
    int size = friends.size();
    return size;
}
std::string Person::get_name() const{
    return name;
}
void Person::display() const{
    int i;
    if (this->get_friend_count() != 0){
        std::cout << this->get_name() << " has " << this->get_friend_count() << " friends:" << std::endl;
    } else {
        std::cout << this->get_name() << " has no friends." << std::endl;
    }
    for (i = 0; i < friends.size(); i++){
        std::cout << std::setw(10) << std::setfill(' ') << "Friend " << i+1 << ": ";
        std::cout << std::setw(10) << std::setfill(' ') << (friends[i])->get_name() << std::endl;
    }
}
/*
 private:
 std::vector<Person*> friends;
 std:: string name;
*/

