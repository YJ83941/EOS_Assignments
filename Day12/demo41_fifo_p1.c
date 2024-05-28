#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

// p1 -- writer
int main() {
	int fd, cnt, num1, num2, res;
	//char str[32];
	fd = open("/tmp/desd_fifo", O_WRONLY);
	if(fd < 0) {
		perror("open() failed");
		_exit(1);
	}

	printf("enter 2 numbers: ");
	scanf("%d%d", &num1, &num2);

	write(fd, &num1, sizeof(num1));
	write(fd, &num2, sizeof(num2));
	close(fd);
	fd = open("/tmp/desd_fifo", O_RDONLY);
	//printf("written in fifo: %d bytes\n", cnt);

	read(fd, &res, sizeof(res));
	printf("%d + %d = %d\n",num1, num2, res);

	close(fd);
	return 0;
}

