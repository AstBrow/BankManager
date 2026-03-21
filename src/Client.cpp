#include "Client.h"
#include <iostream>
#include <string>
#include <assert.h>

int lastID = 0; // Временная переменная, впоследующем будет файл сохранения.

Client::Client (std::string name, std::string passport, int age) 
{
    this->id = lastID + 1;
    
    assert (name.length() > 2);
    this->name = name;

    // добавить проверку что таких данных паспорта нет в системе + проверка что серия и номер это цифры.
    assert (passport.length() == 10);
    this->passport = passport;

    assert (age >= 14);
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
