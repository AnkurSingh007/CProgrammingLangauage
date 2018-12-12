#include<stdio.h>
#include<string.h>

char string[20];
extern void itoa(int num, char s[]);

int main(){
    int num;
    printf("Enter num:\n");
    scanf("%d",&num);
    itoa(num, string);
    printf("%s\n", string);
    return 0;
}

void itoa(int num, char s[]){
    static int i;
    if(num  / 10 == 0){
       s[i++] = num + '0';
       s[i] = '\0';
       return;
    }
    if(num < 0){
        s[i++] = '-';
        num = -num;
        return;
    }    
    itoa(num / 10, s);
    s[i++] = (num % 10) + '0';
    return;
}
