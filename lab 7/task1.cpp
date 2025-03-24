#include <iostream>
#include <string>

using namespace std;

class Account {
protected:
    int accountNumber;
    int balance;
    string accountHolderName;
    string accountType;

public:
    Account(int accountNumber, int balance, string accountHolderName)
        : accountNumber(accountNumber), balance(balance), accountHolderName(accountHolderName), accountType("Generic") {}

    void deposit(int amount) {
        balance += amount;
        cout << amount << " has been added to account number: " << accountNumber << endl;
    }

    virtual void withdraw(int amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << amount << " has been withdrawn from account number: " << accountNumber << endl;
        }
        else {
            cout << "Withdrawal failed: Insufficient funds" << endl;
        }
    }

    virtual void calculateInterest() {
        cout << "No interest rate for generic accounts" << endl;
    }

    virtual void printStatement() {
        cout << "ACCOUNT DETAILS:" << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder Name: " << accountHolderName << endl;
        cout << "Balance: " << balance << endl;
    }

    int getAccountNumber() {
        return accountNumber;
    }

    int getBalance() {
        return balance;
    }

    string getAccountHolderName() {
        return accountHolderName;
    }
};

class SavingAccount : public Account {
protected:
    float interestRate;
    int minimumBalance;

public:
    SavingAccount(int accountNumber, int balance, string accountHolderName, float interestRate, int minimumBalance)
        : Account(accountNumber, balance, accountHolderName), interestRate(interestRate), minimumBalance(minimumBalance) {
        accountType = "Savings";
    }

    void withdraw(int amount) override {
        if (amount <= balance && (balance - amount) >= minimumBalance) {
            balance -= amount;
            cout << amount << " has been withdrawn from account number: " << accountNumber << endl;
        }
        else {
            cout << "Withdrawal failed: Minimum balance requirement not met" << endl;
        }
    }

    void calculateInterest() override {
        // Let's assume 1 year as the time period for interest calculation
        int years = 1;
        int interest = balance * interestRate * years;
        cout << "Interest amount: " << interest << endl;
    }

    void printStatement() override {
        cout << "ACCOUNT DETAILS:" << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder Name: " << accountHolderName << endl;
        cout << "Balance: " << balance << endl;
        cout << "Interest Rate: " << interestRate * 100 << "%" << endl;
        cout << "Minimum Balance: " << minimumBalance << endl;
    }
};

class FixedDepositAccount : public Account {
protected:
    float fixedInterestRate;
    string maturityDate;

public:
    FixedDepositAccount(int accountNumber, int balance, string accountHolderName, float fixedInterestRate, string maturityDate)
        : Account(accountNumber, balance, accountHolderName), fixedInterestRate(fixedInterestRate), maturityDate(maturityDate) {
        accountType = "Fixed Deposit";
    }

    void calculateInterest() override {
        // Assuming 1 year as the time period for interest calculation
        int years = 1;
        int interest = balance * fixedInterestRate * years;
        cout << "Interest amount: " << interest << endl;
    }

    void withdraw(int amount) override {
        cout << "Cannot withdraw before maturity date (" << maturityDate << ")" << endl;
    }

    void printStatement() override {
        cout << "ACCOUNT DETAILS:" << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder Name: " << accountHolderName << endl;
        cout << "Balance: " << balance << endl;
        cout << "Maturity Date: " << maturityDate << endl;
        cout << "Fixed Interest Rate: " << fixedInterestRate * 100 << "%" << endl;
    }
};

class CheckingAccount : public Account {
public:
    CheckingAccount(int accountNumber, int balance, string accountHolderName)
        : Account(accountNumber, balance, accountHolderName) {
        accountType = "Checking";
    }

    void calculateInterest() override {
        cout << "No interest for checking account" << endl;
    }

    void printStatement() override {
        cout << "ACCOUNT DETAILS:" << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder Name: " << accountHolderName << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main() {
    cout << "--- Banking System --------" << endl;

    SavingAccount sa(1001, 5000, "John Doe", 0.05, 1000);
    FixedDepositAccount fd(1002, 10000, "Jane Smith", 0.08, "2025-12-31");
    CheckingAccount ca(1003, 3000, "Bob Johnson");

    Account* accounts[] = {&sa, &fd, &ca};

    for (Account* acc : accounts) {
        cout << "\nProcessing Account #" << acc->getAccountNumber() << endl;
        acc->deposit(1000);
        acc->withdraw(500);
        acc->calculateInterest();
        acc->printStatement();
        cout << "-----------------------" << endl;
    }

    return 0;
