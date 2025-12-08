#include<stdio.h>

int main() {
    int i, nSum;
    nSum = 0;
    for(i = 1; i <= 100; i++)
        nSum += i;
    printf("Sum=%d\n", nSum);
    return 0;
}