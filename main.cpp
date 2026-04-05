#include <iostream>
#include <string>
#include "Bank.hpp"

int main () 
{
    Bank bank;
    int choise;
    
    do 
    {
        std::cout << "\n -!== BANK MANAGER v1.0 ==!-" << std::endl;
        std::cout << "\n - - All Actions - -" << std::endl;
        std::cout << "[1] Add client\n";
        std::cout << "[2] Open account\n";
        std::cout << "[3] Deposit\n";
        std::cout << "[4] Withdraw\n";
        std::cout << "[5] Transfer\n";
        std::cout << "[6] Show all clients\n";
        std::cout << "[7] Show client accounts\n";
        std::cout << "[8] Show account info\n";
        std::cout << "[9] Show client info\n";
        std::cout << "[10] Close account\n";
        std::cout << "[0] Exit\n"; 
        std::cout << "Select an action: ";

        std::cin >> choise;
        try 
        {
            if (choise == 1) // add client
            {
                std::string name, passport;
                int age;

                std::cout << "\n| Add client |" << std::endl;

                std::cout << "+ Enter your name -> ";
                std::cin >> name;

                std::cout << "\n+ Enter your passport -> ";
                std::cin >> passport;

                std::cout << "\n+ Enter your age -> ";
                std::cin >> age;

                bank.addClient(name, passport, age);
            }
            else if (choise == 2) //open account
            {
                double balance, creditlimit = 0;
                int clientID;
                std::string type;

                std::cout << "\n| Open account |" << std::endl;

                std::cout << "\n+ Enter client's ID -> ";
                std::cin >> clientID;

                std::cout << "+ Enter card balance -> ";
                std::cin >> balance;


                std::cout << "\n+ Enter a type your card -> "; // Credit or Debit
                std::cin >> type;

                if (type == "Credit") 
                {
                    std::cout << "\nEnter your card's credit limit -> ";
                    std::cin >> creditlimit;
                }

                bank.openAccount(balance, clientID, type, creditlimit);
                
            }
            else if (choise == 3)  // deposit
            {
                int accountNumber;
                double amount;

                std::cout << "\n| Deposit |" << std::endl;
                std::cout << "+ Enter your account number -> ";
                std::cin >> accountNumber;

                std::cout << "\n+ Enter amount for deposit -> ";
                std::cin >> amount;

                bank.deposit(accountNumber, amount);
            }
            else if (choise == 4) // withdraw
            {
                int accountNumber;
                double amount;

                std::cout << "\n| Withdraw |" << std::endl;
                std::cout << "+ Enter your account number -> ";
                std::cin >> accountNumber;

                std::cout << "\n+ Enter amount for withdraw -> ";
                std::cin >> amount;

                bank.withdraw(accountNumber, amount);
            }
            else if (choise == 5) // transfer
            {
                int fromAccNum, toAccNum;
                double amount;

                std::cout << "\n| Transfer |" << std::endl;
                std::cout << "+ Enter the account number to be debited -> ";
                std::cin >> fromAccNum;

                std::cout << "\n+ Enter the account number to be deposit -> ";
                std::cin >> toAccNum;

                std::cout << "\n+ Enter the transfer amount -> ";
                std::cin >> amount;

                bank.transfer(fromAccNum, toAccNum, amount);
            }
            else if (choise == 6) // show all clients
            {
                std::cout << "\n| Show all clients |" << std::endl;
                bank.showAllClients();
            }
            else if (choise == 7) // show client accounts
            {
                int clientID;

                std::cout << "\n| Show client accounts |" << std::endl;

                std::cout << "+ Enter client's ID -> ";
                std::cin >> clientID;

                bank.showClientAccounts(clientID);
            }
            else if (choise == 8) // show account info
            {
                int accountNumber;

                std::cout << "\n| Show account info |" << std::endl;

                std::cout << "+ Enter your account number -> ";
                std::cin >> accountNumber;

                if (!bank.showAccountByNumber(accountNumber)) 
                {
                    std::cout << "Error: Account with this number not found." << std::endl;
                }
            }
            else if (choise == 9) // Show client info
            {
                int clientID;

                std::cout << "\n| Show client info |" << std::endl;

                std::cout << "+ Enter client's ID -> ";
                std::cin >> clientID;

                if (!bank.showClientByID(clientID)) 
                {
                    std::cout << "Error: Client with this ID not found." << std::endl;
                }
                
            }
            else if (choise == 10) // Close account 
            {
                int accountNumber;

                std::cout << "\n| Close account |" << std::endl;

                std::cout << "Enter your account number -> ";
                std::cin >> accountNumber;

                bank.closeAccount(accountNumber);
            }
            else if (choise == 0) // exit
            {
                std::cout << "\n| Exit |" << std::endl;
                std::cout << "Closes for programm.." << std::endl;
                break;
            }
            else if (choise == -20)
            {
                std::cout << "\n | DEBUG MENU (only develope) |" << std::endl;
                bank.debuggMenu(); 
            }
            else 
            {
                std::cout << "/nIncorrect choise. Try again." << std::endl;
            }
        } 
        catch (const std::exception &e) 
        {
            std::cout << e.what();
        }

    } while (true);

    return 0;
}
