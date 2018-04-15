#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#define PORT 5556
void main(){
    int sock=socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in serveraddr;
    
    bzero(&serveraddr,sizeof(serveraddr));
    serveraddr.sin_family=AF_INET;
    serveraddr.sin_port=htons(PORT);
    inet_pton(AF_INET,"localhost",&serveraddr.sin_addr);

    connect(sock,(struct sockaddr *)&serveraddr,sizeof(serveraddr));
    //
    char filename[10],buffer[80];
    printf("enter the filename you want to enter");
    scanf("%s",filename);
    write(sock,filename,sizeof(filename));
    printf("file contents are\n");
    FILE *fp;
    fp=fopen("copy.txt","w");
    while(read(sock,buffer,80)!=0){
        printf("%s",buffer);
        fputs(buffer,fp);
    }
    close(sock);
}