#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<signal.h>
#include<string.h>
#include<unistd.h>

sig_atomic_t c=0;

/* struct sigaction {
	        void     (*sa_handler)(int);
		void     (*sa_sigaction)(int, siginfo_t *, void *);
		sigset_t   sa_mask;
		int        sa_flags;
		 void     (*sa_restorer)(void);
               };

*/

int main(){
	struct sigaction *old_sa;
	struct sigaction sa;
	memset(&sa,0,sizeof(sa));
	sa.sa_handler=SIG_IGN;
//	sa.sa_handler=SIG_DFL;
	sigaction(SIGINT,&sa,old_sa);
	sleep(5);
	int a,b;
	printf("enter two no\n");
	scanf("%d%d",&a,&b);
	c=a+b;
	printf("sum=%d\n",c);
//	sigaction(SIGINT,old_sa,NULL);
	while(1){
		sleep(1);
		printf("helloworld\n");
	}
	return 0;
}
