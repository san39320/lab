#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<stdlib.h>
#define SERV_PORT 5576

int main(){
    int i,j;
    ssize_t n;
    FILE *fp;
    char s[80],f[80];
    struct sockaddr_in servaddr,cliaddr;
    int listenfd,connfd,clilen;
    //getting socket
    if((listenfd=socket(AF_INET,SOCK_STREAM,0))==-1)
    {
        perror("socket: ");exit(-1);
    }
    //setting server address
    bzero(&servaddr,sizeof(servaddr));
    servaddr.sin_family=AF_INET;
    servaddr.sin_port=htons(SERV_PORT);
    //binding
    int len=sizeof(struct sockaddr_in);
    if((bind(listenfd,(struct sockaddr*)&servaddr,len))==-1)
    {
        perror("bind");exit(-1);
    }
    //listen
    if((listen(listenfd,1)==-1)){
        perror("listen");exit(-1);
    }
    //connect accept
    clilen=sizeof(cliaddr);
    if((connfd=accept(listenfd,(struct sockaddr*)&cliaddr,&clilen))==-1){
        perror("connexction error");exit(-1);
    }
    printf("client connected\n");
    //data transfer
    read(connfd,f,80);
    fp=fopen(f,"r");
    printf("Filename:%s\n",f);
    while(fgets(s,80,fp)){
        printf("%s",s);
        write(connfd,s,sizeof(s));
    }
    close(listenfd);
    fclose(fp);
    return 1;
}