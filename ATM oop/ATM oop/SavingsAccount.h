#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include "Account.h"

// Туынды класс: жинақ шоты (өз мүшесі: interestRate, addInterest)
class SavingsAccount : public Account {
private:
    double interestRate; // пайыз, мысалы 5 = 5%
public:
    SavingsAccount(const std::string& pin, double initial, double rate);
    void addInterest();
    std::string getType() const override;
};
#endif
