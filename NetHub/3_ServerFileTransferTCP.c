//Write a socket program in C to transfer a file from the client to server in TCP. 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 15050
#define MAX_BUFFER_SIZE 1024

int main() {
    int server_fd, new_socket;
    struct sockaddr_in server_addr, new_addr;
    socklen_t addr_size;
    char buffer[MAX_BUFFER_SIZE];
    FILE* fp;

    // Create socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket
    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 5) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);
    addr_size = sizeof(new_addr);

    // Accept connection from client
    new_socket = accept(server_fd, (struct sockaddr*)&new_addr, &addr_size);

    // Open the file for reading
    fp = fopen("demo.txt", "rb"); // Use "rb" mode for reading binary files
    if (fp == NULL) {
        perror("File open failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        // Read from file into buffer
        int n = fread(buffer, 1, MAX_BUFFER_SIZE, fp);
        if (n > 0) {
            write(new_socket, buffer, n); // Send the data to the client
        }
        if (n < MAX_BUFFER_SIZE) {
            if (feof(fp)) {
                printf("File sent successfully.\n");
            }
            if (ferror(fp)) {
                perror("Error reading from file");
            }
            break;
        }
    }

    close(new_socket);
    close(server_fd);
    fclose(fp);

    return 0;
}

