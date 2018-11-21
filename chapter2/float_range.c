#include<stdio.h>
#include<stdlib.h>
#include<float.h>


int main(){
    printf("Max size for float is %.10ef\n", FLT_MAX);
    printf("Min size for float is %.10ef\n", FLT_MIN);
    printf("Max size for double is %.10ef\n", DBL_MAX);
    printf("Min size for double is %.10ef\n", DBL_MIN);
    printf("Max size for long double is %.10LE\n", LDBL_MAX);
    printf("Min size for long double is %.10LE\n", LDBL_MIN);
}

