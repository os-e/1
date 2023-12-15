#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024
void copy(char *src, char *dst){
    int sfd, dfd, count;
    char buffer[BUFFER_SIZE];
    mode_t fileMode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;

    if ((sfd = open(src, O_RDONLY)) < 0){
        fprintf(stderr, "ERROR: %s doesn't exist or cannot be opened for reading\n", src);
        exit(1);
    }
    dfd = open(dst, O_CREAT | O_WRONLY | O_TRUNC, fileMode);
    while ((count = read(sfd, buffer, BUFFER_SIZE)) > 0)
        write(dfd, buffer, count);
    close(sfd);
    close(dfd);
}

int main(int argc, char *argv[]){
    if (argc != 3){
        fprintf(stderr, "ERROR: usage: %s <src> <dst>\n", argv[0]);
        return 1;
    }
    printf("Copying %s to %s\n", argv[1], argv[2]);
    copy(argv[1], argv[2]);
    return 0;
}
