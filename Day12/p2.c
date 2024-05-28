#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
    int fd, num1, num2, result;
    fd = open("/home/yaash/Desktop/DESD/eos/EOS_Assignments/Day12/desd_fifo", O_RDONLY);
    if(fd < 0){
        perror("open() failed");
    }

    read(fd, &num1, sizeof(num1));
    read(fd, &num2, sizeof(num2));

    result = num1 + num2;
    write(fd, &result, sizeof(result));

    close(fd);


    return 0;
}