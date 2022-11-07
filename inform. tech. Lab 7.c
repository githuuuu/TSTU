/*Lab №7*/
#include <stdio.h>
#include <math.h>
void root(float a, float b, float c);

int main(){
float x, a=2, b=-16, c=30, d, x1, x2;
root(a,b,c);
}

void root(float a, float b, float c){
float d=0, x1=0, x2=0;
d=pow(b,2)-4*a*c;
if(d<0){
    printf("no solution");
    return;
}
x1=(-b+sqrt(d))/(2*a);            
x2=(-b-sqrt(d))/(2*a);
printf("X1: %f X2: %f", x1, x2);
return;
}
