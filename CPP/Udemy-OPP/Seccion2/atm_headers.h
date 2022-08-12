#include<iostream>
#include<string>

using namespace std;

class atm {
    private:
        long int account_No;
        string name;
        int PIN;
        double balance;
        string mobile_No;
    
    public:
        void setData(long int account_No_a, string name_a, int PIN_a,
                    double balance_a, string mobile_No_a);
        long int getAccountNo();
        string getName();
        int getPIN();
        double getBalance();
        string getMobileNo();
        void setMobile(string mob_prev, string mob_new);
        void cashWithDraw(int amount_a);
};