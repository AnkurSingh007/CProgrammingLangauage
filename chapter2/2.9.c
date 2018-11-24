#include<stdio.h>
#include<stdlib.h>

int bitcount(unsigned x);

int main(){
    unsigned x;
    printf("Enter x: \n");
    scanf("%d",&x);
    printf("Total number of bits set to 1 in x are %d\n", bitcount(x));
}

int bitcount(unsigned x){
    int count = 0;
    while(x != 0){
        x &= x - 1;
        count++;
    }
    return count;
}
