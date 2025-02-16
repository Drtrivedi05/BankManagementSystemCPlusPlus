#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    string name;
    double balance;

public:
    BankAccount() : accountNumber(0), name(""), balance(0.0) {}
    BankAccount(int accNo, const string &accName, double accBalance)
        : accountNumber(accNo), name(accName), balance(accBalance) {}

    void createAccount();
    void displayAccount() const;
    void deposit(double amount);
    void withdraw(double amount);
    int getAccountNumber() const { return accountNumber; }
    double getBalance() const { return balance; }
    string getName() const { return name; }
    void modifyAccount(const string &newName);
};

void BankAccount::createAccount() {
    cout << "Enter Account Number: ";
    cin >> accountNumber;
    cin.ignore(); // Clear newline from input buffer
    cout << "Enter Account Holder Name: ";
    getline(cin, name);
    cout << "Enter Initial Balance: ";
    cin >> balance;
    cout << "Account Created Successfully!\n";
}

void BankAccount::displayAccount() const {
    cout << "Account Number: " << accountNumber << "\n";
    cout << "Account Holder: " << name << "\n";
    cout << "Balance: " << balance << "\n";
}

void BankAccount::deposit(double amount) {
    balance += amount;
    cout << "Amount Deposited Successfully!\n";
}

void BankAccount::withdraw(double amount) {
    if (amount > balance) {
        cout << "Insufficient Balance!\n";
    } else {
        balance -= amount;
        cout << "Amount Withdrawn Successfully!\n";
    }
}

void BankAccount::modifyAccount(const string &newName) {
    name = newName;
    cout << "Account Modified Successfully!\n";
}

// Save all accounts to a text file (one record per line using '|' as a delimiter)
void saveToFile(const vector<BankAccount> &accounts) {
    ofstream file("accounts.txt");
    if (!file) {
        cerr << "Error opening file for writing!\n";
        return;
    }
    for (const auto &acc : accounts) {
        file << acc.getAccountNumber() << "|"
             << acc.getName() << "|"
             << acc.getBalance() << "\n";
    }
    file.close();
}

// Load all accounts from the text file
vector<BankAccount> loadFromFile() {
    vector<BankAccount> accounts;
    ifstream file("accounts.txt");
    if (!file) {
        // File might not exist on first run
        return accounts;
    }
    
    string line;
    while (getline(file, line)) {
        if(line.empty()) continue;
        stringstream ss(line);
        string token;
        int accNo;
        string accName;
        double balance;

        // Parse account number
        if(getline(ss, token, '|'))
            accNo = stoi(token);
        else
            continue;

        // Parse account holder name
        if(getline(ss, token, '|'))
            accName = token;
        else
            continue;

        // Parse balance
        if(getline(ss, token, '|'))
            balance = stod(token);
        else
            continue;

        BankAccount acc(accNo, accName, balance);
        accounts.push_back(acc);
    }
    file.close();
    return accounts;
}

void manageBank() {
    vector<BankAccount> accounts = loadFromFile();
    int choice, accNo;
    double amount;
    string newName;
    
    while (true) {
        cout << "\nBank Management System\n";
        cout << "1. Create Account\n";
        cout << "2. View Account\n";
        cout << "3. Deposit\n";
        cout << "4. Withdraw\n";
        cout << "5. Modify Account\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1: {
                BankAccount acc;
                acc.createAccount();
                accounts.push_back(acc);
                saveToFile(accounts);
                break;
            }
            case 2: {
                cout << "Enter Account Number: ";
                cin >> accNo;
                bool found = false;
                for (const auto &acc : accounts) {
                    if (acc.getAccountNumber() == accNo) {
                        acc.displayAccount();
                        found = true;
                        break;
                    }
                }
                if (!found)
                    cout << "Account not found!\n";
                break;
            }
            case 3: {
                cout << "Enter Account Number: ";
                cin >> accNo;
                cout << "Enter Deposit Amount: ";
                cin >> amount;
                bool found = false;
                for (auto &acc : accounts) {
                    if (acc.getAccountNumber() == accNo) {
                        acc.deposit(amount);
                        found = true;
                        break;
                    }
                }
                if (!found)
                    cout << "Account not found!\n";
                saveToFile(accounts);
                break;
            }
            case 4: {
                cout << "Enter Account Number: ";
                cin >> accNo;
                cout << "Enter Withdraw Amount: ";
                cin >> amount;
                bool found = false;
                for (auto &acc : accounts) {
                    if (acc.getAccountNumber() == accNo) {
                        acc.withdraw(amount);
                        found = true;
                        break;
                    }
                }
                if (!found)
                    cout << "Account not found!\n";
                saveToFile(accounts);
                break;
            }
            case 5: {
                cout << "Enter Account Number: ";
                cin >> accNo;
                cin.ignore(); // Clear newline
                cout << "Enter New Name: ";
                getline(cin, newName);
                bool found = false;
                for (auto &acc : accounts) {
                    if (acc.getAccountNumber() == accNo) {
                        acc.modifyAccount(newName);
                        found = true;
                        break;
                    }
                }
                if (!found)
                    cout << "Account not found!\n";
                saveToFile(accounts);
                break;
            }
            case 6:
                return;
            default:
                cout << "Invalid Choice!\n";
        }
    }
}

int main() {
    manageBank();
    return 0;
}
