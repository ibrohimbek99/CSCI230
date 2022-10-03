#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>



int main()
{
	int arr[10] = {15, 10, 2, 7, 9, 4, 1, 11, 8, 13};
	int i, j, a;
	pid_t pid;

	pid = fork();
	if (pid == 0){
		 for(i = 0; i < 10; i++){
			for( j = i+1; j < 10; j++){
				if(arr[i] > arr[j]){
					a = arr [i];
					arr[i] = arr[j];
					arr[j] = a;
				}
			}
		}
		printf("The largest element in the array is %d \n", arr[9]);
	}
	else if(pid > 0){
		wait(NULL);
		printf("Sorting by child is completed!\n");
	}
}

