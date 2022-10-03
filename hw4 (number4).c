#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int columnSum(int n, int arr[][n]) //size of matrix
{
    int i, j, sum;
    sum = 0;
    for(j = 0; j < n; j++)
        for(i = 0; i < n; i++)
            sum += arr[i][j];
    
    return sum;
}

int rowSum(int n, int arr[][n]) //size of matrix
{
    int i, j, sum;
    sum = 0;
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            sum += arr[i][j];
    
    return sum;
}

int main(){
    
   int a[5][5]= {
                { 1, 5, 6, 7, 8},
                { 2, 3, 1, 2, 9},
                { 1, 5, 7, 1, 4},
                { 7, 1, 4, 9, 1},
                { 2, 3, 5, 4, 1}
    };
   /* int b[2][2] = {
                    {0, 1},
                    {1, 0}
    };*/
    
    int sum1, sum2, i;
    clock_t start, end;
    double cpu_time_used1, cpu_time_used2;
    start = clock();
    for (i=0;i<10000000;i++)
    {
         sum1 = columnSum(5, a) ;
    }
    end = clock();
    cpu_time_used1 = (double) (end - start);
    printf("Summation time for array of length 5*5 in column-wise method is: %lf \n", cpu_time_used1/10000000);
    
    start = clock();
    for (i=0;i<10000000;i++)
    {
        sum2 = rowSum(5, a);
    }
    end = clock();
    cpu_time_used2 = (double) (end - start);
    printf("Summation time for array of length 5*5 in row-wise method is: %lf \n", cpu_time_used2/10000000);
   
    
   
    
    return 0;
    
}
    


