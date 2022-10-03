#include <stdio.h>

int main()
{
	int lowerNum, upperNum, count,i;
	
	printf("Enter lower bound: ");
	scanf("%d", &lowerNum);
	printf("Enter upper bound: ");
	scanf("%d", &upperNum);

    printf ("The prime numbers between %d and %d are: ", lowerNum, upperNum);
 
 for (i=lowerNum; i<upperNum; i++){
 	if (i==0 || i == 1)
 		continue;
 		
    	count = 1;
 	
 	for (int j=2;j<= i/2; j++){
 		if (i % j==0){
 			count = 0;
 			break;
 		}
 	}
 	if (count == 1)
 		printf("%d ",i);
 	
 	
 }return 0;
}