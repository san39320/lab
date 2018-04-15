#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<ctype.h>
#define RAWPORT 5556
void main(){
    char buffer[1024];
    int bufferlen=1024,listenfd,nBytes,sock;
    int addrlen1,addrlen2; 
    sock=socket(AF_INET,SOCK_DGRAM,0);
    struct sockaddr_in serveraddr;
    serveraddr.sin_family=AF_INET;
    serveraddr.sin_port=htons(RAWPORT);
    serveraddr.sin_addr.s_addr=inet_addr("127.0.0.1");
    addrlen2=sizeof(serveraddr);
    while(1)
    {
        printf("enter the message\n");
        fgets(buffer,1024,stdin);
        nBytes=strlen(buffer)+1;
        sendto(sock,buffer,nBytes,0,(struct sockaddr *)&serveraddr,addrlen2);
        nBytes=0;
        nBytes=recvfrom(sock,buffer,bufferlen,0,NULL,NULL);
        if(nBytes==0){printf("chtiya");}
        printf("Received from server: %s\n",buffer);
    }
}
