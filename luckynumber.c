#include<stdio.h>
#define SIZE 6
void sum (int arr[]);

int main(){
int r;
int array[SIZE] = { 1, 2, 0, 0, 0, 3};
sum(array);
}

void sum (int arr[]){
int i=0, s=0, s2=0, r=0;
while(i<SIZE/2){
    s+=arr[i];
    i++;
}
while(i<SIZE){
    s2+=arr[i];
    i++;
}
if(s==s2)
    printf("Number is lucky");
else
    printf("Number isn't lucky");
}
