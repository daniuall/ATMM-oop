#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H
#include "Account.h"

// Туынды класс: ағымдағы шот (овердрафт лимиті бар)
class CheckingAccount : public Account {
private:
    double overdraftLimit;
public:
    CheckingAccount(const std::string& pin, double initial, double overdraft);
    bool withdraw(double amount) override;
    std::string getType() const override;
    double getOverdraftLimit() const;
};
#endif
