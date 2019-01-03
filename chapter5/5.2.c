#include<ctype.h>
#include<stdlib.h>
#include<stdio.h>

#define BASE 10

int getch(void);
void ungetch(int);
int getfloat(double * pn);

int main(){
	double a = 0;
	getfloat(&a);
    printf("Float input is %f \n", a);
    return 0;
}

int getfloat(double *pn){
    double factor = BASE;
    *pn = 0.0;
	int c, sign;
	while(isspace(c = getch()));
	if(!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.'){
		ungetch(c);
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if(c == '+' || c == '-'){
	    c = getch();
	}
	for(; isdigit(c) ; c = getch())
		*pn = factor * *pn + (c - '0');
	if(!isdigit(c) && c == '.'){
		 c = getch();
	}
    for(; isdigit(c) ; c = getch()){
		*pn = *pn + (c - '0') / factor;
		factor *= 10.0;
		}
	*pn *= sign;
	if(c != EOF){
		ungetch(c);
	    return c;
    }
}



#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;


int getch(void){
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c){
    if(bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
