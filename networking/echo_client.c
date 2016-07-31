/*

	Author : Siddheshwar P Sharma
	Date   : 17th July 2016

*/

// ECHO CLIENT

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <strings.h>

#define MAXDATASIZE 1024
#define ERROR -1


int main(int argc, char ** argv)
{
	struct sockaddr_in remote_server;
	int sock;
	char input[MAXDATASIZE], output[MAXDATASIZE];
	int len;

	if((sock = socket(AF_INET,SOCK_STREAM,0))==ERROR)
	{
		printf("\nError creating socket, try again");
		exit(-1);
	}
	
	remote_server.sin_family = AF_INET;
	remote_server.sin_port = htons(atoi(argv[2]));
	remote_server.sin_addr.s_addr = inet_addr(argv[1]);
	bzero(&remote_server.sin_zero, 0);
	
	if(connect(sock,(struct sockaddr *)&remote_server, sizeof(struct sockaddr_in)) == ERROR)
	{
		printf("\nConnect failure");
		exit(-1);
	}
	
	while(1)
	{
		fgets(input, MAXDATASIZE, stdin);
		
		send(sock, input, strlen(input), 0);
		
		len = recv(sock, output, MAXDATASIZE, 0);
		output[len] = '\0';
		printf("\nFrom server : %s", output);
	}
	close(sock);

	return 0;
}
