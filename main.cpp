#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string name;
    double balance;

public:
    // Constructor
    BankAccount(string accountName, double initialBalance)
        : name(accountName), balance(initialBalance) {}

    // Deposit
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Amount deposited successfully." << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    // Withdraw
    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount." << endl;
        }
        else if (amount <= balance) {
            balance -= amount;
            cout << "Amount withdrawn successfully." << endl;
        }
        else {
            cout << "Insufficient Funds." << endl;
        }
    }

    // Display account details
    void display() {
        cout << "\nAccount: " << name
             << "\nBalance: $" << balance << endl;
    }
};

int main() {
    string name;
    double initialDeposit;

    cout << "Enter your name: ";
    getline(cin, name);

    cout << "Enter initial deposit: ";
    cin >> initialDeposit;

    // Prevent negative initial balance
    if (initialDeposit < 0) {
        cout << "Initial deposit cannot be negative." << endl;
        return 0;
    }

    BankAccount account(name, initialDeposit);

    int choice;
    double amount;

    do {
        cout << "\n========== BANK MANAGEMENT SYSTEM ==========" << endl;
        cout << "1. Deposit" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Display Balance" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                cout << "Enter deposit amount: ";
                cin >> amount;
                account.deposit(amount);
                break;

            case 2:
                cout << "Enter withdrawal amount: ";
                cin >> amount;
                account.withdraw(amount);
                break;

            case 3:
                account.display();
                break;

            case 4:
                cout << "Thank you for using Bank Management System."
                     << endl;
                break;

            default:
                cout << "Invalid choice. Please try again."
                     << endl;
        }

    } while (choice != 4);

    return 0;
}


