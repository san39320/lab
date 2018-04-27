#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<stdlib.h>
#define PORT 5556
void main(){
    //declare
    ssize_t n;
    int listenfd,connfd,addrsize;
    struct sockaddr_in serveraddr,clientaddr;
    //socket
    listenfd=socket(AF_INET,SOCK_STREAM,0);
    //addr and bind
    addrsize=sizeof(serveraddr);
    bzero(&serveraddr,addrsize);
    serveraddr.sin_family=AF_INET;
    serveraddr.sin_port=htons(PORT);
    serveraddr.sin_addr.s_addr=INADDR_ANY;
    bind(listenfd,(struct sockaddr*)&serveraddr,addrsize);
    //listen
    listen(listenfd,1);
    //acccept
    int addrsize1=sizeof(clientaddr);
    while(1){
        connfd=accept(listenfd,(struct sockaddr*)&clientaddr,&addrsize1);
        //
        char filename[10],buffer[80];
        read(connfd,filename,10);
        printf("filename is %s\n",filename);
        FILE *fp;
        fp=fopen(filename,"r");
        while(fgets(buffer,80,fp)!=NULL){
            write(connfd,buffer,80);                                                                                       
        }
        //close
        fclose(fp);
        close(connfd);
    }

}