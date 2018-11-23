#include<stdio.h>
#include<stdlib.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main(){
    unsigned x;
    unsigned y;
    int n, p;
    printf("Enter x: \n");
    scanf("%d", &x);
    printf("Enter y: \n");
    scanf("%d", &y);
    printf("Enter n: \n");
    scanf("%d", &n);
    printf("Enter p: \n");
    scanf("%d", &p);
    unsigned answer = setbits(x,p, n, y);
    printf("Answer is %d\n", answer);
}


unsigned setbits(unsigned x, int p, int n, unsigned y){
    // create mask which set the required bits of x to zero
    unsigned mask = (~0 << (p + 1)) | ~ (~0 << (p + 1 - n));
    return  (x & mask) | ((y & ~(~0 << n)) << (p + 1 -n));
}
