#include "account.hpp"

/*
BankAccount::~BankAccount(){
    balance = 0.0;
}
 */
BankAccount::BankAccount(){
    balance = 0.0;
}
BankAccount::BankAccount(double b){
    balance = b;
}
void BankAccount::deposit(double d){
    balance += d;
}
double BankAccount::get_balance(){
    return balance;
}
void BankAccount::print_balance(){
    std::cout << std::fixed << std::setprecision(2) << "BALANCE: $" << this->get_balance() << std::endl;
}

/*
private:
    double balance;
*/
