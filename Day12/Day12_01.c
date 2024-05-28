//The client process send two numbers to the server process via one ﬁfo. The server process calculate the sum and return via another ﬁfo. The client process print the result.
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(){

    int fd, result, num1, num2;
    char str[32];

    fd = open("/tmp/desd_fifo/", O_CREAT | O_TRUNC | O_WRONLY, 0644);
    if(fd < 0){
        perror("open() failed:");
        _exit(1);
    }

    printf("Enter 2 numbers");
    scanf("%d %d",&num1,&num2);
    write(fd, &num1, sizeof(num1));
    write(fd, &num2, sizeof(num2));

    read(fd, &result, sizeof(result));

    printf("Sum: %d",result);
    
    close(fd);

    return 0;
}
