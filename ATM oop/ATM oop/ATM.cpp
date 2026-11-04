#include "ATM.h"
#include <iostream>
using namespace std;

int ATM::atmCount = 0;

ATM::CashBox::CashBox(double c) : cash(c) {}
bool ATM::CashBox::dispense(double amount) {
    if (amount > cash) return false;
    cash -= amount;
    return true;
}
void ATM::CashBox::load(double amount) { cash += amount; }
double ATM::CashBox::getCash() const { return cash; }

ATM::ATM(double initialCash) : atmId(++atmCount), box(initialCash), current(nullptr) {}

bool ATM::insertCard(Account& acc, const string& pin) {
    if (acc.pin != pin) { // жеке өріске friend арқылы қолжетім
        cout << "Қате PIN!" << endl;
        return false;
    }
    current = &acc;
    cout << "ATM#" << atmId << ": шот №" << acc.getId() << " ашылды" << endl;
    return true;
}

void ATM::ejectCard() { current = nullptr; cout << "Карта қайтарылды" << endl; }

bool ATM::withdraw(double amount) {
    if (!current) { cout << "Карта салынбаған" << endl; return false; }
    if (amount > box.getCash()) { cout << "Банкоматта ақша жеткіліксіз" << endl; return false; }
    if (!current->withdraw(amount)) { cout << "Шотта қаражат жеткіліксіз" << endl; return false; }
    box.dispense(amount);
    cout << "Берілді: " << amount << endl;
    return true;
}

bool ATM::deposit(double amount) {
    if (!current || amount <= 0) return false;
    current->deposit(amount);
    box.load(amount);
    cout << "Салынды: " << amount << endl;
    return true;
}

void ATM::checkBalance() const {
    if (current) cout << "Қалдық: " << current->getBalance() << endl;
}

void ATM::printHistory() const {
    if (!current) return;
    cout << "Операциялар тарихы:" << endl;
    for (int i = 0; i < current->historyCount; i++)
        current->history[i].print();
}

int ATM::getAtmCount() { return atmCount; }
