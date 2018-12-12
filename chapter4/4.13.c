#include<stdio.h>
#include<string.h>

char string[] = "test string to reverse";
extern void reverse(char s[], int start, int end);
extern void swap(char s[], int start, int end);

int main(){
    int num;
    reverse(string, 0 , strlen(string) - 1);
    printf("%s\n", string);
    return 0;
}

void reverse(char s[], int start, int end){
    if(start >= end)
        return;
    swap(s, start, end);
    start++; end--;
    reverse(s, start, end);
    return;
}

void swap(char s[], int start, int end){
    int temp = s[start];
    s[start] = s[end];
    s[end] = temp;
}
