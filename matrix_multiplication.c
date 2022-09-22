#include <stdio.h>
int main()
{
  int rowI, columnI;//first matrix
  int rowII, columnII;// second matrix
  int c = 0, i, j, sum;//counters
  int tempI, tempII, tempIII, tempIV;//for array declaration
//number of rows and columns input
//while checks if the value is correct
 while(c==0)
 {
  printf("Enter number of rows and columns of first matrix\n");
  scanf("%d%d", &rowI, &columnI);

  printf("Enter number of rows and columns of second matrix\n");
  scanf("%d%d", &rowII, &columnII);

   if(rowI!=columnII)
   {
   printf("\n Number of rows in first matrix must be equal to \n number of columns in second matrix\n \n");
   printf("Enter again\n\n");
   }
   else
   {
   c++;
   }
 }
//declare arrays the size of matrices

tempI=rowI;
tempII=columnI;
tempIII=rowII;
tempIV=columnII;
int first[rowI][columnI], second[rowII][columnII], product[rowI][columnII];

//elements if first matrix input

  printf("Enter elements of first matrix\n");

   for (c = 0; c < rowI; c++)
   {
    for (i = 0; i < columnI; i++)
    {
      scanf("%d", &first[c][i]);
    }
   }

//elements of second matrix input

    printf("Enter elements of second matrix\n");
 
    for (c = 0; c < rowII; c++)
    {
      for (i = 0; i < columnII; i++)
      {
        scanf("%d", &second[c][i]);
      }
    }
 
//mutiplication
//printfs are for convenience

sum = 0;

    for (c = 0; c < rowI; c++) 
    {
      for (i = 0; i < columnII; i++) 
      {
        for (j = 0; j < rowII; j++) 
        {
            sum = sum + first[c][j]*second[j][i];
       //printf("j: %d \n", j);
       //printf("first[%d][%d]: %d \n", c, j, first[c][j]);
       //printf("second[%d][%d]: %d \n",j, i, second[j][i]);
        }
 
         product[c][i] = sum;
        //printf("i: %d \n", i);
        //printf("sum: %d \n", sum);
         sum = 0;
      }
    //printf("c: %d \n", c);
    }
//Output
    printf("Product of matrix multiplication:\n");
 
    for (c = 0; c < rowI; c++) 
    {
      for (i = 0; i < columnII; i++)
       { 
          printf("%d\t", product[c][i]);
       }
        printf("\n");
    }
 
  return 0;
}
