#pragma once
#include <iostream>
#include "Account.h"

class CreditAccount : public Account 
{
 private:
    double creditLimit = 0;

 public:
    CreditAccount (double balance, int ownerID, double creditLimit);

    bool withdraw (double amount);

    double getCreditLimit () const;
};