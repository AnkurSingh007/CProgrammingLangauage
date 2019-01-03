#include<stdio.h>
#include<stdlib.h>

void strcat2(char *s, char *t);
char str1[100];
char str2[100];

int main(){
	printf("Input first string\n");
	scanf("%s",str1);
	printf("Input second string\n");
	scanf("%si",str2);
	strcat2(str1, str2);
	printf("after concatenation str1 is %s\n", str1);			
}


void strcat2(char *s, char *t){
	for(;*s != '\0';s++)
	;
	for(; *t != '\0'; *s++ = *t++);
	*s = '\0';
}
