
#include <iostream>
#include <unistd.h>
#include <cstdlib>

void daemonize() {
    // Fork the parent process
    pid_t pid = fork();

    // If the fork fails, exit with an error
    if (pid < 0) {
        std::cerr << "Failed to fork." << std::endl;
        exit(EXIT_FAILURE);
    }

    // If the fork succeeds, exit the parent process
    if (pid > 0) {
        exit(EXIT_SUCCESS);
    }

    // Create a new session
    if (setsid() < 0) {
        std::cerr << "Failed to create a new session." << std::endl;
        exit(EXIT_FAILURE);
    }

    // Fork again to ensure the process is not a session leader
    pid = fork();

    // If the fork fails, exit with an error
    if (pid < 0) {
        std::cerr << "Failed to fork again." << std::endl;
        exit(EXIT_FAILURE);
    }

    // If the fork succeeds, exit the parent process
    if (pid > 0) {
        exit(EXIT_SUCCESS);
    }

    // Change the working directory to root
    if (chdir("/") < 0) {
        std::cerr << "Failed to change the working directory to /." << std::endl;
        exit(EXIT_FAILURE);
    }

    // Close standard file descriptors
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
}

int main() {
    // Daemonize the process
    daemonize();

    // Your application logic goes here
    // ...

    return 0;
}
