#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

// This program prints the max and min range of each data type.
int main(){
	printf("Max range for char is %d\n",CHAR_MAX);
	printf("Min range for char is %d\n",CHAR_MIN);
	printf("Max range for int is %d\n",INT_MAX);
	printf("Min range for int is %d\n",INT_MIN);
    printf("Max range for long is %ld\n",LONG_MAX);
    printf("Min range for long is %ld\n",LONG_MIN);
    printf("Max range for signed char is %d\n",SCHAR_MAX);
    printf("Min range for signed char is %d\n",SCHAR_MIN);
    printf("Max range for unsigned int is %u\n", UINT_MAX);
    printf("Max range for unsigned long is %lu\n", ULONG_MAX);
    return 0;
}
