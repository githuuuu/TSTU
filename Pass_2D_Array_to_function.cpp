#include <iostream>
using namespace std;
void showArr(int **a, int n);
void makeArr(int **a, int n);
void diag(int **a, int n);
int main(){
    int n=4;
    int **arrA;
    arrA = new int *[n];
    for(int i = 0; i <n; i++){
        arrA[i] = new int[n];
    }
    makeArr(arrA,n);
    diag(arrA,n);
    showArr(arrA,n);
}
void showArr(int **a, int n){
    cout<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<'\t';
        }
        cout<<endl;
    }
    cout<<endl;
    return;
}
void makeArr(int **a, int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            a[i][j]=0;
        }
    }
}
void diag(int **a, int n){
    for(int i=0;i<n;i++){
            a[i][i]=i;

    }
}
