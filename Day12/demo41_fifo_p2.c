#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

// p2 -- reader
int main() {
	int fd, cnt, n1, n2, res;
	//char str[32];
	fd = open("/tmp/desd_fifo", O_RDONLY);
	if(fd < 0) {
		perror("open() failed");
		_exit(1);
	}

	printf("waiting for data...\n");
	read(fd, &n1, sizeof(n1));
	read(fd, &n2, sizeof(n2));
	//printf("read from fifo: %d bytes -- %s\n", cnt, str);
	res = n1+n2;
	printf("Result: %d\n",res);
	close(fd);
	fd = open("/tmp/desd_fifo", O_WRONLY);
	write(fd, &res, sizeof(res));
	close(fd);
	return 0;
}


