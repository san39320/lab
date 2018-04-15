#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<ctype.h>
#define RAWPORT 5555
void main(){
    int listenfd,addrlen1;
    listenfd=socket(AF_INET,SOCK_DGRAM,0);
    struct sockaddr_in serveraddr;
    struct sockaddr_storage storage;
    addrlen1=sizeof(storage);
    serveraddr.sin_family=AF_INET;
    serveraddr.sin_port=htons(RAWPORT);
    serveraddr.sin_addr.s_addr=INADDR_ANY;
    bind(listenfd,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
    while(1){
        char buffer[80];
        int nBytes;
        nBytes=recvfrom(listenfd,buffer,80,0,&storage,&addrlen1);
        printf("%s",buffer);
        for(int i=0;i<nBytes;i++){buffer[i]=toupper(buffer[i]);}
        sendto(listenfd,buffer,nBytes,0,&storage,addrlen1);
    }
    close(listenfd);
}
