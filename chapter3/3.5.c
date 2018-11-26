#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<limits.h>

#define SIZE 100

char num[SIZE];

void itoa(int n, char num[], int b);
void reverse(char str[]);
void set_int_min(char num[], int b);

int main(){
    int n, b;
    printf("Input the number\n");
    scanf("%d",&n);
    printf("Input base: \n");
    scanf("%d",&b);
    itoa(n, num, b);
    printf("You entered %s\n", num);
}

void itoa(int n, char num[], int b){
    int i = 0;
    int sign;
    if((sign = n) < 0){
        if(n == INT_MIN){
            set_int_min(num, b);
            return;
        }
            n = -n;
    }
    do{ 
        int digit = n % b;
        if(digit < 10){
            num[i++] = digit + '0';
        }
        else{
            num[i++] = digit - 10 + 'a';
        }
        n /= b;
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

void set_int_min(char num[], int b){
    int i = 0;
    int min = INT_MIN;
    min += 1;
    unsigned temp = (-min) + 1;
    for(i = 0; temp > 0; i++){
        int digit = temp % b;
        if(digit < 10){
            num[i] = (temp % b) + '0';
        }
        else{
            num[i] = (temp % b) - 10 + 'a';
        }
        num[i] = (temp % b) + '0';
        temp /= b;
    }
    num[i++] = '-';
    num[i++] = '\0';
    reverse(num);
}
