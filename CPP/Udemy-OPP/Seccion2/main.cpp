#include"atm_headers.h"

int main(void) {
    int choice = 0;
    int enterPIN;
    long int enterAccountNo;

    atm user1;

    user1.setData(1234567, "Tim", 111, 45000.00, "9087654321");

    do {
        cout <<endl <<"----- Welcome  to ATM -----";
        cout <<endl <<"Enter your account No: ";
        cin >> enterAccountNo;

        cout <<endl <<"Enter PIN: ";
        cin >> enterPIN;

        if (enterAccountNo == user1.getAccountNo() && (enterPIN == user1.getPIN())) {
            do {
                int amount = 0;
                string oldMobileNo, newMobile;

                cout <<endl <<"----- Welcome to ATM -----";
                cout <<endl <<"Select options: ";
                cout <<endl <<"1. Check Balance.";
                cout <<endl <<"2. Chash withDraw.";
                cout <<endl <<"3. Show User Details.";
                cout <<endl <<"4. Update Mobile No.";
                cout <<endl <<"5. Exit" <<endl;
                cin >> choice;

                switch (choice)
                {
                    case 1:
                        cout <<endl <<"Your Bank balance is: " << user1.getBalance();
                        break;
                    case 2:
                        cout <<endl <<"Enter the account: ";
                        cin >> amount;
                        user1.cashWithDraw(amount);
                        break;
                    case 3:
                        cout <<endl <<"----- User Details are:- ";
                        cout <<endl <<"--> Account No:  " << user1.getAccountNo();
                        cout <<endl <<"--> Name         " << user1.getName();
                        cout <<endl <<"--> Balance      " << user1.getBalance();
                        cout <<endl <<"--> Mobile No    " << user1.getMobileNo();
                        break;
                    case 4:
                        cout <<endl <<"Enter old Mobile No. ";
                        cin >> oldMobileNo;

                        cout <<endl <<"Enter new Mobile No. ";
                        cin >> newMobile;

                        user1.setMobile(oldMobileNo, newMobile);
                        break;
                    case 5:
                        exit(0);
                        break;
                    default:
                        cout <<endl <<"Enter Valid Data!!";
                        break;
                }
            } while (1);

        } else {
            cout <<endl <<"User Datails are Invalid!!";
        }

    } while (1);

    return (0);
}