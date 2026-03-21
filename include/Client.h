#pragma once
#include <iostream>

class Client 
{
 private:
    int id;
    int age;
    std::string name;
    std::string passport;

 public:

    Client (std::string name, std::string passport, int age);

    int getID () const;
    std::string getName () const;
    std::string getPassport () const;
    int getAge () const;

    void showInfo ();
};