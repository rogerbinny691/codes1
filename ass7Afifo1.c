#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    int fd;

    // FIFO file path
    char *myfifo = "/tmp/myfifo";

    // Creating the named file (FIFO)
    mkfifo(myfifo, 0666);

    char sentence[1000]; // Buffer to store the user's input, larger for multiline input

    while (1) {
        // Open FIFO for write only
        fd = open(myfifo, O_WRONLY);

        // Take input from the user, multiple lines can be entered
        printf("\n\n >> Enter a sentence (or 'exit' to end this process, followed by Enter):\n");
        strcpy(sentence, ""); // Clear the buffer

        while (1) {
            char line[100];
            fgets(line, sizeof(line), stdin);

            // Check if the user wants to exit
            if (strcmp(line, "exit\n") == 0) {
                break; // Exit the loop
            }

            strcat(sentence, line); // Concatenate the lines
        }

        // Write the input sentence on the FIFO
        write(fd, sentence, strlen(sentence) + 1);
        close(fd);

        if (strcmp(sentence, "exit\n") == 0) {
            break; // Exit the loop
        }

        // Now open FIFO for read only to get the response
        fd = open(myfifo, O_RDONLY);

        // Read and display the response of the receiver in the sender (pipe1) terminal
        printf("\n --> Receiver's Response:\n\n");

        while (1) {
            char response[100];
            read(fd, response, sizeof(response));
            if (strcmp(response, "exit\n") == 0) {
                break; // Exit the loop
            }
            printf("%s", response);
        }

        close(fd); // Close the file descriptor
    }

    return 0;
}
