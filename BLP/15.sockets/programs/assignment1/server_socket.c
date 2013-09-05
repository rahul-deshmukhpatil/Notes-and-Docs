#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <sys/un.h>
#include <errno.h>
#include <string.h>



int main()
{
	int clientfd, serverSocket;
	int clientLen, serverLen;
	char my_char = 'A';	
	struct sockaddr_un serverAddress, clientAddress;

	printf("Server prosses :\n");

	if(unlink("server_socket"))
	{
		printf("could not unlink the prev same named socket : %d:%s\n", errno, strerror(errno));
//		exit(-1);
	}	

	serverSocket = socket(AF_UNIX, SOCK_STREAM,0);

	if(serverSocket == -1)
	{
		printf("could not open server socket \n");
		exit(-1);
	}

	serverAddress.sun_family = AF_UNIX;	
	strcpy(serverAddress.sun_path, "server_socket");	
	serverLen = sizeof(serverAddress);
	
	if(bind(serverSocket, (const struct sockaddr *) &serverAddress, serverLen))
	{
		printf("could not bind to the address !!!\n");
		exit(-1);
	}

	listen(serverSocket, 5);

	while(1)
	{
		char ch;
		printf("server waitng ... \n");
		clientLen = sizeof(clientAddress);
		clientfd = accept(serverSocket, (struct  sockaddr *) &clientAddress, &clientLen);
		read(clientfd, &ch, 1);
		printf("client says : %c \n", ch);
		ch = my_char++;
		printf("sending client: %c \n", ch);
		write(clientfd, &ch, 1);
	}

	close(serverSocket);
	close(clientfd);
	return 0;
}
