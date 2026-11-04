#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(const std::string& pin, double initial, double rate)
    : Account(pin, initial), interestRate(rate) {}

void SavingsAccount::addInterest() {
    double interest = balance * interestRate / 100;
    balance += interest;
    record("Пайыз", interest);
}

std::string SavingsAccount::getType() const { return "Жинақ шоты"; }
