/*Lab №9*/
#include <stdio.h>

int main(){
int arr[3][3]={2,3,6,9,4,6,34,2,0};
int max=0;
for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
        if (arr[i][j]>max){
            max=arr[i][j];
        }
        
    }
}
printf("Max= %d",max);
}

