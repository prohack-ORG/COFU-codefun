/*

	Author : Siddheshwar P Sharma
	Date   : 17th July 2016
	Link   : http://beej.us/guide/bgnet/output/html/singlepage/bgnet.html
	
*/


/// ECHO SERVER side socket code

/*

	Usage :
		TERMINAL 1
		----------
		gcc echo_server.c
		./a.out <portNumber>

		TERMINAL 2
		----------
		telnet localhost <portNumber>

*/

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
#include <arpa/inet.h>
#define PORT "3940"

#define MAXDATALEN 1024
#define ERROR -1

int main(int argc, char **argv)
{
	int sock, cli;
	struct sockaddr_in server, client;
	
	unsigned int len, sent;
	int data_len;
	char data[MAXDATALEN];
	char message[] = "Hi Sid to the socket programming world\n";
	if((sock = socket(AF_INET, SOCK_STREAM, 0)) == ERROR)
	{
		perror("\nError creating socket");
		exit(-1);
	}

	server.sin_family = AF_INET;
	server.sin_port = htons(atoi(argv[1]));  //Port number to be provided command line 
	server.sin_addr.s_addr = INADDR_ANY;
	bzero(&server.sin_zero, 0);
	
	len = sizeof(struct sockaddr_in);

	if(bind(sock, (struct sockaddr *)&server, len) == ERROR)
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
		if((cli = accept(sock, (struct sockaddr *)&client, &len)) == ERROR) //accept is a blocking call. until client connects, it will make the program wait
		{
			perror("\nError in accepting");
			exit(-1);
		}
		printf("Connected to port %d with client : %s", ntohs(client.sin_port), inet_ntoa(client.sin_addr));
		data_len = 1;
		while(data_len)
		{
			data_len = recv(cli, data, MAXDATALEN, 0);
			if(data_len)
			{
				send(cli, data, data_len, 0);
				data[data_len]='\0';
				printf("Sent Message : %s", data);
			}
		}
//		sent = send(cli, message, strlen(message), 0);
		//printf("\nSent %ud bytes to client %d ", sent, inet_ntoa(client.sin_addr));
		close(cli);
		printf("\nClient Disconnected");		
	}
	close(sock);
	return 0;
}
