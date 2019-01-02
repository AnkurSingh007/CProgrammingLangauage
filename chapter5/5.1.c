#include<ctype.h>

int getch(void)
void ungetch(int)

int main(){
	
    return 0;
}

int getint(int *pn){
	int c, sign;
	while(isspace(c = getch()));
	if(!isdigit(c) && c != EOF && c != '+' && c != '-'){
		ungetch(c);
		return 0;
	}
	
	sign = (c == '-') ? -1 : 1;
	if(c == '+' || c == '-')
		c = getch();
	for(*pn = 0; isdigit(c) ; c = getch()){
		*pn = 10 * *pn + (c - '0');
	if(isdigit(c) && c == '+' || c == '-'){
		ungetch(c);
		return 0;
	}
	*pn *= sign;
	if(c != EOF){
		ungetch(c);
	return c;
}



#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;


int getch(void){
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungietch(int c){
    if(bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
