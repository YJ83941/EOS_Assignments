#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
// client
#define SOCK_PATH	"/tmp/desd_socket"
#define SERV_PORT	2809
#define SERV_IP		"127.0.0.1"
int main() {
	int cli_fd, ret, num1, num2, res;
	struct sockaddr_un serv_addr;
	char str[64];
	cli_fd = socket(AF_UNIX, SOCK_STREAM, 0);
	if(cli_fd < 0) {
		perror("socket() failed");
		_exit(1);
	}

	serv_addr.sun_family = AF_UNIX;
	strcpy(serv_addr.sun_path, SOCK_PATH);
	//inet_aton(SERV_IP, &serv_addr.sin_addr);

	//while(1){
		ret = connect(cli_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
		if(ret < 0) {
			perror("connect() failed");
			_exit(2);
		}

		printf("Enter First number: \n");
		scanf("%d",&num1);
		printf("num1: %d\n", num1);
		write(cli_fd, &num1, sizeof(num1));
		
		printf("Enter Second number: \n");
		scanf("%d",&num2);
		printf("num2: %d\n", num2);
		write(cli_fd, &num2, sizeof(num2));

		read(cli_fd, &res, sizeof(res));
		printf("Client1 Res: %d\n",res);
		close(cli_fd);
//	}

	return 0;
}