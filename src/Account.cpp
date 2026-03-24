#include <iostream>
#include <string>
#include <cstdlib>
#include <assert.h>
#include "Account.h"

Account::Account (double balance, int ownerID, std::string typeAcc) 
{
    srand(static_cast<unsigned int>(time(NULL))); // grain for random
    int random_account_number = 1000 + rand() % (9999 - 1000 + 1);

    //проверка: существует ли уже такой номер счета в базе, если да то крутим рандом еще раз, с помощью while
    accountNumber = random_account_number;

    assert (balance >= 0);
    this->balance = balance;

    this->ownerID = ownerID;

    assert (typeAcc == "debit" || typeAcc == "credit");
    this->typeAcc = typeAcc;
}

int Account::getAccountNumber () const 
{
    return accountNumber;
}

double Account::getBalance () const 
{
    return balance;
}

void Account::setBalance (double newBalance)  
{
    balance = newBalance;
}

int Account::getOwnerID () const 
{
    return ownerID;
}

std::string Account::getTypeAcc () const 
{
    return typeAcc;
}

void Account::deposit (double amount) 
{
    if (amount > 0) 
    {
        balance += amount;
    } 
}

bool Account::withdraw (double amount) 
{
    if (amount > 0) 
    {
        if (amount <= balance) 
        {
            balance -= amount;
            return true;
        }
        else 
        {
            return false;
        }
    }
    else return false;
}

void Account::showInfo () 
{
    std::cout << "-- INFORMATION FOR ACCOUNT --" << std::endl;
    std::cout << "\n[- Account number: " << getAccountNumber() << std::endl;
    std::cout << "\n[- Balance: " << getBalance() << std::endl;
    std::cout << "\n[- Owner ID: " << getOwnerID()  << std::endl;
    std::cout << "\n[- Type account: " << getTypeAcc() << std::endl;
    std::cout << "\n- - - - - - - - - - - - - - " << std::endl;
}