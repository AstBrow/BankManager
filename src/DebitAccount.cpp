#include <iostream>
#include "DebitAccount.h"

DebitAccount::DebitAccount(double balance, int ownerID, int accountNumber) : Account(balance, ownerID, "Debit", accountNumber)
{
    
}
