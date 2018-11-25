#include<stdio.h>
#include<stdlib.h>

char s[100];
char t[100];

void escape(char s[], char t[]);

int main(){
    printf("Enter one string\n");
    scanf("%s",t);
    escape(s, t);
    printf("You entered %s\n", s);
}


void escape(char s[], char t[]){
    int x = 0;
    int y = 0;
    while(t[x] != '\0'){
        switch(t[x]){
            case '\n':
                s[y++] = '\\';
                s[y++] = 'n';
                break;
            case '\t':
                s[y++] = '\\';
                s[y++] = 't';
            default:
                s[y++] = t[x]; 
        }
        x++;
    }
    s[y] = '\0';
}
