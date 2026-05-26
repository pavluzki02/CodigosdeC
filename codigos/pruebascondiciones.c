#include <stdio.h>

int main() {
    int a=0, b=5, c=-2, d=5;
    if(a || b > 3 && !c || d-- & a++)
    {
        printf("Condition is true\n");
    } else {
        printf("Condition is false\n");
    }
    return 0;
}