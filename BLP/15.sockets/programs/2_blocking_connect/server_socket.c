#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <sys/un.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>



int main()
{
	int clientfd, serverSocket;
	int clientLen, serverLen;
	char my_char = 'A';	
	struct sockaddr_un serverAddress, clientAddress;
	int flags;

	printf("Server prosses :\n");

	if(unlink("server_socket_file"))
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
	strcpy(serverAddress.sun_path, "server_socket_file");	
	serverLen = sizeof(serverAddress);
	
	if(bind(serverSocket, (const struct sockaddr *) &serverAddress, serverLen))
	{
		printf("could not bind to the address !!!\n");
		perror("Error:");
		exit(-1);
	}

	listen(serverSocket, 5);

	flags = fcntl(serverSocket, F_GETFL, 0);

	printf("File controls : %x %x", flags, O_NONBLOCK);	
		fcntl(serverSocket, F_SETFL, flags | O_NONBLOCK);
	
	
	while(1)
	{
		char ch;
		printf("server waitng ... \n");
		clientLen = sizeof(clientAddress);
		clientfd = accept(serverSocket, (struct  sockaddr *) &clientAddress, &clientLen);
		if(errno == EWOULDBLOCK)
		{
			perror("No client to connect: ");
			sleep(1);
			continue;
		}
		read(clientfd, &ch, 3);
		printf("client says : %c \n", ch);
		ch = my_char++;
		printf("sending client: %c \n", ch);
		write(clientfd, &ch, 1);
	}

	close(serverSocket);
	close(clientfd);
	return 0;
}
