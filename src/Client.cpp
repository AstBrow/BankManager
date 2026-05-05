#include "Client.h"
#include <iostream>
#include <string>
#include <stdexcept>

Client::Client (std::string name, std::string passport, int age, int id) 
{
    this->id = id;
    
    if (name.length() < 2) 
    {
        throw std::invalid_argument("Error: The name must be more than 2 characters.");
    }
    this->name = name;

    // добавить проверку что таких данных паспорта нет в системе + проверка что серия и номер это цифры.
    if (passport.length() != 10) 
    {
        throw std::invalid_argument("Error: Invalid data format");
    }
    this->passport = passport;

    if (age < 14) 
    {
        throw std::invalid_argument("Error: You cannot open an account until you are 14 years old.");
    }

    if (age <= 0) 
    {
        throw std::invalid_argument("Error: Inccorect age.");
    }
    this->age = age;
}

int Client::getID () const
{
    return id;
}

std::string Client::getName () const
{
    return name;
}

std::string Client::getPassport () const
{
    return passport;
}

int Client::getAge () const 
{
    return age;
}

void Client::showInfo () 
{
    std::cout << "-- INFORMATION FOR CLIENT --" << std::endl;
    std::cout << "\n[- CLient ID: " << getID() << std::endl;
    std::cout << "\n[- Client name: " << getName() << std::endl;
    std::cout << "\n[- Client age: " << getAge()  << std::endl;
    std::cout << "\n[- Clinet passport: " << getPassport() << std::endl;
    std::cout << "\n- - - - - - - - - - - - - - " << std::endl;
}
