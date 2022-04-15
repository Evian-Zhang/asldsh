#define _GNU_SOURCE
#include <sys/personality.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (personality(ADDR_NO_RANDOMIZE) == -1) {
        fprintf(stderr, "Failed to disable ASLR, errno: %d.\n", errno);
        exit(-1);
    }

    if (argc <= 1) {
        char *shell = secure_getenv("SHELL");
        if (shell == NULL) {
            shell = "/bin/sh";
        }
        char *child_argv[] = {shell, "-i", NULL};
        execvp(shell, child_argv);
        exit(0);
    }

    char **child_argv = argv + 1;
    char *child_pathname = child_argv[0];
    execvp(child_pathname, child_argv);
    exit(0);
}
