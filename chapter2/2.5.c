#include<stdio.h>
#include<stdlib.h>

#define SIZE 100
#define MAX_ASCII_CHARS 256

int any(char s1[], char s2[]);
void populate_alphabets_table(char s2[], int alphabets[]);
int first_match_position(char s1[], int alphabets[]);

int main(){
    char s1[SIZE];
    char s2[SIZE];
    int position = -1;
    scanf("%s", s1);
    scanf("%s", s2);
    position = any(s1, s2);
    printf("string 1 is %s, string 2 is %s.\nPosition of first occurance is %d\n", s1, s2, position);
}


int any(char s1[], char s2[]){
    int alphabets[MAX_ASCII_CHARS];
    populate_alphabets_table(s2, alphabets);
    return first_match_position(s1, alphabets);
}

void populate_alphabets_table(char s2[], int alphabets[]){
    int i = 0;
    for(i = 0; i < MAX_ASCII_CHARS; i++){
        alphabets[i] = 0;
    }
    for(i = 0 ; s2[i] != '\0'; i++){
        alphabets[s2[i]]++;
    }
}



int first_match_position(char s1[], int alphabets[]){
    int i = 0; 
    for(i = 0; s1[i] != '\0'; i++){
        if(alphabets[s1[i]] > 0){
            return i;
        }
    }
    return -1;
}
