#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
#define RPORT 5556
void main(){
	int sock,addrlen1;
	sock=socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in serveraddr;
	bzero(&serveraddr,sizeof(serveraddr));
	serveraddr.sin_family=AF_INET;
	serveraddr.sin_port=htons(RPORT);
	inet_pton(AF_INET,"localhost",&serveraddr.sin_addr);

	connect(sock,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
	char buffer[80];
	char filename[80];
	printf("enter the filename");
	fgets(filename,80,stdin);
	printf("filename is %s\n",filename);
	write(sock,filename,sizeof(filename));
	while(read(sock,buffer,80)!=0){
	printf("%s",buffer);
	}
	close(sock);
}