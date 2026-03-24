#include <iostream>
#include <assert.h>
#include "CreditAccount.h"

CreditAccount::CreditAccount(double balance, int ownerID, double creditLimit) : Account(balance, ownerID, "Credit")
{
    assert (creditLimit >= 0);
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