#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
int main() {
    char name[5];
    printf("type ABCD\n");
    fgets(name, 5, stdin);
    if(!strcmp(name, "ABCD")) {
        char data[30];
        int fd = open("flag", O_RDONLY);
        read(fd, data, 30);
        write(1, data, 30);
        return 0;
    }
    printf("just type ABCD....\n");
    return 0;
}