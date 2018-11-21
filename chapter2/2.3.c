#include<stdio.h>
#include<stdlib.h>


#define SIZE 100

int htoi(char s[]);
int test_hex_prefix(char s[]);
int get_token_value(char ch);

int main(){
    char s[SIZE];
    scanf("%s",s);
    int result = htoi(s);
    if(result >= 0){
        printf("%d\n", result);
    }
    return 0;
}

// converts hexadecimal string to equivalent integer
// Acceptable string contains characters 0-9 and a-f or A-F
// 0x or 0X is also accepted as prefix
// in case of invalid string -1 is returned.
// Hex integer size does not fit into int, case is not handled.

int htoi(char s[]){
    int ans = 0;
    int counter = 0;
    int has_prefix = test_hex_prefix(s);
    if(has_prefix){
        counter = 2;
    }
    while(s[counter] != '\0'){
            int token_val = get_token_value(s[counter]);
            if(token_val < 0){
                printf("Invalid character %c found in input string at position %d\n", s[counter], counter);
                return -1;
            }
            else{
                ans = ans * 16 + token_val;
            }
            counter++;
   }
   return ans;
}

int test_hex_prefix(char s[]){
    if(s[0] == '0'){
        if(s[1] == 'x' || s[1] == 'X'){
            return 1;
        }
        else{
            return 0;
        }
    }
    return 0;
}

// return integer equivalent of the character for hexadecimal character set
// in case of invalid character returns -1
int get_token_value(char ch){
    if(ch >= '0' && ch <= '9'){
        return ch - '0';
    }
    if(ch >= 'a' && ch <= 'h'){
        return ch - 'a' + 10;
    }
    return -1;
}
