#include "test_module2.h"

void test_module2::function2(){
    printf("this is func: %s in file %s\n", __FUNCTION__, __FILE__);
}