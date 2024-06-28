#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void signal_handler(int signal_num) {
    printf("Caught signal %d\n", signal_num);
}

int main() {
    // Register signal handler
    signal(SIGINT, signal_handler);

    printf("Press Ctrl+C to trigger the signal handler...\n");
    while (1) {
        sleep(1);
    }

    return 0;
}
