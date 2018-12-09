#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>


#define MAXOP  100
#define NUMBER '0'

int getop(char []);
void push(double);
double pop(void);
int getLine(char s[], int lim);


int main(){
    int type;
    double op2;
    char s[MAXOP];
    while((type = getop(s)) != EOF){
        switch(type){
            case NUMBER:
                printf("Got %s\n",s);
                push(atof(s));
                break;
            case '+':
                printf("Got %c \n",'+');
                push(pop() + pop());
                break;
            case '*':
                printf("Got %c \n",'*');
                push(pop() * pop());
                break;
            case '-':
                printf("Got %c \n",'-');
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                printf("Got %c \n",'/');
                op2 = pop();
                if(op2 != 0.0){
                    push(pop() - op2);
                }
                else
                    printf("error: zero divisor\n");
                break;
            case '\n':
                printf("Got newline \n");
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}


#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f){
    printf("pushed %f\n",f);
    if(sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full , can't push %g\n", f);
}


double pop(void){
    printf("pop %f\n",val[sp - 1]);
    if(sp > 0)
        return val[--sp];
    else{
        printf("error: stack empty\n");
        return 0.0;
    }
}

#define MAXLEN 1000
int ln = 0;
char line[MAXLEN];

int getop(char s[]){
    int i,c;
    int current = 0;
    
    if(line[ln] == '\0'){
        if(getLine(line, MAXLEN) == 0){
            return EOF;
        }
        else
            ln = 0;
    }
    while((s[0] = c = line[ln++]) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if(!isdigit(c) && c != '.')
        return c;
    i = 0;
    if(isdigit(c))
        while(isdigit(s[++i] = c = line[ln++]))
        ;
    if(c == '.')
        while(isdigit(s[++i] =  c = line[ln++]))
        ;
    s[--i] = '\0';
    ln--;
    return NUMBER;
}



/* getline: read a line into s, return length */
int getLine(char s[], int lim)
{
        int c, i;

        for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
                s[i] = c;
        if (c == '\n') {
                s[i] = c;
                ++i;
        }
        s[i] = '\0';
        return i;
}
