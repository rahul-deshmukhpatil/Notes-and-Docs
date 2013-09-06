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
	int clientfd;
	int serverLen;
	struct sockaddr_un serverAddress;

	printf("client prosses :\n");

	clientfd = socket(AF_UNIX, SOCK_STREAM,0);

	if(clientfd == -1)
	{
		printf("could not open server socket %d %s\n", errno, strerror(errno));
		exit(-1);
	}

	serverAddress.sun_family = AF_UNIX;	
	strcpy(serverAddress.sun_path, "server_socket");	
	serverLen = sizeof(serverAddress);
	
	if(connect(clientfd, (const struct sockaddr *) &serverAddress, serverLen))
	{
		printf("could not connect to the address : %d %s!!!\n", errno, strerror(errno));
		exit(-1);
	}

	{
		char ch = 'a';
		int ret = 0;
		printf("seding server %c ... \n", ch);
		ret = write(clientfd, &ch, 1);
		if(ret <= 0 )
		{
			printf("Error %d:%s", ret, !ret?strerror(errno):"EOF");
			exit(-1);
		}
		else
			printf("written %d succesfully", ret);
		ret = read(clientfd, &ch, 1);
		
		if(ret <= 0 )
		{
			printf("Error %d:%s", ret, !ret?strerror(errno):"EOF");
			exit(-1);
		}
		else
			printf("read %d succesfully", ret);
		printf("server says : %c \n", ch);
	}

	close(clientfd);
	return 0;
}
