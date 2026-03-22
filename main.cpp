#include <iostream>
#include "Client.h"
#include "Account.h"

int main () 
{
    Client client1("Alex", "0820695930", 18);

    std::cout << client1.getID() << std::endl;
    std::cout << client1.getName() << std::endl;
    std::cout << client1.getPassport() << std::endl;
    client1.showInfo();

    std::cout << "- - - - - - - - - - - - - - - - - - " << std::endl;

    Account account1(1200, client1.getID(), "debit");

    std::cout << account1.getAccountNumber() << std::endl;
    std::cout << account1.getBalance() <<std::endl;
    std::cout << account1.getOwnerID() << std::endl;
    std::cout << account1.getTypeAcc() << std::endl;

    account1.deposit(250);
    std::cout << account1.getBalance() << std::endl;

    account1.withdraw(250);
    std::cout << account1.getBalance() << std::endl;

    account1.showInfo();

    return 0;
}