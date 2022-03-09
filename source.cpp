#include <iostream>
#include "HugeInt.h"

int main(void)
{
    HugeInt Int1("1000000000000");
    HugeInt Int2("1000000000");


    (Int1 + Int2).printNum();



    return (0);
}
