//Write a socket program in C to create a chat between client and server in UDP. 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define MAX 100
#define SA struct sockaddr
#define PORT 8080

int main()
{
  int sockfd, len, n;
  struct sockaddr_in server_addr;
  char server_msg[MAX], client_msg[MAX];

  // creating the new socket

  sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockfd < 0)
  {
    printf("Error in socket creation..\n");
    exit(0);
  }
  else
    printf("Socket created successfully..\n");

  bzero(&server_addr, sizeof(server_addr));

  // assigning IP and PORT
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

  while (1)
  {
    len = sizeof(server_addr);
    memset(client_msg, '\0', sizeof(client_msg));
    memset(server_msg, '\0', sizeof(server_msg));

    // Sending message to client
    printf("To Server : ");
    gets(client_msg);
    sendto(sockfd, client_msg, sizeof(client_msg), 0, (SA *)&server_addr, sizeof(server_addr));
    if (strcmp(client_msg, "exit") == 0)
    {
      printf("Closing the chat...\n");
      break;
    }

    // receiving message from client
    recvfrom(sockfd, server_msg, sizeof(server_msg), 0, (SA *)&server_addr, &len);
    printf("\tFrom Server : %s\n", server_msg);
    if (strcmp(server_msg, "exit") == 0)
    {
      printf("Server Exit...\n");
      break;
    }
  }
  close(sockfd);
  return 0;
}