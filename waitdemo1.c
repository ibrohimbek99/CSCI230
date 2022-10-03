#include <stdlib.h>
#include     <sys/types.h>
#include     <stdio.h>
#include     <unistd.h>
#include <sys/wait.h>

#define	DELAY	2

int main()
{
	int  newpid;
	void child_code(), parent_code();

	printf("before: mypid is %d\n", getpid());

	if ( (newpid = fork()) == -1 )
		perror("fork");
	else if ( newpid == 0 )
		child_code(DELAY);
	else
		parent_code(newpid);
return 0;
}
/*
 * new process takes a nap and then exits
 */
void child_code(int delay)
{
	printf("child %d here. will sleep for %d seconds\n", getpid(), delay);
	sleep(delay);
	printf("child done. about to exit\n");
	exit(0);
}
/*
 * parent waits for child then prints a message
 */
void parent_code(int childpid)
{
	int wait_rv;		/* return value from wait() */
	wait_rv = wait(NULL);
	printf("done waiting for %d. Wait returned: %d\n", childpid, wait_rv);
}
