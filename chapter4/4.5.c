#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>


#define MAXOP  100
#define NUMBER '0'
#define STRING '1'

int getop(char []);
void push(double);
double pop(void);
double top(void);
double uniary_operator(char []);

int main(){
    int type;
    double op2;
    char s[MAXOP];
    while((type = getop(s)) != EOF){
        switch(type){
            case NUMBER:
                printf("Got %s\n",s);
                push(atof(s));
                printf("top is %f\n", top());
                break;
            case STRING:
                printf("Got %s\n", s);
                push(uniary_operator(s));
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


double uniary_operator(char s[]){
    if(strcmp(s, "sin") == 0)
        return sin(pop());
    if(strcmp(s, "cos") == 0)
        return cos(pop());
    if(strcmp(s, "exp") == 0)
        return exp(pop());
    printf("error: unknown uniary operator\n");
    return 0.0;
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

double top(void){
    if(sp >= 0){    
        return val[sp - 1];
    }
    else{
        printf("error: empty stack\n");
    }
    return 0.0;
}

void clear(void){
    sp = 0;
}

void duplicate(void){
    if(sp < MAXVAL && sp > 0){
        val[sp] = val[sp - 1];
        sp++;
    }
    else if(sp == 0){
        printf("error: stack underflow\n");
    }
    else{
        printf("error: stack overflow");
    }
}

void swap(void){
    double temp;
    if(sp == 0){
        printf("error: empty stack");
    }
    else if(sp == 1){
        printf("error: only one element present. swap not possible\n");
    }
    else{
        temp = val[sp - 1]; 
        val[sp - 1] = val[sp - 2];
        val[sp - 2] = temp;
    }
    
    
}


int getch(void);
void ungetch(int);

int getop(char s[]){
    int i,c ;
    int isalphabet = 0;
    while((s[0] = c = getch()) == ' ' || c == '\t')
    ;
    s[1] = '\0';
    if(!isalpha(c) && !isdigit(c) && c != '.')
        return c;
    i = 0;
    if(isalpha(c)){
        isalphabet = 1;
        while(isalpha(s[++i] = c = getch()))
        ;
    }
    if(isdigit(c))
        while(isdigit(s[++i] = c = getch()))
        ;
    if(c == '.')
        while(isdigit(s[++i] = c = getch()))
        ;
    s[i] = '\0';
    if(c != EOF)
        ungetch(c);
    if(isalphabet){
        return STRING;
    }
    else{
        return NUMBER;
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
