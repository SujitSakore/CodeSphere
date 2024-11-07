//Write a socket program in C to handle multiple clients using fork in TCP. 
//mServer

#include<stdio.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#define SERV_TCP_PORT 5035
int main(int argc,char**argv)
{
       int i,sockfd,newsockfd,clength;
       struct sockaddr_in serv_addr,cli_addr;
       char buffer[4098];
       pid_t childpid;
       sockfd=socket(AF_INET,SOCK_STREAM,0);
       serv_addr.sin_family=AF_INET;
       serv_addr.sin_addr.s_addr=INADDR_ANY;
       serv_addr.sin_port=htons(SERV_TCP_PORT);
       printf("\nStart");
       bind(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
       printf("\nListening...\n");
       listen(sockfd,5);
       i=1;
       for(;;)
       {
            clength=sizeof(cli_addr);
           listen(sockfd,5);
           newsockfd=accept(sockfd,(struct sockaddr*)&cli_addr,&clength);
           printf("\n\nAccepted");
           if((childpid=fork())==0)
           {
                printf("\nChild PID is : %d",getpid());
                read(newsockfd,buffer,4096);
                printf("\nClient Message : %s",buffer);
           }
           close(newsockfd);
           i++;
       }
       return 0;
}
