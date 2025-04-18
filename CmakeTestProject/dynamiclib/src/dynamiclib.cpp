#include "dynamiclib.h"
#include <string>

START_NAMESPACE

static std::string g_str = "dynamiclib char* getString()";

char* __STDCALL__ getString(){
    return (char*)g_str.c_str();
}

END_NAMESPACE
