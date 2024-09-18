#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

void gift() {
    char path[5] = {0, };
    printf("What do you Want?\n");

    read(0, path, 5);

    if(strcmp(path, "flag")){
        printf("i can't give you that");
        return -1;
    }

    printf("Sure, Here you are.\n");
    
    char data[100] = {0, };

    int fd = open(path, O_RDONLY);
    read(fd, data, 21);
    write(1, data, 21);
    printf("\n");
    return 0;

}

void vuln()
{
    int a,b;
    unsigned int ua;
    printf("Can You Pass Me?\n");
    scanf("%d", &a);
    if(a != 0x31337) {
        printf("No, You can't");
        exit(0);
    }
    printf("ok, ok..\nbut not this time...\n");
    printf("Give me something Big....\n");
    scanf("%d", &b);
    if(b > 10) {
        printf("That is So big Value\n");
        exit(0);
    }
    ua = b;
    if(ua < 10000) {
        printf("Give Me More!! zz\n");
        exit(0);
    }

    printf("WoW You understand the unsigned type!\n");

    char arr[18];
    printf("Give Me Password\n");
    printf("Password : ");
    scanf("%s", arr);
    if(strlen(arr) > 18) {
        printf("No.");
        exit(0);
    }

    for(int i=0; i < strlen(arr); i++) {
        arr[i] -= 10;
    }

    if(strcmp(arr, "THISISNOTPASSWORD")) {
       printf("Wrong Password\n");
       exit(0);
    }

    printf("Password Correct\n\n");

    printf("You've solved all the problems. Record your name\n");

    char of[100];

    scanf("%s", of);

    printf("Nice job %s! This is gift.\n", of);
    //gift(); oops i forgot to implement this function...
}

int main() {
    vuln();

    printf("Nice Job!");
    return 0;
}