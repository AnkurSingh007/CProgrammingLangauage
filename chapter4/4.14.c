#include<stdio.h>


#define swap(t, x, y) t temp = x; x = y; y = temp;



int main(){
 float x = 10.12;
 float y = 12.11;
 swap(float, x , y);
 printf("x is %f and y is %f \n", x, y);	
}
