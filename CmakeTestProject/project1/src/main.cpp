#include "main.h"
int main(){
    std::cout << "-------------------------------------\n";
    std::cout << "this is project1 cmake example  \n\n";
    std::cout << "using api1::call(): " << api1::getins().call();
    std::cout << "using api2::call(): " << api2::getins().call(); 
    std::cout << "-------------------------------------\n";
    printf("123\n");

    std::cout << "\nPress any key to exit!\n";
    std::getchar();
    return 0;
}
