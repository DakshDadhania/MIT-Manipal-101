#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    printf("hello\n");
    pid_t pid = fork();
    if (pid == -1) {
        fprintf(stderr, "Failed to fork process\n");
        exit(1);
    } else if (pid == 0) {
        // Child process
        printf("test\n");
        int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
        if (fd == -1) {
            fprintf(stderr, "Failed to open output file\n");
            exit(1);
        }
        write(fd, "Child process\n", 15);
        close(fd);
    } else {
        // Parent process
        printf("bye\n");
        int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
        if (fd == -1) {
            fprintf(stderr, "Failed to open output file\n");
            exit(1);
        }
        write(fd, "Parent process\n", 16);
        close(fd);
    }
    return 0;
}
