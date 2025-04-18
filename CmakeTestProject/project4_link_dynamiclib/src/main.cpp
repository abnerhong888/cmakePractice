#include "main.h"


#include "dynamiclib.h"

int main(){
    std::cout << "-------------------------------------\n";
    std::cout << "this is project4 cmake example for cmake link dynamic library lib file \n\n";
    std::cout << "using api1::call(): " << api1::getins().call();
    std::cout << "using api2::call(): " << api2::getins().call();

    std::cout << dynamiclib::getString() << "\n";
    std::cout << "-------------------------------------\n";
    
    std::cout << "\nPress any key to exit!\n";
    std::getchar();
    return 0;
}
