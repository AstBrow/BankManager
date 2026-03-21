#include <iostream>
#include "Client.h"

int main () 
{
    Client client1("Alex", "0820695930", 18);

    std::cout << client1.getID() << std::endl;
    std::cout << client1.getName() << std::endl;
    std::cout << client1.getPassport() << std::endl;
    client1.showInfo();

    return 0;
}