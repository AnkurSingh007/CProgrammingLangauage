#include<stdio.h>

void strncpy2(char *s , char * t, int n);

char str1[100];
char str2[100];

int main(){
	printf("Enter the string\n");
	scanf("%s", str1);
	strncpy2(str2, str1, 5);
	printf("after strncpy call str2 is %s\n", str2);	
}


void strncpy2(char *s , char * t, int n){
	int i = 0;
	for(; *t != '\0' && i < n ; *s++ = *t++, i++)
	;
	*s = '\0';
	return;
}
