#include <iostream>
using namespace std;

// Default pin and balance
const int DEFAULT_PIN = 0000;
const int DEFAULT_BALANCE = 1000;

int main() {
    int pin, new_pin, balance = DEFAULT_BALANCE;
    int attempts = 0;
    bool authenticated = false;

    // Authentication loop
    while (!authenticated && attempts < 3) {
        cout << "Enter your PIN: ";
        cin >> pin;
        
        if (pin == DEFAULT_PIN) {
            authenticated = true;
            cout << "Authenticated successfully!" << endl;
        } else {
            attempts++;
            if (attempts < 3) {
                cout << "Invalid PIN. Please try again." << endl;
            } else {
                cout << "Too many failed attempts. Exiting program." << endl;
                return 0;
            }
        }
    }
    
    // Menu loop
    while (authenticated) {
        int choice;
        cout << "Enter 1 to reset your PIN, 2 to send money, or 3 to exit: ";
        cin >> choice;
        
        switch (choice) {
            case 1: // Resetting PIN
                cout << "Enter your new PIN: ";
                cin >> new_pin;
                pin = new_pin;
                cout << "Your PIN has been reset successfully." << endl;
                break;
            case 2: // Sending money
                int amount;
                cout << "Enter the amount you want to send: ";
                cin >> amount;
                if (amount > balance) {
                    cout << "You don't have enough balance to make this transaction." << endl;
                } else {
                    balance -= amount;
                    cout << "Transaction successful. Your new balance is: " << balance << endl;
                }
                break;
            case 3: // Exiting
                cout << "Exiting program." << endl;
                authenticated = false;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }
    
    return 0;
}

