#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<limits.h>

#define SIZE 100

char num[SIZE];

void itoa(int n, char num[]);
void reverse(char str[]);
void set_int_min(char num[]);

int main(){
    int n;
    printf("Input the number\n");
    scanf("%d",&n);
    itoa(n, num);
    printf("You entered %s\n", num);
}

void itoa(int n, char num[]){
    int i = 0;
    int sign;
    if((sign = n) < 0){
        if(n == INT_MIN){
            set_int_min(num);
            return;
        }
            n = -n;
    }
    do{
        num[i++] = (n % 10) + '0';
        n /= 10;
    }while(n > 0);
    if(sign < 0)
        num[i++] = '-';
    num[i++] = '\0';
    reverse(num);
}

void reverse(char str[]){
    int i, j, temp;
    for(i = 0, j = strlen(str) - 1; i <= j; i++, j--){
       temp = str[i];
       str[i] = str[j];
       str[j] = temp;
    }
}

void set_int_min(char num[]){
    int i = 0;
    int min = INT_MIN;
    min += 1;
    unsigned temp = (-min) + 1;
    for(i = 0; temp > 0; i++){
        num[i] = (temp % 10) + '0';
        temp /= 10;
    }
    num[i++] = '-';
    num[i++] = '\0';
    reverse(num);
}
