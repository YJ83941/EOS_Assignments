#include <stdio.h>
//#include <unistd.h>
//#include <sys/wait.h>
#include <signal.h>

int main() {
	int ret, signum, psid;
	printf("Enter Signum: \n");
	scanf("%d",&signum);
	printf("Enter PID:\n");
	scanf("%d",&psid);
	ret = kill(psid,signum);
	if(ret == 0) {
		 printf("Process killed successfully!\n");
	}
	else {
		printf("Killing Failed");
	}
	return 0;
}

