#include<stdio.h>
#include<stdlib.h>

int arr[] = {1, 3, 6, 8, 11, 17, 28, 56, 123, 134};

int binsearch(int arr[], int size, int element);
int binsearchBook(int x, int v[], int n);

int main(){
   int pos = binsearch(arr, 10, 28);
   // int pos = binsearchBook(28, arr, 10);
    if(pos == -1){
        printf("Element not found\n");
    }
    else{
        printf("Element found at position %d\n", pos);
    }
}


int binsearch(int arr[], int size, int element){
    int start = 0;
    int end = size - 1;
    int mid ;
    for(mid = (start + end) / 2; start <= end && element != arr[mid]; mid = (start + end) / 2){
        if( element > arr[mid]){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    if(element == arr[mid]){
        return mid;
    }
    return -1;
}


int binsearchBook(int x, int v[], int n){
    int low, high, mid;
    
    low = 0;
    high = n - 1;
    while(low <= high){
        mid = (low + high ) / 2;
        if(x < v[mid])
            high = mid - 1;
        else if ( x > v[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}
