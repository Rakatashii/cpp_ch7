#include "car.hpp"

Car::Car(){
    model = "";
    year = 0;
    owner = NULL;
    driver = NULL;
}
Car::Car(std::string m){
    model = m;
    year = 0;
    owner = NULL;
    driver = NULL;
}
Car::Car(std::string m, int y){
    model = m;
    year = y;
    owner = NULL;
    driver = NULL;
}
Car::Car(std::string m, int y, Person* o, Person* d){
    model = m;
    year = y;
    owner = o;
    driver = d;
}
void Car::set_owner(Person* p){
    owner = p;
}
void Car::set_driver(Person* p){
    driver = p;
}
Person* Car::get_owner() const{
    return owner;
}
Person* Car::get_driver() const{
    return driver;
}
std::string Car::get_model() const{
    return model;
}
void Car::display_fields(bool display_friends){
    if (model != ""){
        std::cout << "model: " << model << std::endl;
    } else {
        std::cout << "model: N/A" << std::endl;
    }
    if (year != 0){
        std::cout << "year: " << year << std::endl;
    } else {
        std::cout << "year: N/A" << std::endl;
    }
    if (owner != NULL){
        std::cout << "owner: " << owner->get_name() << std::endl;
        if ((owner->get_friend_count() > 0) && (display_friends == true)){
            owner->display_friends();
        }
    } else {
        std::cout << "owner: N/A" << std::endl;
    }
    if (driver != NULL){
        std::cout << "driver: " << driver->get_name() << std::endl;
        if ((driver->get_friend_count() > 0) && (display_friends == true)){
            driver->display_friends();
        }
    } else {
        std::cout << "driver: N/A" << std::endl;
    }
}

/*
private:
    std::string model;
    int year;
    Person* owner;
    Person* driver;
*/
