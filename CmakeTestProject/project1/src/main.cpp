#include "main.h"
#include "condition_var_example.h"
#include "future_async_example.h"

int main(){
    std::cout << "-------------------------------------\n";
    std::cout << "this is project1 cmake example  \n\n";
    std::cout << "using api1::call(): " << api1::getins().call();
    std::cout << "using api2::call(): " << api2::getins().call(); 


    // condition_var_example::getins().run();
    // future_async_example::getins().run();
    future_async_apply::getins().run();
    std::cout << "-------------------------------------\n";

    std::cout << "\nPress any key to exit!\n";
    std::getchar();
    return 0;
}
