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
	int listenfd,addrlen1,sock;
	sock=socket(AF_INET,SOCK_DGRAM,0);
	struct sockaddr_in serveraddr;
	addrlen1=sizeof(serveraddr);
	serveraddr.sin_family=AF_INET;
	serveraddr.sin_port=htons(RAWPORT);
	serveraddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	while(1){
		char buffer[80];
		printf("enter the message\n");
        fgets(buffer,80,stdin);
		int nBytes=strlen(buffer)+1;
		sendto(sock,buffer,nBytes,0,(struct sockaddr *)&serveraddr,addrlen1);
		nBytes=recvfrom(sock,buffer,80,0,NULL,NULL);
		printf("recieved is%s",buffer);
	}
	close(sock);
}