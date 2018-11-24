#include<stdio.h>
#include<stdlib.h>

unsigned invert(unsigned x, int p , int n);

int main(){
    unsigned x;
    int p, n;
    printf("Enter x: \n");
    scanf("%d", &x);
    printf("Enter p: \n");
    scanf("%d", &p);
    printf("Enter n: \n");
    scanf("%d", &n);
    printf("Answer is %d\n", invert(x, p, n));
}


unsigned invert(unsigned x, int p , int n){
    return x ^ ((~(~0 << n)) << (p - n + 1));
}
