#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define SIZE 100

char s1[SIZE];
char s2[SIZE];

void expand(char s1[], char s2[]);

int main(){
    printf("Input the string\n");
    scanf("%s", s1);
    expand(s1, s2);
    printf("%s\n",s2);
}

void expand(char s1[], char s2[]){
    int i = 0;
    int j = 0;
    char first_letter, second_letter;
    int safty_count = 26; // used for non-sensible inputs like 0-A
    // skip space in s1
    for(i = 0; s1[i] != '\0' && isspace(s1[i]); i++)
    ;
    for(; s1[i] != '\0'; safty_count = 26){
        if(s1[i] != '-'){
            s2[j] = s1[i];
            i++, j++;
        }
        else{
            if(i > 0  && isalnum(s1[i - 1]) && isalnum(s1[i + 1])){
                first_letter =  s1[i - 1] + 1;//first letter has already been copied
                second_letter = s1[i + 1];
                for(;first_letter <= second_letter && safty_count >= 0; first_letter++, j++, safty_count--){
                    s2[j] = first_letter;
                }
                i += 2;
            }
            else{
                // literal meaning for leading or trailing '-'
                s2[j] = s1[i];
                i++; j++;
            }
        }
    }
    s2[j] = '\0';
}
