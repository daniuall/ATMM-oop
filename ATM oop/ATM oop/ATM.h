#ifndef ATM_H
#define ATM_H
#include "Account.h"

// Банкомат. CashBox оның ішінде өмір сүреді (композиция).
// Ағымдағы шотқа сілтеме (агрегация).
class ATM {
private:
    // Кірістірілген класс: ақша салынатын кассета
    class CashBox {
    private:
        double cash;
    public:
        CashBox(double c);
        bool dispense(double amount);
        void load(double amount);
        double getCash() const;
    };

    int atmId;
    CashBox box;            // композиция
    Account* current;       // агрегация
    static int atmCount;    // статикалық өріс

public:
    ATM(double initialCash);
    bool insertCard(Account& acc, const std::string& pin); // friend арқылы PIN тексеру
    void ejectCard();
    bool withdraw(double amount);
    bool deposit(double amount);
    void checkBalance() const;
    void printHistory() const; // friend арқылы тарихқа қолжетім
    static int getAtmCount();
};
#endif
