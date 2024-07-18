// С++ program - Bankomat by Ksusha Pistsova
#include <iostream>
#include <vector>
using namespace std;

class Bank {
private:
    double balance = 0;
    int PIN;
    int banknotes[5] = { 5, 10, 20, 50, 100 };
    int MAX = 2000;

public:
    void setdata() {
        while (1) {
            cout << "Enter balance:" << endl;
            cin >> balance;
            if (balance > 0) break;
            cout << "Balance should be >= 0" << endl;
        }
        cout << "Enter PIN:" << endl;
        cin >> PIN;
        cout << endl << endl;
    }
    int isPINcorrect(int pin) {
        if (pin == PIN) {
            return true;
        }
        else return false;
    }
    void showbalance() {
        cout << "Total balance: " << balance << endl << endl;
    }
    void withdrawmoney() {
        cout << "Possible banknotes: " << endl;
        for (int i = 0; i < size(banknotes); i++)
            cout << banknotes[i] << "\t"; cout << endl;
        int money;
        while (1) {
            cout << "Enter amount to withdraw" << endl;
            cin >> money;
            if ((money <= balance) && (money % 5 == 0) && (money < MAX)) {
                balance -= money;
                break;
            }
            cout << "Incorrect amount. Maximum value = " << MAX << endl << 
            "Number must be divisible by 5 without remainder. Balance: " << balance << endl << endl;
        }

        int money1 = money;
        vector <int> banknoteslist;
        for (int i = size(banknotes) - 1; i >= 0; i--) {
            while (money1 - banknotes[i] >= 0) {
                money1 -= banknotes[i];
                banknoteslist.push_back(banknotes[i]);
            }
        }
        cout << endl << endl << "Your money: " << money << endl << "Banknotes: ";

        for (auto iter = banknoteslist.begin(); iter != banknoteslist.end(); ++iter) {
            cout << *iter << "\t";
        }
        cout << endl;
        //звук денег      
    }
};

int main() {
    Bank b; 
    b.setdata();

    int pin;
    for (;;) {
        cout << "PIN: " << endl;
        cin >> pin;
        if (b.isPINcorrect(pin)) break;
        cout << "Error!" << endl;
    }
    
    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~WELCOME~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    int choice;
    while (1) {
        cout << "Enter Your Choice (number)" << endl;
        cout << "\t1. Show Total balance" << endl;
        cout << "\t2. Withdraw Money" << endl;
        cout << "\t3. Cancel" << endl;
        cin >> choice; cout << endl;

        switch (choice) {
        case 1:
            b.showbalance();
            break;
        case 2:
            b.withdrawmoney();
            break;
        case 3:
            exit(1);
            break;
        default:
            cout << endl << "Invalid choice" << endl;
        }
    }
}

