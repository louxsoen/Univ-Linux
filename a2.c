#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int filedes;
    ssize_t nread;
    off_t newpos;

    char buffer[1024];
    char content[] = "Hello my friend!\n";
    char content2[] = "I love you\n";
    
    filedes = open("data.txt", O_RDWR);
    
    nread = read(filedes, buffer, 1024);
    printf("%s\n", buffer);

    newpos = lseek(filedes, (off_t)3, SEEK_SET);
    if(newpos == -1)
    printf("error");


    write(filedes, content, strlen(content)); // content2 -> content
    write(filedes, content2, strlen(content2));
    write(filedes, "\0", (sizeof(buffer)/sizeof(char))-strlen(content)-strlen(content2));

    newpos = lseek(filedes, (off_t)3, SEEK_SET);
    nread = read(filedes, buffer, 1024);
    printf("%s\n", buffer);
    
    close(filedes);

    return 0;
}