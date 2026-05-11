#include <iostream>
#include <memory>
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
    for (const auto& account : Accounts) 
    {
        if (account->getAccountNumber() == accountNumber) 
        {
            account->showInfo();
            return true;
        }
    }
    return false;
}

int Bank::findClientIndex(int clientID) 
{
    for (size_t i = 0; i < Clients.size(); ++i) 
    {
        if (Clients[i].getID() == clientID) return i;
    }
    return -1;
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
    for (const auto& client : Clients) 
    {
        if (client.getID() == id) return false;
    }
    return true;
}

bool Bank::uniquenessCheckPassport (std::string passport) 
{
    for (const auto& client : Clients) 
    {
        if (client.getPassport() == passport) return false;
    }
    return true;
}

bool Bank::uniquenessCheckAccNum (int accountNum) 
{
    for (const auto& account : Accounts) 
    {
        if (account->getAccountNumber() == accountNum) return false;
    }
    return true;
}

void Bank::debuggMenu () 
{
    std::cout << "\n[DEBUG] Enter the code to access the debug menu: ";
    int code;
    std::cin >> code;
    
    if (code == 3434)
    {
        int err;
        std::cout << "[DEBUG] Choose type error: " << std::endl;
        std::cout << "  [1] - AccountNumber" << std::endl;
        std::cout << "  [2] - ClientID" << std::endl;
        std::cout << "  [3] - Save-Load options" << std::endl;
        std::cout << "  --> ";

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
            std::cout << "[DEBUG] Force : " << std::endl;
            std::cout << "  [1] - Load" << std::endl;
            std::cout << "  [2] - Save" << std::endl;
            std::cout << "  [3] - Delete" << std::endl;
            std::cout << "  --> ";
            int chos;
            std::cin >> chos;

            if (chos == 1) 
            {
                    std::cout << "[DEBUG] Select a parameter: " << std::endl;
                    std::cout << "  [1] - Load counters" << std::endl;
                    std::cout << "  [2] - Load clients" << std::endl;
                    std::cout << "  [3] - Load accounts" << std::endl;
                    std::cout << "  [4] - Load all data" << std::endl;
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
                    else if (choose == 4) 
                    {
                        std::cout << "[DEBUG] Loading all.." << std::endl;
                        loadAll();
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
                std::cout << "  [2] - Save clients" << std::endl;
                std::cout << "  [3] - Save accounts" << std::endl;
                std::cout << "  [4] - Save all data" << std::endl;
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
                    else if (choose == 4) 
                    {
                        std::cout << "[DEBUG] All saving.." << std::endl;
                        saveAll();
                    }
                    else;
                }
                catch (const std::exception& e) 
                {
                    std::cout << e.what();
                }
            }
            else if (chos == 3) 
            {
                std::cout << "[DEBUG] Delete all data. " << std::endl;

                std::cout << "Are you sure you want to delete all data?" << std::endl;
                std::cout << "[Y / N] : ";
                char answ;
                std::cin >> answ;

                if (answ == 'Y' || answ == 'y') 
                {
                    deleteAll();
                    loadAll();
                }
                else;
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

    for (const auto& client : Clients) 
    {
        file << client.getName() << " " << client.getPassport() 
          << " " << client.getAge() << " " << client.getID() << "\n";
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

    for (const auto& account : Accounts) 
    {
        if (account->getTypeAcc() == "Debit") 
        {
            file << account->getBalance() << " " << account->getOwnerID() 
              << " " << account->getTypeAcc() << " " << account->getAccountNumber() << "\n";
        }
        else 
        {
            CreditAccount* credit = dynamic_cast <CreditAccount*> (account.get());

            file << credit->getBalance() << " " << credit->getOwnerID() 
              << " " << credit->getTypeAcc() << " " << credit->getCreditLimit() 
              << " " << account->getAccountNumber() << "\n";
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
        return;
    }
    file.seekg(0, std::ios::beg);

    double temp_balance, temp_creditLimit;
    int temp_clientId, temp_accountNumber;
    std::string temp_type;
    bool isAccountLoad = false;

    while (file >> temp_balance >> temp_clientId >> temp_type) 
    {
        if (temp_type == "Credit") 
        {
            isAccountLoad = true;
            file >> temp_creditLimit >> temp_accountNumber;
            Accounts.push_back(std::make_unique<CreditAccount>(temp_balance, temp_clientId, temp_creditLimit, temp_accountNumber, isAccountLoad));
            isAccountLoad = false;
        }
        else 
        {
            file >> temp_accountNumber;
            Accounts.push_back(std::make_unique<DebitAccount>(temp_balance, temp_clientId, temp_accountNumber));
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
        std::cout << "Success." << std::endl;
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
        std::cout << "Success." << std::endl;

    }
    catch (const std::exception& e) 
    {
        std::cout << e.what();
        std::cout << "\nStarting with fresh data.\n";
        
        nextClientID = 1;
        nextAccountNumber = 1000;
        Clients.clear();
        Accounts.clear();
    }
}
// end Save-Load

void Bank::deleteAll () 
{
    std::cout << "Delete clietns.." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::ofstream file ("C:\\vs code\\BankManager\\data\\Clients.txt");
    file.close();

    std::cout << "Delete accounts.." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::ofstream file2 ("C:\\vs code\\BankManager\\data\\Accounts.txt");

    file2.close();

    std::cout << "Success." << std::endl;
}

Bank::Bank () 
{
    loadAll();
}

Bank::~Bank () 
{
    saveAll();
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
    std::cout << "Сlient added successfully." << std::endl;
    Clients.push_back(clientAdd);
}

void Bank::removeClient (int clientID) 
{
    int idx = findClientIndex(clientID);

    if (idx == -1) 
    {
        throw std::runtime_error("Error: Client with this ID not found");
    }

    for (const auto& account : Accounts) 
    {
        if (account->getOwnerID() == clientID) 
        {
            throw std::runtime_error("Error: Cannot delete client with open accounts. Close all accounts first.");
        }
    }

    Clients.erase(Clients.begin() + idx);
    std::cout << "\nClient ID " << clientID << " removed successfully." << std::endl;
}


void Bank::openAccount (double balance, int clientID, std::string type, double creditLimit) 
{
    if (uniquenessCheckID(clientID)) 
    {
        throw std::runtime_error("Erorr: Client with this ID not found");
    }

    int i = findClientIndex(clientID);

    if (type == "Credit" || type == "credit") 
    {
        if (Clients[i].getAge() < 18) 
        {
            throw std::runtime_error("Error: You cannot open a credit account until you are 18 years old.");
        }

        if (!uniquenessCheckAccNum(nextAccountNumber)) 
        {
            throw std::runtime_error("Error: An account with this number already exists.");
        }

        int accountNumber = nextAccountNumber;
        nextAccountNumber++;

        std::cout << "Account opened successfully." << std::endl;
        Accounts.push_back(std::make_unique<CreditAccount>(balance, clientID, creditLimit, accountNumber));
    }
    else if (type == "Debit" || type == "debit")
    {
        if (!uniquenessCheckAccNum(nextAccountNumber)) 
        {
            throw std::runtime_error("Error: An account with this number already exists.");
        }
        int accountNumber = nextAccountNumber;
        nextAccountNumber++;

        std::cout << "Account opened successfully." << std::endl;
        Accounts.push_back(std::make_unique<DebitAccount>(balance, clientID, accountNumber));
    }
    else 
    {
        throw std::runtime_error("Error: Incorrect account type.");
    }
}

void Bank::closeAccount (int accountNumber) 
{
    int i = findIterByAccountNumber(accountNumber);
    if (i == -1) 
    {
        throw std::runtime_error("Error: An account with this number does not exist.");
    }
    Accounts.erase(Accounts.begin() + i);
    std::cout << "Account successfully closed" << std::endl;
}

void Bank::deposit (int accountNumber, double amount) 
{
    int i = findIterByAccountNumber(accountNumber);
    if (i == -1) 
    {
        throw std::runtime_error("Error: An account with this number does not exist.");
    }
    Accounts[i]->deposit(amount);
    std::cout << "Deposit of "<< amount << " was successful." << std::endl;
}

void Bank::withdraw (int accountNumber, double amount) 
{
    int i = findIterByAccountNumber(accountNumber);
    if (i == -1) 
    {
        throw std::runtime_error("Error: An account with this number does not exist.");
    }

    if (!Accounts[i]->withdraw(amount)) 
    {
        throw std::runtime_error("Error: There are insufficient funds in the account.");
    }
    std::cout << "Withdrawal of "<< amount << " was successful." << std::endl;
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

    if (!Accounts[itFrom]->withdraw(amount)) 
    {
        throw std::runtime_error("Error: There are insufficient funds in the account.");
    }
    std::cout << "From the account " << fromAccNum << " withdrawn " << amount << std::endl;

    Accounts[itTo]->deposit(amount);
    std::cout << "To the account " << toAccnum << " deposited " << amount << std::endl;
}

void Bank::showAllClients () 
{
    std::cout << "\n = = = ALL CLIENTS = = =" << std::endl;

    int i = 1;
    for (const auto& client : Clients) 
    {
        std::cout << "-- Client #" << i++ << std::endl;
        std::cout << "Name: " << client.getName() << std::endl;
        std::cout << "ID: " << client.getID() << std::endl;
        std::cout << "Age: " << client.getAge() << std::endl;
        std::cout << "- - - - - - - - " << std::endl;
    }
}

void Bank::showClientAccounts (int clientID) 
{
    int itId = findClientIndex(clientID);
    std::cout << "\n= = = INFORMATION FOR CLIENT'S ACCOUNTS = = =" << std::endl;

    if (itId == -1) 
    {
        throw std::runtime_error("Error: Client with this ID not found.");
    }

    for (const auto& account : Accounts) 
    {
        if (account->getOwnerID() == Clients[itId].getID()) 
        {
            account->showInfo();
        }
    }
}