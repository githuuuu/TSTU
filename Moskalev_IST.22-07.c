#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
double task1 (double y, double x);
double task2 (double x);
int main(){   
    int n;
    double res, num1, num2;
    char a='y';
    while(a=='y' || a=='Y'){
        printf"If you want to calculate:\n\nz=arcccos(y)+ln(x)\t,enter 1\n\nIf you want to calculate:\n\n     /\n    | 1+|x|\t,if x <= -6\ny = < (e^x)+1\t,if 0 < x <= 2\t,enter 2\n    | sin(x)\t,if x > 12\n     \\\n");
        scanf("%d", &n);
        if (n==1){
            printf("Enter y and x : ");
            scanf("%lf %lf", &num1, &num2);
            res=task1(num1, num2);
            printf("\ny=%lf\n", res);
        }
        if (n==2){
            printf("Enter x : ");
            scanf("%lf", &num1);
            res=task2(num1);
            printf("\ny=%lf\n", res);
        }
        printf("Run again? : y\\n");
        scanf(" %c", &a);
    }
}
double task1 (double y, double x){
    if(y>=-1 && y<=1 && x>0){
        double r;
        r=acos(y)+log(x);
        return r;
    }
    else{
        printf("input is not within the domain of the function\n");
        return 0;
    }
}

double task2 (double x){
    double r;
    if(x<=-6){
        r=1+fabs(x);
        return r;
    }
    if(0<x && x<=2){
        r=exp(x)+1;
        return r;
    }
    if(x>12){
        r=sin(x*M_PI/180);
        return r;
    }
    else{
        printf("input is not within the domain of the function\n");
        return 0;
    }
}
