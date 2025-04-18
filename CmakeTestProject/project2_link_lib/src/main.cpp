#include "main.h"

#define __DLL_EXPORT_USING__
#include "dynamiclib.h"


int main(){
    std::cout << "-------------------------------------\n";
    std::cout << "this is project2 cmake example for link dynamic library \n\n";
    std::cout << "using api1::call(): " << api1::getins().call();
    std::cout << "using api2::call(): " << api2::getins().call();

    dynamiclib::DLLEXPORT dll;
    std::cout << dll.fgetString() << "\n";
    std::cout << "-------------------------------------\n";

    std::cout << "\nPress any key to exit!\n";
    std::getchar();
    return 0;
}
