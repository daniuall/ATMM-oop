#ifndef CLIENT_H
#define CLIENT_H
#include <string>
#include "Account.h"

// Клиент шоттарға сілтеме жасайды (агрегация: шотты өзі жоймайды)
class Client {
private:
    std::string name;
    static const int MAX_ACCOUNTS = 5;
    Account* accounts[MAX_ACCOUNTS]; // объектілер (көрсеткіштер) жиымы
    int count;
public:
    Client(const std::string& name);
    bool addAccount(Account* acc);
    Account* getAccount(int index) const;
    int getAccountCount() const;
    std::string getName() const;
    void printAccounts() const;
};
#endif
