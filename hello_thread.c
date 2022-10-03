#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *msg_func( void *ptr );

main()
{
  pthread_t thread1, thread2;
  const char *msg1 = "Hello from Thread 1";
  const char *msg2 = "Hello from Thread 2";
  int  iret1, iret2;

  iret1 = pthread_create(&thread1, NULL, msg_func,(void*) msg1);
  if(iret1)
  {
      fprintf(stderr,"Error: %d\n",iret1);
      exit(EXIT_FAILURE);
  }

  iret2 = pthread_create(&thread2, NULL, msg_func,(void*) msg2);
  if(iret2)
  {
      fprintf(stderr,"Error: %d\n",iret2);
      exit(EXIT_FAILURE);
  }

  printf("pthread_create() for thread 1 returns: %d\n",iret1);
  printf("pthread_create() for thread 2 returns: %d\n",iret2);

  pthread_join( thread1, NULL);
  pthread_join( thread2, NULL);

  exit(EXIT_SUCCESS);
}

void *msg_func( void *ptr )
{
  char *message;
  message = (char *) ptr;
  printf("%s \n", message);
}

