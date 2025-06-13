#include "common.h"
#include "common_module1.h"
#include "test_module1.h"

int main(){
    printf("project 1 test\n\n");
    common_module1 commonmodule1;
    commonmodule1.function1();
    commonmodule1.function2();

    test_module1 testmodule1;
    testmodule1.function1();
    testmodule1.function2();

    printf("\nproject 1 end\n\n");
    return 0;
}