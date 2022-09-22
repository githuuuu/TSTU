#include <stdio.h>
#include <stdlib.h>
void insertCol(double *arr, double *col, int j, int n){
 for(int i=0; i<n; i++){
 *(arr + i*n + j)=*(col + i);
 }
}
void fillArrE(double *arr, int n){
 for(int i=0;i<n;i++){
 for(int j=0;j<n;j++){
 if(i==j)
 *(arr + i*n + j)=1.;
 else
 *(arr + i*n + j)=0.;
 }
 }
}
void matCopy(double *arr, double *cpyto, int n){
 for(int i=0; i<n; i++){
 for(int j=0; j<n; j++){
 *(cpyto + i*n + j) = *(arr + i*n + j);
 }
 }
}
void swap(double *arr, int i, int j, int n){
 for(int k = 0; k < n; k++){
 double temp = *(arr + i*n + k);
 *(arr + i*n + k) = *(arr + j*n + k);
 *(arr + j*n + k) = temp;
 }
}
void mult(double *arr, int i, double n, int m){
 for(int j=0; j<m;j++){
 *(arr + i*m + j) *= n;

 }
}
void multMatrix(double *arr, double *arrb, int n){
 for(int i = 0; i<n;i++){
 double r = 0;
 for(int j = 0;j<n;j++){
 r += *(arrb + j) * *(arr + i*n + j);
 }
 printf("x%d is %lf\n", i+1, r);
 }
}
void arif(double *arr, int i, int j, double n, int m){
 for(int k=0; k<m;k++)
 *(arr + i*m + k) -= *(arr + j*m + k) * n;
}
double det(double *arr, int n){
 double res = 1.;
 for(int i = 0; i<n; i++){
 int m = i+1;
 while(*(arr + i*n + i)==0&&m<n){
 if(*(arr + m*n + i)!=0){
 swap(arr, i, m, n);
 res *= -1.;
 }
 m++;
 }
 if(*(arr + i*n + i)==0){
 return 0;
 }
 double z = 1 / *(arr + i*n + i);
 res *= *(arr + i*n + i);
 mult(arr, i, z, n);
 for(int j = i+1; j<n; j++){
 double t = *(arr + j*n + i);
 arif(arr, j, i, t, n);
 }
 }
 return res;
}

void gauss(double *arr, double *arrrev, int n){
 for(int i = 0; i<n; i++){
 int m = i+1;
 while(*(arr + i*n + i)==0&&m<n){
 if(*(arr + m*n + i)!=0){
 swap(arr, i, m, n);
 swap(arrrev, i, m, n);
 }
 m++;
 }
 double z = 1 / *(arr + i*n + i);
 mult(arr, i, z, n);
 mult(arrrev, i, z, n);
 for(int j = i+1; j<n; j++){
 double t = *(arr + j*n + i);
 arif(arr, j, i, t, n);
 arif(arrrev, j, i, t, n);
 }
 for(int j = i-1; j>-1; j--){
 double t = *(arr + j*n + i);
 arif(arr, j, i, t, n);
 arif(arrrev, j, i, t, n);
 }
 }
}
void hub(double *arr, double *arrb, char s, int n){
 if(s=='R'){
 double *arrrev=(double *)malloc(n * n * sizeof(double));
 fillArrE(arrrev, n);
 gauss(arr, arrrev, n);
 multMatrix(arrrev, arrb, n);
 free(arrrev);
 }
 else{
 double *temp = (double *)malloc(n * n * sizeof(double));
 matCopy(arr, temp, n);
 double tempdet=det(temp, n);
 for(int i=0; i<n; i++){
 matCopy(arr, temp, n);
 insertCol(temp, arrb, i, n);


 double o = det(temp, n);
 double r = o/tempdet;
 printf("x%d is %lf\n", i+1, r);
 }
 free(temp);
 }
}
int main()
{
 int n;
 printf("enter the dimension of matrix\n");
 scanf("%d", &n);
 if(n<1)
 return 0;
 double *arr=(double *)malloc(n * n * sizeof(double));
 double *arrb=(double *)malloc(n * sizeof(double));
 for(int i = 0; i<n;i++){
 for(int j=0;j<n;j++){
 printf("enter an element %d %d for matrix A (default 0)\n", i+1, j+1);
 double r;
 scanf("%lf", &r);
 *(arr + i*n + j)=r;
 }
 printf("enter an element %d for matrix B (default 0)\n", i+1);
 double l;
 scanf("%lf", &l);
 *(arrb + i)=l;
 }
 printf("\n");
 for(int i = 0; i<n;i++){
 for(int j=0;j<n;j++){
 printf("%lf\t", *(arr + i*n + j));
 }
 printf("%lf\n", *(arrb + i));
 }
 printf("\n");
 char s='0';
 while(s!='R'&&s!='K'){
 printf("which method would you like to use? R, K\n");
 scanf("%c", &s);
 }

 double *temp = (double *)malloc(n * n * sizeof(double));
 matCopy(arr, temp, n);
 if(det(temp, n)==0){
 free(arr);
 free(arrb);
 free(temp);
 return 0;
 }
 free(temp);
 hub(arr, arrb, s, n);
 free(arr);
 free(arrb);
 return 0;
}
