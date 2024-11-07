//Write a socket program in C to provide the current Time and Date to the client in UDP. 

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<time.h>

#define MAX 30
#define PORT 8080
#define SA struct sockaddr


int main(){
    int sockfd;
    struct sockaddr_in server_addr,client_addr;
    time_t curr_time;
    time(&curr_time);
    int countClient = 0;
    char buff[MAX];
    sockfd = socket(AF_INET,SOCK_DGRAM,0);

    if(sockfd<0){
        printf("Error in socket creation.\n");
        exit(0);
    }
    else
        printf("Server created successfully.\n");
    bzero(&server_addr,sizeof(server_addr));
    
    
    server_addr.sin_family=AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if(bind(sockfd,(SA*)&server_addr,sizeof(server_addr)) !=0 ){
        printf("Binding failed\n");
        exit(0);
    }
    else
        printf("Socket binded successfully\n");
    
    while(1){
        countClient++;
        int len = sizeof(client_addr);
        recvfrom(sockfd,buff,MAX,0,(SA*)&client_addr,&len);
        // char *string = asctime(timeinfo);
        time(&curr_time);
        printf("\nClient %d has requested for time at %s", countClient, ctime(&curr_time));
      
        //sending time to the client side
        // ctime(&time_from_pc)
       
        time(&curr_time);
        sendto(sockfd,ctime(&curr_time), MAX, 0,(SA*)&client_addr,len);
        
    }

    return 0;
}