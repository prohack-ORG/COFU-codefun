/*

	Author : Siddheshwar P Sharma
	Date   : 08th July 2016
	Link   : http://beej.us/guide/bgnet/output/html/singlepage/bgnet.html
	
*/


/// SERVER side socket code

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>	// for socket
#include <netinet/in.h> // for structures
#include <stdlib.h>
#include <signal.h>
#include <errno.h>
#include <error.h>
#include <strings.h>
#define PORT "3940"

#define BACKLOG 10

int main()
{
	int sock, cli;
	struct sockaddr_in server, client;
	
	unsigned int len, sent;
	char message[] = "Hi Sid to the socket programming world\n";
	if((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		perror("\nError creating socket");
		exit(-1);
	}

	server.sin_family = AF_INET;
	server.sin_port = htons(1000);
	server.sin_addr.s_addr = INADDR_ANY;
	bzero(&server.sin_zero, 0);
	
	len = sizeof(struct sockaddr_in);

	if(bind(sock, (struct sockaddr *)&server, len) == -1)
	{
		perror("\nBind Error");
		exit(-1);
	}

	if(listen(sock, 5) == -1)
	{
		perror("\nListen Error");
		exit(-1);
	}

	while(1) // to keep server on 
	{
		if((cli = accept(sock, (struct sockaddr *)&client, &len)) == -1)
		{
			perror("\nError in accepting");
			exit(-1);
		}
		sent = send(cli, message, strlen(message), 0);
		
		printf("\nSent %ud bytes to client %d ", sent, inet_ntoa(client.sin_addr));
		close(cli);
	}

	return 0;
}
