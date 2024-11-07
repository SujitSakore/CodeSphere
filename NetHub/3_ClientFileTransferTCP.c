//Write a socket program in C to transfer a file from the client to server in TCP.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 15050
#define MAX_BUFFER_SIZE 1024

int main() {
    int client_fd;
    struct sockaddr_in server_addr;
    char buffer[MAX_BUFFER_SIZE];
    FILE* fp;

    // Create socket
    client_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client_fd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect to the server
    if (connect(client_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        exit(EXIT_FAILURE);
    }

    // Open a file for writing
    fp = fopen("received_file.txt", "w");
    if (fp == NULL) {
        perror("File open failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        int n = read(client_fd, buffer, MAX_BUFFER_SIZE); // Receive data from the server
        if (n <= 0) {
            break;
        }
        fwrite(buffer, 1, n, fp); // Write the data to the file
    }

    printf("File received successfully.\n");

    close(client_fd);
    fclose(fp);

    return 0;
}
