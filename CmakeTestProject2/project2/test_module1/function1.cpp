#include "test_module1.h"

void test_module1::function1(){
    printf("this is func: %s in file %s\n", __FUNCTION__, __FILE__);
}