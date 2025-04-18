#include "main.h"


#include "staticlib1.h"
#include "staticlib2.h"

int main(){
    std::cout << "-------------------------------------\n";
    std::cout << "this is project3 camke example for link static library \n\n";
    std::cout << "using api1::call(): " << api1::getins().call();
    std::cout << "using api2::call(): " << api2::getins().call();

    std::cout <<staticlib1::getString() << "\n";
    std::cout << staticlib2::getString() << "\n";
    std::cout << "-------------------------------------\n";
    
    std::cout << "\nPress any key to exit!\n";
    std::getchar();
    return 0;
}
