#include <iostream>
#include "Account.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include "Client.h"
#include "ATM.h"
using namespace std;

int main() {
    SavingsAccount sav("1234", 100000, 5);
    CheckingAccount chk("1234", 50000, 20000);

    Client client("Асанов Асан");
    client.addAccount(&sav);
    client.addAccount(&chk);
    client.printAccounts();

    ATM atm(500000);

    cout << "\n--- Қате PIN ---" << endl;
    atm.insertCard(sav, "0000");

    cout << "\n--- Жинақ шоты ---" << endl;
    if (atm.insertCard(sav, "1234")) {
        atm.deposit(20000);
        atm.withdraw(30000);
        sav.addInterest();
        atm.checkBalance();
        atm.printHistory();
        atm.ejectCard();
    }

    cout << "\n--- Ағымдағы шот (овердрафт) ---" << endl;
    if (atm.insertCard(chk, "1234")) {
        atm.withdraw(60000);   // баланстан артық, овердрафт шегінде
        atm.withdraw(20000);   // лимиттен асады
        atm.checkBalance();
        atm.printHistory();
        atm.ejectCard();
    }

    cout << "\nШоттар саны: " << Account::getTotalAccounts()
         << ", банкоматтар саны: " << ATM::getAtmCount() << endl;
    return 0;
}

