//Write a socket program in C to create a chat between client and server in UDP. 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define MAX 1000
#define SA struct sockaddr
#define PORT 8080

int main()
{
  int sockfd, len;
  struct sockaddr_in server_addr, client_addr;
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
  bzero(&client_addr, sizeof(client_addr));

  // assigning IP and PORT
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

  if (bind(sockfd, (SA *)&server_addr, sizeof(server_addr)) != 0)
  {
    printf("Socket binding failed...\n");
    exit(0);
  }
  else
    printf("Socket successfully binded..\n");

  printf("Listening for incoming messages...\n\n");

  while (1)
  {
    len = sizeof(client_addr);

    memset(client_msg, '\0', sizeof(client_msg));
    memset(server_msg, '\0', sizeof(server_msg));

    // receiving message from client
    recvfrom(sockfd, client_msg, sizeof(client_msg), 0, (SA *)&client_addr, &len);
    printf("From Client : %s\n", client_msg);
    if(strcmp(client_msg,"exit")==0){
      printf("Client Exit...\n");
      break;
    }

    // Sending message to client
    printf("\tTo Client : ");
    gets(server_msg);
    sendto(sockfd, server_msg, sizeof(server_msg), 0, (SA *)&client_addr, len);
    if(strcmp(server_msg,"exit")==0){
      printf("Closing the chat...\n");
      break;
    }
  }
  close(sockfd);
  return 0;
}
