#include <stdio.h>
#include <cmath>

extern int num;

int func(){
    // Finds that n = 10 based on the global definition in main, then finds that itis 15 after it was increased in the local scope of main
    return pow(num, 2);
}
