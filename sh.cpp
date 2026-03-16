#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char **argv) {
    pid_t ppid = getppid();
    char comm[16] = {0};
    char path[64];
    snprintf(path, sizeof(path), "/proc/%d/comm", (int)ppid);
    int fd = open(path, O_RDONLY);
    if (fd >= 0) {
        ssize_t len = read(fd, comm, sizeof(comm)-1);
        close(fd);
        if (len > 0) {
            comm[len] = '\0';
            char *nl = strchr(comm, '\n');
            if (nl) *nl = '\0';
            if (strcmp(comm, "adbd") == 0) {
                printf("shell Closed\n");
                exit(0);
            }
        }
    }
    execv("/vendor/bin/sh", argv);
    perror("sh exec failed");
    exit(1);
}
