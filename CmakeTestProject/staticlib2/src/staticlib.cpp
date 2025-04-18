#include "staticlib2.h"
#include <string>

#define START_NAMESPACE namespace staticlib2 {
#define END_NAMESPACE }

START_NAMESPACE

static std::string g_str = "staticlib2 char* getString()";

char* getString(){
    return (char*)g_str.c_str();
}


END_NAMESPACE

#undef START_NAMESPACE
#undef END_NAMESPACE
