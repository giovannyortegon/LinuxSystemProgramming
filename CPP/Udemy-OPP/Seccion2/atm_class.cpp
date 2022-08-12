#include"atm_headers.h"

void atm::setData(long int account_No_a, string name_a, int PIN_a, 
                  double balance_a, string mobile_No_a) {
    account_No = account_No_a;
    name = name_a;
    PIN = PIN_a;
    balance = balance_a;
    mobile_No = mobile_No_a;
}
long int atm::getAccountNo() {
    return account_No;
}
string atm::getName() {
    return name;
}
int atm::getPIN() {
    return PIN;
}
double atm::getBalance() {
    return balance;
}
string atm::getMobileNo() {
    return mobile_No;
}
void atm::setMobile(string mob_prev, string mob_new) {
    if (mob_prev == mobile_No) {
        mobile_No = mob_new;
        cout <<endl << "Successfully Update Mobile no.";
    } else {
        cout <<endl <<"Incorrect!! old mobile no";
    }

}
void atm::cashWithDraw(int amount_a) {
    if (amount_a > 0 && amount_a < balance) {
        balance -= amount_a;
        cout <<endl <<"Please collect your cash";
        cout <<endl <<"Available Balance: " <<balance;        
    } else {
        cout <<endl <<"Invalid input or insufficient Balance.";
    }
}