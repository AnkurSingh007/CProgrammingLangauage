#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define SIZE 100

char ch[SIZE] = "-123.32E2";

double Atof(char ch[]);

int main(){
    double num = atof(ch);
    printf("Number is %f\n", num);
}

double Atof(char ch[]){
    int i = 0;
    int sign = 1;
    int exponent = 1;
    int value, power;
    for(i = 0; isspace(ch[i]);  i++);
    sign = (ch[i] == '-' ? -1 : 1);
    if(ch[i] == '+' || ch[i] == '-'){
        i++;
    }
    for(value = 0.0; isdigit(ch[i]); i++){
        value = 10.0 * value + (ch[i] - '0');
    }
    if(ch[i] == '.' || ch[i] == 'E' || ch[i] == 'e'){
        i++;
    }
    for(power = 1.0; isdigit(ch[i]); i++){
        value = 10.0 * value + (ch[i] - '0');
        power *= 10.0;
    }
    if(ch[i] == '-' || ch[i] == '+'){
        exponent = (ch[i] == '-') ? -1 : 1;
        i++;        
    }
   for(; isdigit(ch[i]); i++){
        value = 10.0 * value + (ch[i] - '0');
        if(exponent < 0){
            power *= 10.0;
        }
        else{
            power /= 10.0;
        }
    }
    return exponent == -1 ? sign * (value / power): sign * (value * power);
}
