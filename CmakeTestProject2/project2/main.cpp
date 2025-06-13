#include "common.h"
#include "common_module1.h"
#include "common_module2.h"
#include "test_module1.h"
#include "test_module2.h"

int main(){
    printf("project 2 test\n\n");
    common_module1 module1;
    module1.function1();
    module1.function2();

    common_module2 module2;
    module2.function1();
    module2.function2();

    test_module1 testmodule1;
    testmodule1.function1();
    testmodule1.function2();

    test_module2 testmodule2;
    testmodule2.function1();
    testmodule2.function2();

    printf("\nproject 2 end\n\n");
    return 0;
}