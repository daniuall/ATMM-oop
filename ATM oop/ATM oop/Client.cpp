#include "Client.h"
#include <iostream>
using namespace std;

Client::Client(const string& n) : name(n), count(0) {
    for (int i = 0; i < MAX_ACCOUNTS; i++) accounts[i] = nullptr;
}
bool Client::addAccount(Account* acc) {
    if (count >= MAX_ACCOUNTS || acc == nullptr) return false;
    accounts[count++] = acc;
    return true;
}
Account* Client::getAccount(int i) const {
    return (i >= 0 && i < count) ? accounts[i] : nullptr;
}
int Client::getAccountCount() const { return count; }
string Client::getName() const { return name; }
void Client::printAccounts() const {
    cout << "Клиент: " << name << endl;
    for (int i = 0; i < count; i++)
        cout << "  [" << i << "] " << accounts[i]->getType()
             << " №" << accounts[i]->getId()
             << ", қалдық: " << accounts[i]->getBalance() << endl;
}
