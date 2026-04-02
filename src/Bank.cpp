#include <iostream>
#include <vector>
#include <fstream>
#include <assert.h>
#include <stdexcept>
#include <exception>
#include <thread>
#include <chrono>
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

void Bank::debuggMenu () 
{
    std::cout << "[DEBUG] Enter the code to access the debug menu: " << std::endl;
    int code;
    std::cin >> code;
    
    if (code == 3434)
    {
        int err;
        std::cout << "[DEBUG] Choose type error: [1] - AccountNumber | [2] - ClientID | [3] - Save-Load options " << std::endl;
        std::cin >> err;
        if (err == 1) 
        {
            nextAccountNumber++;
        }
        else if (err == 2) 
        {
            nextClientID++;
        }
        else if (err == 3) 
        {
            std::cout << "[DEBUG] Force: [1] Load / [2] Save: ";
            int chos;
            std::cin >> chos;

            if (chos == 1) 
            {
                    std::cout << "[DEBUG] Select a parameter: " << std::endl;
                    std::cout << "  [1] - Load counters" << std::endl;
                    std::cout << "  [2] - Load Clients" << std::endl;
                    std::cout << "  [3] - Load Accounts" << std::endl;
                    std::cout << "  --> ";
                    int choose;
                    std::cin >> choose;

                try 
                {
                    if (choose == 1) 
                    {
                        std::cout << "[DEBUG] Loading Counters.." << std::endl;
                        loadCounters();
                        std::this_thread::sleep_for(std::chrono::seconds(1));
                        std::cout << "[DEBUG] Succsess." << std::endl;
                    }
                    else if (choose == 2) 
                    {
                        std::cout << "[DEBUG] Loading Clients.." << std::endl;
                        loadClients();
                        std::this_thread::sleep_for(std::chrono::seconds(1));
                        std::cout << "[DEBUG] Succsess." << std::endl;
                    }
                    else if (choose == 3) 
                    {
                        std::cout << "[DEBUG] Loading Accounts.." << std::endl;
                        loadAccounts();
                        std::this_thread::sleep_for(std::chrono::seconds(1));
                        std::cout << "[DEBUG] Succsess." << std::endl;
                    }
                    else;
                }
                catch (const std::exception& e) 
                {
                    std::cout << e.what();
                }
            }
            else if (chos == 2) 
            {
                std::cout << "[DEBUG] Select a parameter: " << std::endl;
                std::cout << "  [1] - Save counters" << std::endl;
                std::cout << "  [2] - Save Clients" << std::endl;
                std::cout << "  [3] - Save Accounts" << std::endl;
                std::cout << "  --> ";
                int choose;
                std::cin >> choose;

                try 
                {
                    if (choose == 1) 
                    {
                        std::cout << "[DEBUG] Saving Counters.." << std::endl;
                        saveCounters();
                        std::this_thread::sleep_for(std::chrono::seconds(1));
                        std::cout << "[DEBUG] Succsess." << std::endl;
                    }
                    else if (choose == 2) 
                    {
                        std::cout << "[DEBUG] Saving Clients.." << std::endl;
                        saveClients();
                        std::this_thread::sleep_for(std::chrono::seconds(1));
                        std::cout << "[DEBUG] Succsess." << std::endl;
                    }
                    else if (choose == 3) 
                    {
                        std::cout << "[DEBUG] Saving Accounts.." << std::endl;
                        saveAccounts();
                        std::this_thread::sleep_for(std::chrono::seconds(1));
                        std::cout << "[DEBUG] Succsess." << std::endl;
                    }
                    else;
                }
                catch (const std::exception& e) 
                {
                    std::cout << e.what();
                }
            }
            else;
        }
        else;
    }
    else;
}

// Save-Load

void Bank::saveCounters () 
{
    std::ofstream file ("C:\\vs code\\BankManager\\data\\Counters.txt");
    if (!file.is_open()) 
    {
        throw std::runtime_error("Error: failed to open file.");
    }

    file << nextClientID << " " << nextAccountNumber;

    file.close();
}

void Bank::loadCounters () 
{
    std::ifstream file ("C:\\vs code\\BankManager\\data\\Counters.txt");
    if (!file.is_open()) 
    {
        throw std::runtime_error("Error: failed to open file.");
    }
    file.seekg(0, std::ios::end);

    if (file.tellg() == 0) 
    {
        throw std::runtime_error("Error: file is empty.");
    }
    file.seekg(0, std::ios::beg);

    file >> nextClientID >> nextAccountNumber;

    file.close();
}

