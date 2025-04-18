#include "api1.h"

api1& api1::getins(){
    static api1 instance;
    return instance;
}

std::string api1::call(){
    return "this is api1::call() in common.hpp file\n";
}



