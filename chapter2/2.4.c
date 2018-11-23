#include<stdio.h>
#include<stdlib.h>

#define SIZE 100
#define MAX_ASCII_CHARS 256

void delete_matched_chars(char s1[], char s2[]);
void populate_alphabets_table(char s2 []);
void remove_chars(char s1[]);

int alphabets[MAX_ASCII_CHARS];

int main(){
    char s1[SIZE];
    char s2[SIZE];
    scanf("%s",s1);
    scanf("%s",s2);
    printf("Before operation s1 is %s and s2 is %s\n", s1, s2);
    delete_matched_chars(s1, s2);
    printf("After operation s1 is %s and s2 is %s\n", s1, s2);
}


// Delete the occurances of all the characters present in string s2 from string s1
// Only ASCII characters supported

void delete_matched_chars(char s1[], char s2[]){
    populate_alphabets_table(s2);
    remove_chars(s1);
}

void populate_alphabets_table(char s2 []){
    int i = 0;
    int j = 0;
    for(i = 0; i < MAX_ASCII_CHARS ; i++){
       alphabets[i] = 0;
    }
    while(s2[j] != '\0'){
        alphabets[s2[j]]++;
        j++;
    }
}

void remove_chars(char s1[]){
    int start = 0;
    int counter = 0;
    while(s1[counter] != '\0'){
        if(alphabets[s1[counter]] == 0){
            s1[start] = s1[counter];
            start++;
        }
        counter++;
    }
    s1[start] = '\0';
}
