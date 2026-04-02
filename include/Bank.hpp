#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Account.h"
#include "DebitAccount.h"
#include "CreditAccount.h"
#include "Client.h"



class Bank 
{
 private:
    std::vector <Account*> Accounts;
    std::vector <Client> Clients;
    int nextClientID = 0;
    int nextAccountNumber = 0;

    bool showClientByID (int id);
    bool showAccountByNumber (int accountNumebr);

    int findIterByAccountNumber (int accountNumber);

    bool uniquenessCheckID (int id);
    bool uniquenessCheckPassport (std::string passport);
    bool uniquenessCheckAccNum (int accountNum);

    void debuggMenu ();

    void saveCounters ();
    void loadCounters ();

    void saveClients ();
    void loadClients ();

    void saveAccounts ();
    void loadAccounts ();

    void saveAll ();
    void loadAll ();


 public:
    Bank ();
    
    ~Bank ();

    void addClient (std::string name, std::string passport, int age);

    void openAccount (double balance, int clientID, std::string type, double creditLimit);

    void closeAccount (int accountNumber);

    void deposit (int accountNumber, double amount);

    void withdraw (int accountNumber, double amount);

    void transfer (int fromAccNum, int toAccnum, double amount);

    void showAllClients ();

    void showClientAccounts (int clientID);

};