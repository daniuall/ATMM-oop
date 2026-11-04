#include "CheckingAccount.h"

CheckingAccount::CheckingAccount(const std::string& pin, double initial, double overdraft)
    : Account(pin, initial), overdraftLimit(overdraft) {}

bool CheckingAccount::withdraw(double amount) {
    if (amount <= 0 || amount > balance + overdraftLimit) return false;
    balance -= amount;
    record("Алу", amount);
    return true;
}

std::string CheckingAccount::getType() const { return "Ағымдағы шот"; }
double CheckingAccount::getOverdraftLimit() const { return overdraftLimit; }
