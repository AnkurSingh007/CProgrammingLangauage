#include<stdio.h>
#include<stdlib.h>


#define SIZE 100
char buffer[SIZE];

void print(char * c);

int main(){
    int size = 0;
    int c;
    while(size < SIZE - 1 && (c = getchar()) != '\n' && c != EOF){
        buffer[size++] = c;
    }
    buffer[size] = '\0';
    print(buffer);
    return 0;
}

void print(char * c){
    int i =0;
    while(c[i] != '\0'){
        printf("%c",c[i]);
        i++;
    }
    printf("\n");
}

