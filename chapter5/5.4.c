#include<stdio.h>
#include<stdlib.h>

int strend(char *s, char *t);
char str1[100];
char str2[100];

int main(){
	printf("Input first string\n");
	scanf("%s",str1);
	printf("Input second string\n");
	scanf("%si",str2);
	if(strend(str1, str2))
		printf("%s has %s as its end string\n", str1, str2);			
	else
		printf("%s does not have %s  as its end string\n", str1, str2);
}


int strend(char *s, char *t){
	for(;*s != '\0' && *t != '\0' &&  *s != *t; s++)
	;
	if(*s == '\0')
		return 0;
	else{
		for(;*s != '\0' && *t != '\0' && *s == *t; s++, t++)
		;
		if(*s == '\0' && *t == '\0'){
			return 1;
		}
	}
	return 0;
}
