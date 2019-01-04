#include<stdio.h>

void strncpy2(char *s , char * t, int n);
void strncat2(char *s , char *t , int n);
int strncmp2(char *s , char *t , int n);

char str1[100];
char str2[100];

int main(){
	printf("Enter the string\n");
	scanf("%s", str1);
	printf("Enter the string\n");
	scanf("%s", str2);
	int comp = strncmp2(str1, str2, 5);
	if(comp == 0)
		printf("str1 and str2 are equal\n");
	else if(comp > 0)
		printf("str1 is lexicographically greater than str2\n");
	else if(comp < 0)
		printf("str1 is lexicographically lesser than str2\n");
	return 0;
}


void strncpy2(char *s , char * t, int n){
	int i = 0;
	for(; *t != '\0' && i < n ; *s++ = *t++, i++)
	;
	*s = '\0';
	return;
}

void strncat2(char *s , char *t, int n){
	int i = 0;
	for(; *s != '\0'; s++)
	;
	for(;i < n && *t != '\0'; *s++ = *t++, i++)
	;
	*s = '\0';
	return;
}

int strncmp2(char *s , char *t , int n){
	int i = 0;
	for(;*s == *t; s++, t++, i++){
		if(*s == '\0')
			return 0;
		if(i == n)
			return 0;
	}
	return *s - *t;
}
