#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<signal.h>
#include<string.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


sig_atomic_t c=0;
sig_atomic_t cr_val;
sig_atomic_t exit_status;


//void print_message(SIGINT);

/* struct sigaction {
	        void     (*sa_handler)(int);
		void     (*sa_sigaction)(int, siginfo_t *, void *);
		sigset_t   sa_mask;
		int        sa_flags;
		 void     (*sa_restorer)(void);
               };

*/
int main(){
	pid_t j;
	int i;
	i=fork();
	if(i==-1){
		perror("fork");
		exit(1);
	}
	else if(i==0){
		j=getpid();
		struct sigaction sa;
		memset(&sa,0,sizeof(sa));
		sa.sa_handler=SIG_IGN;
		sigaction(SIGINT,&sa,NULL);
		printf("YOU ARE IN CHILD PROCESS\n");
		printf("enter your luck no\n");
		int t=0;
	//	scanf("%d",&t);
		while(1){
		sleep(1);
		printf("pid=%d",j);
		printf("your lucky no=%d\n",t);
		}
	//	sigaction(SIGINT,NULL,NULL);
	}
	else{
		 wait(&j);
		 printf("you are in parent process\n");
		 kill(j,SIGINT);
	}

}
/*
void print_message(SIGINT){
	
	exit_status=EXIT_FAILURE;
	printf("SIGINT has been occured");
	exit(exit_status);
}
























/*
int main(){
	struct sigaction *old_sa;
	struct sigaction sa;
	memset(&sa,sizeof(sa),0);
	sa.sa_handler=SIG_IGN;
	sigaction(SIGINT,&sa,old_sa);
	sleep(5);
	int a,b;
	printf("enter two no\n");
	scanf("%d%d",&a,&b);
	c=a+b;
	printf("sum=%d\n",c);
	sigaction(SIGINT,old_sa,NULL);
	return 0;
}
*/
