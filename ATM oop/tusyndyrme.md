# Банкомат жүйесі

-  Жақсылық Даниял Айтжанұлы
-  Нұсқа: 1 — Банкомат жүйесі

## Класс құрылымы
- `Account` — негізгі класс (шот). Ішінде кірістірілген `Operation` класы.
- `SavingsAccount`, `CheckingAccount` — туынды класстар.
- `Client` — клиент, шоттарға сілтеме жасайды.
- `ATM` — банкомат, ішінде кірістірілген `CashBox`.

## Негіздемелер
| Талап | Қайда |
|---|---|
| Статикалық мүше | `Account::totalAccounts`, `getTotalAccounts()`, `ATM::atmCount` |
| Дос класс | `friend class ATM` — PIN мен тарихқа геттерсіз қолжетім |
| Кірістірілген класс | `Account::Operation`, `ATM::CashBox` |
| Объектілер жиымы | `Account::history[]`, `Client::accounts[]` |
| Композиция | `Account` → `Operation`, `ATM` → `CashBox` |
| Агрегация | `Client` → `Account*`, `ATM` → `Account*` |
| Мұрагерлік | `Account` → `SavingsAccount`, `CheckingAccount` |
| Инкапсуляция | барлық өріс `private`/`protected` |

## UML
![UML](https://www.plantuml.com/plantuml/png/)

## Жинақтау
`g++ -std=c++11 *.cpp -o atm`
