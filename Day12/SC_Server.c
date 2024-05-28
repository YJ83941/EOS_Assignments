#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
// server
#define SOCK_PATH "/tmp/desd_socket"
#define SERV_PORT	2809
#define SERV_IP		"172.18.5.140"

int serv_fd;
void sigint_handler(int sig) {
	shutdown(serv_fd, SHUT_RDWR);
	unlink(SOCK_PATH);
	_exit(0);
}

int main() {
	int cli_fd, ret, num1,num2, res;
	struct sockaddr_un serv_addr, cli_addr;
	socklen_t socklen;

	struct sigaction sa;

	memset(&sa, 0, sizeof(struct sigaction));
	sa.sa_handler = sigint_handler;
	ret = sigaction(SIGINT, &sa, NULL);
	if(ret < 0) {
		perror("sigaction() failed");
		_exit(1);
	}

	char str[64];
	serv_fd = socket(AF_UNIX, SOCK_STREAM, 0);
	if(serv_fd < 0) {
		perror("socket() failed");
		_exit(1);
	}

	serv_addr.sun_family = AF_UNIX;
	strcpy(serv_addr.sun_path, SOCK_PATH);
	//inet_aton(SERV_IP, &serv_addr.sin_addr);
	ret = bind(serv_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
	if(ret < 0) {
		perror("bind() failed");
		_exit(2);
	}

	listen(serv_fd, 5);

	socklen = sizeof(cli_addr);
	
	while(1){
		cli_fd = accept(serv_fd, (struct sockaddr*)&cli_addr, &socklen);
		if(cli_fd < 0) {
			perror("accept() failed");
			_exit(3);
		}
		read(cli_fd, &num1, sizeof(num1));
		printf("Num 1: %d\n", num1);
		//----------------------------------//
		read(cli_fd, &num2, sizeof(num2));
		printf("Num2: %d\n", num2);
		res = num1+num2;
		printf("Server Sum: %d\n",res);
		write(cli_fd, &res, sizeof(res));
		close(cli_fd);
	}
	
//	shutdown(serv_fd, SHUT_RDWR);
	return 0;
}
