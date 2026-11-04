#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>

// Негізгі класс: банк шоты
class Account {
public:
    // Кірістірілген класс: шоттағы бір операция жазбасы
    class Operation {
    private:
        std::string type;
        double amount;
        double balanceAfter;
    public:
        Operation();
        Operation(const std::string& type, double amount, double balanceAfter);
        void print() const;
    };

private:
    std::string pin;                 // жеке: тек friend ATM көреді
    static const int MAX_HISTORY = 50;
    Operation history[MAX_HISTORY];  // объектілер жиымы
    int historyCount;
    static int totalAccounts;        // статикалық өріс
    static int nextId;

protected:
    int id;
    double balance;
    void record(const std::string& type, double amount); // операцияны тарихқа жазу

public:
    Account(const std::string& pin, double initial = 0);
    virtual ~Account();

    void deposit(double amount);
    virtual bool withdraw(double amount);
    virtual std::string getType() const;
    int getId() const;
    double getBalance() const;

    static int getTotalAccounts();   // статикалық әдіс

    // ATM-ге PIN және тарихқа тікелей қолжетім керек (геттерлерсіз)
    friend class ATM;
};

#endif
