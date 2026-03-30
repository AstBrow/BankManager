#include <iostream>
#include <string>
#include <cstdlib>
#include <stdexcept>
#include "Account.h"

Account::Account (double balance, int ownerID, std::string typeAcc, int accountNumber) 
{
    this->accountNumber = accountNumber;

    if (balance < 0) 
    {
        throw std::invalid_argument("Error: The balance cannot be negative.");
    }
    this->balance = balance;

    this->ownerID = ownerID;

    if (typeAcc != "Debit" && typeAcc != "Credit") 
    {
        throw std::invalid_argument("Error: Invalid account type");
    }
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
    std::cout << "\n[- Account number: " << getAccountNumber() << std::endl;
    std::cout << "\n[- Balance: " << getBalance() << std::endl;
    std::cout << "\n[- Owner ID: " << getOwnerID()  << std::endl;
    std::cout << "\n[- Type account: " << getTypeAcc() << std::endl;
    std::cout << "\n- - - - - - - - - - - - - - " << std::endl;
}