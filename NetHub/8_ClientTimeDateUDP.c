//Write a socket program in C to provide the current Time and Date to the client in UDP. 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>

#define MAX 30
#define PORT 8080
#define SA struct sockaddr


int main(){
    int sockfd;
    struct sockaddr_in server_addr;
    char buff[MAX];
  
    sockfd = socket(AF_INET,SOCK_DGRAM,0);

    if(sockfd<0){
        printf("Error in socket creation.\n");
        exit(0);
    }
    
    server_addr.sin_family=AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    int len = sizeof(server_addr);

    strcpy(buff,"");
    sendto(sockfd,buff,MAX,0,(SA*)&server_addr,len);
    recvfrom(sockfd,buff,MAX,0,(SA*)&server_addr,&len);
    printf("\nTime From Server : %s\n",buff); 
    close(sockfd);  
    return 0;
}