#include <iostream>
#include "Bank.hpp"

int main () 
{
    Bank bank;
    
    try 
    {
        // Весь код программы здесь
        bank.addClient("Alex", "1234567890", 18);
        bank.openAccount(1000, 1, "Debit", 0);
        bank.deposit(1000, 500);
        bank.showAllClients();
        bank.showClientAccounts(1);

        bank.addClient("James", "0102034567", 20);
        bank.openAccount(1001, 2, "Credit", 200);
        bank.showAllClients();
        bank.showClientAccounts(2);
    }
    catch (const std::exception& e) 
    {
        std::cout << e.what() << std::endl;
    }
    
    return 0;
}
