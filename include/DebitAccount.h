#pragma once
#include <iostream>
#include "Account.h"

class DebitAccount : public Account 
{
 public:
    DebitAccount(double balance, int ownerID, int accountNumber);
}; 