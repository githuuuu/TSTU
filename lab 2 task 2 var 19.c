#include <stdio.h>
#include <math.h>
double task1 (double y, double x);
int main(){   
    int n;
    double res, num1, num2;
            printf("Enter y : ");
            scanf("%lf", &num1);
            printf("Enter x : ");
            scanf("%lf", &num2);
            res=task1(num1, num2);
            printf("\ny=%lf\n", res);
      
}
double task1 (double y, double x){
    double r;
    if(x+y<=1 && x<0){
        r=exp(2*x)+y;
        return r;
    }
    if(pow(x,2)+pow(y,2)<=1 && x>=0){
        r=exp(2*x)+y;
        return r;
    }
    else{
        r=5*x*y;
        return r;
    }
}
