#include<stdio.h>

#define MAX_LENGTH 12
#define IN 1
#define OUT 0
int main(){
	int word_length[MAX_LENGTH + 1];
	int state = OUT ;
	int i = 0, j = 0;
	//initialize array
	for( i = 0; i < MAX_LENGTH + 1; i++){
		word_length[i] = 0;
	}
	int ch, count = 0;
	while((ch = getchar()) != EOF){
		if(ch == '\n' && ch == ' ' && ch == '\t' ){
			printf("inside if\n");
			if(state == IN){
				state = OUT;
				word_length[count]++;
				printf("printing count %d\n",count);
				count = 0;
			}
		}
		else{
			if(state == IN){
				printf("inside else if");	
				count++;
			}
			else{
				printf("inside else else");
				state = IN;
				count = 1;
			}
		}
	}
	//Still reading a word when EOF encountered?
	if(state == IN){
		word_length[count]++;
	}
	
	for( i = 0; i < MAX_LENGTH + 1 ; i++){
		putchar('\n');
		for(j =0 ; j < word_length[i]; j++){
			putchar('|');
			putchar(' ');
		}
		putchar('\n');
	}
}