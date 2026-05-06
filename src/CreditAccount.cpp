#include <iostream>
#include <stdexcept>
#include "CreditAccount.h"

CreditAccount::CreditAccount(double balance, int ownerID, double creditLimit, int accountNumber)
     : Account(balance, ownerID, "Credit", accountNumber)
{
    if (creditLimit < 0) 
    {
        throw std::invalid_argument("Error: The credit limit cannot be negative.");
    }
    this->creditLimit = creditLimit;
}

bool CreditAccount::withdraw (double amount) 
{
    if (amount > 0) 
    {
        if (getBalance() - amount >= -creditLimit) 
        {
            setBalance(getBalance() - amount);
            return true;
        }
        else return false;
    }
    else return false;
}

double CreditAccount::getCreditLimit () const 
{
    return creditLimit;
}
