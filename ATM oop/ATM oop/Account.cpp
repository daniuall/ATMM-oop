#include "Account.h"
#include <iostream>
using namespace std;

int Account::totalAccounts = 0;
int Account::nextId = 1000;

Account::Operation::Operation() : type(""), amount(0), balanceAfter(0) {}
Account::Operation::Operation(const string& t, double a, double b)
    : type(t), amount(a), balanceAfter(b) {}
void Account::Operation::print() const {
    cout << "  " << type << ": " << amount << " | қалдық: " << balanceAfter << endl;
}

Account::Account(const string& p, double initial)
    : pin(p), historyCount(0), id(nextId++), balance(initial) {
    totalAccounts++;
}
Account::~Account() { totalAccounts--; }

void Account::record(const string& type, double amount) {
    if (historyCount < MAX_HISTORY)
        history[historyCount++] = Operation(type, amount, balance);
}

void Account::deposit(double amount) {
    if (amount <= 0) return;
    balance += amount;
    record("Салу", amount);
}

bool Account::withdraw(double amount) {
    if (amount <= 0 || amount > balance) return false;
    balance -= amount;
    record("Алу", amount);
    return true;
}

string Account::getType() const { return "Жалпы шот"; }
int Account::getId() const { return id; }
double Account::getBalance() const { return balance; }
int Account::getTotalAccounts() { return totalAccounts; }
