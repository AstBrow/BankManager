#include <iostream>
#include <vector>
#include <fstream>
#include <assert.h>
#include <stdexcept>
#include <exception>
#include "Bank.hpp"

bool Bank::showClientByID (int id) 
{
    for (int i = 0; i < Clients.size(); i++) 
    {
        if (Clients[i].getID() == id) 
        {
            Clients[i].showInfo();
            return true;
        }
    }
    return false;
}

bool Bank::showAccountByNumber (int accountNumber) 
{
    for (int i = 0; i < Accounts.size(); i++) 
    {
        if (Accounts[i]->getAccountNumber() == accountNumber) 
        {
            Accounts[i]->showInfo();
            return true;
        }
    }
    return false;
}

int Bank::findIterByAccountNumber (int accountNumber) 
{
    for (int i = 0; i < Accounts.size(); i++) 
    {
        if (Accounts[i]->getAccountNumber() == accountNumber) 
        {
            return i;
        }
    }
    return -1;
}

bool Bank::uniquenessCheckID (int id) 
{
    for (int i = 0; i < Clients.size(); i++) 
    {
        if (Clients[i].getID() == id) return false;
    }
    return true;
}

bool Bank::uniquenessCheckPassport (std::string passport) 
{
    for (int i = 0; i < Clients.size(); i++) 
    {
        if (Clients[i].getPassport() == passport) return false;
    }
    return true;
}

bool Bank::uniquenessCheckAccNum (int accountNum) 
{
    for (int i = 0; i < Accounts.size(); i++) 
    {
        if (Accounts[i]->getAccountNumber() == accountNum) return false;
    }
    return true;
}

void Bank::debuggingCounters () 
{
    std::cout << "[DEBUG] Enter the code to access the debug menu: " << std::endl;
    int code;
    std::cin >> code;
    
    if (code == 3434)
    {
        int err;
        std::cout << "[DEBUG] Choose type error: 1 - AccountNumber | 2 - ClientID " << std::endl;
        std::cin >> err;
        if (err == 1) 
        {
            nextAccountNumber++;
        }
        else if (err == 2) 
        {
            nextClientID++;
        }
        else 
        {
            throw std::runtime_error("Error: incorrect type error");
        }
    }
    else 
    {
        throw std::runtime_error("Error: Incorrect code for Debug menu");
    }
}



Bank::Bank () 
{
    nextAccountNumber = 1000;
    nextClientID = 1;
    // std::fstream file("C:\\vs code\\BankManager\\data\\saveIDandAccNum.txt", std::ios::binary); //binary for safety
    // assert (file.is_open());
    // file.read(reinterpret_cast<char*>(&nextClientID), sizeof(nextClientID));
    // file.read(reinterpret_cast<char*>(&nextAccountNumber), sizeof(nextAccountNumber));
    // file.close();
}

Bank::~Bank () 
{
    for (int i = 0; i < Accounts.size(); i++) 
    {
        delete Accounts[i];
    }

    // std::ofstream file("C:\\vs code\\BankManager\\data\\saveIDandAccNum.txt", std::ios::binary); //binary for safety
    // assert (file.is_open());
    // file.write(reinterpret_cast<char*>(&nextClientID), sizeof(nextClientID));
    // file.write(reinterpret_cast<char*>(&nextAccountNumber), sizeof(nextAccountNumber));
    // file.close();
}

void Bank::addClient (std::string name, std::string passport, int age) 
{
    if (!uniquenessCheckID(nextClientID)) 
    {
        throw std::runtime_error("Error: Such ID already exists.");
    }
    int id = nextClientID;
    nextClientID++;
    
    if (!uniquenessCheckPassport(passport)) 
    {
        throw std::runtime_error("Error: Such data already exists in the system.");
    }
    Client clientAdd(name, passport, age, id);
    Clients.push_back(clientAdd);
}

void Bank::openAccount (double balance, int clientID, std::string type, double creditLimit) 
{
    if (uniquenessCheckID(clientID)) 
    {
        throw std::runtime_error("Erorr: Client with this ID not found");
    }

    if (type == "Credit") 
    {
        if (Clients[clientID].getAge() < 18) 
        {
            throw std::runtime_error("Error: You cannot open a credit account until you are 18 years old.");
        }

        if (!uniquenessCheckAccNum(nextAccountNumber)) 
        {
            throw std::runtime_error("Error: An account with this number already exists.");
        }

        int accountNumber = nextAccountNumber;
        nextAccountNumber++;

        CreditAccount* openCredAcc = new CreditAccount(balance, clientID, creditLimit, accountNumber);
        Accounts.push_back(openCredAcc);
    }
    else 
    {
        if (!uniquenessCheckAccNum(nextAccountNumber)) 
        {
            throw std::runtime_error("Error: An account with this number already exists.");
        }
        int accountNumber = nextAccountNumber;
        nextAccountNumber++;

        DebitAccount* openDebAcc = new DebitAccount(balance, clientID, accountNumber);
        Accounts.push_back(openDebAcc);
    }
}

void Bank::closeAccount (int accountNumber) 
{
    int i = findIterByAccountNumber(accountNumber);
    if (i == -1) 
    {
        throw std::runtime_error("Error: An account with this number does not exist.");
    }
    delete Accounts[i];
    Accounts.erase(Accounts.begin() + i);
}

void Bank::deposit (int accountNumber, double amount) 
{
    int i = findIterByAccountNumber(accountNumber);
    if (i == -1) 
    {
        throw std::runtime_error("Error: An account with this number does not exist.");
    }
    Accounts[i]->deposit(amount);
}

void Bank::withdraw (int accountNumber, double amount) 
{
    int i = findIterByAccountNumber(accountNumber);
    if (i == -1) 
    {
        throw std::runtime_error("Error: An account with this number does not exist.");
    }
    Accounts[i]->withdraw(amount);
}

void Bank::transfer (int fromAccNum, int toAccnum, double amount) 
{
    int itFrom = findIterByAccountNumber(fromAccNum);
    if (itFrom == -1) 
    {
        throw std::runtime_error("Error: An account with this number does not exist.");
    }

    int itTo = findIterByAccountNumber(toAccnum);
    if (itTo == -1) 
    {
        throw std::runtime_error("Error: An account with this number does not exist.");
    }

    Accounts[itFrom]->withdraw(amount);

    Accounts[itTo]->deposit(amount);
}

void Bank::showAllClients () 
{
    std::cout << " = = = ALL CLIENTS = = =" << std::endl;

    for (int i = 0; i < Clients.size(); i++) 
    {
        std::cout << "-- Client #" << i + 1 << std::endl;
        std::cout << "Name: " << Clients[i].getName() << std::endl;
        std::cout << "Age: " << Clients[i].getAge() << std::endl;
        std::cout << "- - - - - - - - " << std::endl;
    }
}

void Bank::showClientAccounts (int clientID) 
{
    int itId = -1;
    std::cout << "= = = INFORMATION FOR CLIENT'S ACCOUNTS = = =" << std::endl;

    for (int i = 0; i < Clients.size(); i++) 
    {
        if (Clients[i].getID() == clientID) 
        {
            itId = i;

            if (itId == -1) 
            {
                throw std::runtime_error("Error: An account with this number does not exist.");
            }

            for (int j = 0; j < Accounts.size(); j++) 
            {
                if (Accounts[j]->getOwnerID() == Clients[itId].getID()) 
                {
                    Accounts[j]->showInfo();
                }
            }
            break;
        }
    }
}