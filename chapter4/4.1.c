#include<stdio.h>

#define MAXLINE 1000

int getLine(char line [], int max);

int strrindex(char source[], char searchfor[]);

char pattern[] = "ould";

/*find all lines matching pattern */

int main(){
    char line[MAXLINE];
    int found = 0;
    int rightmost_pos = -1;
    while(getLine(line, MAXLINE) > 0){
        if((rightmost_pos = strrindex(line, pattern)) >=0){
            printf("rightmost position of the pattern %s is %d\n", pattern, rightmost_pos);
            found++;
        }
    }
    return found;
}


/*getLine: get line into s, return length */
int getLine(char s[], int lim){
    int c, i;
    
    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n'){
        s[i++] = c;
    }
    if(c == '\n')
       s[i++] = c;
    s[i] = '\0';
    return i;
}

/*strrindex: return index of t in s, -1 if none*/
int strrindex(char s[] , char t[]){
    int i, j, k;
    int last_matched = -1;
    for(i = 0; s[i] != '\0'; i++){
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
        ;
        if(k > 0 && t[k] == '\0'){
            last_matched = j;
        }
   }
   return last_matched;
}
