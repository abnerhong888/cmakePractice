#include "api2.h"

api2& api2::getins(){
    static api2 instance;
    return instance;
}

std::string api2::call(){
    return "this is api2::call() in common.hpp file\n";
}



