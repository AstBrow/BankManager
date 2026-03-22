#pragma once
#include <iostream>
#include <string>

class Account 
{
 private:
    int accountNumber = 0;
    double balance = 0;
    int ownerID = 0;
    std::string typeAcc = "unknown";

 public:
    Account (double balance, int ownerID, std::string typeAcc);

    int getAccountNumber () const;
    double getBalance () const;
    int getOwnerID () const;
    std::string getTypeAcc () const;

    void deposit (double amount);

    virtual bool withdraw (double amount);

    virtual void showInfo ();
};