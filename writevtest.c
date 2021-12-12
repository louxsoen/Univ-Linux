#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <sys/uio.h>

int main()
{
    struct iovec iov[3];
    ssize_t nr;
    int fd, i;

    char *buf[] = 
    {
        "i love you.\n",
        "hello world.\n",
        "writev test.\n"
    };

    fd = open("vectest.txt", O_WRONLY | O_CREAT | O_TRUNC);

    for(i = 0 ; i < 3 ; i++)
    {
        iov[i].iov_base = buf[i];
        iov[i].iov_len = strlen(buf[i]);
    }

    nr = writev(fd, iov, 3);

    printf("wrote %ld bytes\n", nr);

    return 0;
}