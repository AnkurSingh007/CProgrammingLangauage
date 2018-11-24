#include<stdio.h>
#include<stdlib.h>

unsigned rightrot(unsigned x, int n);
int get_int_size();

int main()
{
    unsigned x;
    int n;
    printf("Enter x: \n");
    scanf("%d", &x);
    printf("Enter n: \n");
    scanf("%d", &n);
    printf("Answer is %d\n", rightrot(x, n));
}

unsigned rightrot(unsigned x, int n){
    int int_size = get_int_size();
    n = n % int_size;
    unsigned right_most = x & (~0 >> (int_size - n));
    right_most = right_most << (int_size - n);
    x = x >> n;
    return x | right_most;
}

int get_int_size(){
    unsigned a = ~0;
    int count = 0;
    while(a != 0){
        a = a >> 1;
        count++;
    }
    return count;
}
