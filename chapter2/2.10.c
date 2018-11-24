#include<stdio.h>
#include<stdlib.h>

#define SIZE 100

void lower(char str[]);

int main(){
    char str[SIZE];
    printf("Enter String\n");
    scanf("%s",str);
    lower(str);
    printf("Lower-case string is %s\n",str);
}


void lower(char str[]){
    int counter = 0;
    while(str[counter] != '\0'){
        str[counter] = (str[counter] - 'A' >= 0 && str[counter] - 'Z' <= 0) ? str[counter] - 'A' + 'a' : str[counter];
        counter++;
    }
}