void Bank::saveClients () 
{
    std::ofstream file ("C:\\vs code\\BankManager\\data\\Clients.txt");

    if (!file.is_open()) 
    {
        throw std::runtime_error("Error: failed to open file.");
    }

    for (int i = 0; i < Clients.size(); i++) 
    {
        file << Clients[i].getName() << " " << Clients[i].getPassport() 
          << " " << Clients[i].getAge() << " " << Clients[i].getID() << "\n";
    }

    file.close();
}

void Bank::loadClients () 
{
    std::ifstream file ("C:\\vs code\\BankManager\\data\\Clients.txt");

    if (!file.is_open()) 
    {
        throw std::runtime_error("Error: failed to open file.");
    }
    file.seekg(0, std::ios::end);

    if (file.tellg() == 0) 
    {
        throw std::runtime_error("Error: file is empty.");
    }
    file.seekg(0, std::ios::beg);

    std::string temp_name, temp_passport;
    int temp_age, temp_id;

    while (file >> temp_name >> temp_passport >> temp_age >> temp_id) 
    {
        Client clientAdd(temp_name, temp_passport, temp_age, temp_id);
        Clients.push_back(clientAdd);
    }

    file.close();
}

void Bank::saveAccounts () 
{
    std::ofstream file ("C:\\vs code\\BankManager\\data\\Accounts.txt");

    if (!file.is_open()) 
    {
        throw std::runtime_error("Error: failed to open file");
    }

    for (int i = 0; i < Accounts.size(); i++) 
    {
        if (Accounts[i]->getTypeAcc() == "Debit") 
        {
            file << Accounts[i]->getBalance() << " " << Accounts[i]->getOwnerID() 
              << " " << Accounts[i]->getTypeAcc() << " " << Accounts[i]->getAccountNumber() << "\n";
        }
        else 
        {
            CreditAccount* credit = dynamic_cast<CreditAccount*>(Accounts[i]);

            file << credit->getBalance() << " " << credit->getOwnerID() 
              << " " << credit->getTypeAcc() << " " << credit->getCreditLimit() 
              << " " << Accounts[i]->getAccountNumber() << "\n";
        }
    }

    file.close();
}

void Bank::loadAccounts () 
{
    std::ifstream file ("C:\\vs code\\BankManager\\data\\Accounts.txt");

    if (!file.is_open()) 
    {
        throw std::runtime_error("Error: failed to open file.");
    }
    file.seekg(0, std::ios::end);

    if (file.tellg() == 0) 
    {
        throw std::runtime_error("Error: file is empty.");
    }
    file.seekg(0, std::ios::beg);

    double temp_balance, temp_creditLimit;
    int temp_clientId, temp_accountNumber;
    std::string temp_type;

    while (file >> temp_balance >> temp_clientId >> temp_type) 
    {
        if (temp_type == "Credit") 
        {
            file >> temp_creditLimit >> temp_accountNumber;
            CreditAccount* openCredAcc = new CreditAccount(temp_balance, temp_clientId, temp_creditLimit, temp_accountNumber);
            Accounts.push_back(openCredAcc);
        }
        else 
        {
            file >> temp_accountNumber;
            DebitAccount* openCredAcc = new DebitAccount(temp_balance, temp_clientId, temp_accountNumber);
            Accounts.push_back(openCredAcc);
        }
    }

    file.close();
}

void Bank::saveAll () 
{
    try 
    {
        std::cout << "Saving counters.." << std::endl;
        saveCounters();

        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Saving Clietns.." << std::endl;
        saveClients();

        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Saving Accounts.." << std::endl;
        saveAccounts();

        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Succsess." << std::endl;
    }
    catch (const std::exception& e) 
    {
        std::cout << e.what();
        std::cout << "\nData may not have been saved correctly." << std::endl;
    }
}
  
void Bank::loadAll () 
{
    std::ifstream test("C:\\vs code\\BankManager\\data\\Counters.txt");
    if (!test.is_open()) 
    {
        std::cout << "First launch: no save files found. Starting fresh.\n";
        nextClientID = 1;
        nextAccountNumber = 1000;
        return;
    }
    test.close();

    try 
    {
        std::cout << "Loading counters.." << std::endl;
        loadCounters();

        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Loading Clients.." << std::endl;
        loadClients();

        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Loading Accounts.." << std::endl;
        loadAccounts();

        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Succsess." << std::endl;

    }
    catch (const std::exception& e) 
    {
        std::cout << e.what();
        std::cout << "Starting with fresh data.\n";
        
        nextClientID = 1;
        nextAccountNumber = 1000;
        Clients.clear();
        for (int i = 0; i < Accounts.size(); i++) delete Accounts[i];
        Accounts.clear();
    }
}
// end Save-Load

Bank::Bank () 
{
    loadAll();
}

Bank::~Bank () 
{
    saveAll();

    for (int i = 0; i < Accounts.size(); i++) 
    {
        delete Accounts[i];
    }
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