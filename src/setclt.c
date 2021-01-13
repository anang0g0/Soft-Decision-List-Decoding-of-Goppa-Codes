#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet.h>
#include <netdb.h>


int setup_client(hostname,port)
char *hostname;
u_short port;
{
	struct hostent *servhost;
	struct sockaddr_in server;
	int s;

	if((servhost=gethostbyname(hostname))==NULL)
	{
		printf("bad hostname!\n");
		return -1;
	}

	bzero((char *)&server,sizeof(server));
	server.sin_family=AF_INET;
	server.sin_port=port;
	bcopy(setvhost->h_addr,(char *)&server.sin_addr,servhost->h_length);
	if((s=socket(AF_INET,SOCK_STREAM,0))<0)
	{
		printf("socket allocation failed.\n");
		return -1;
	}

	if(connect(s,&server,sizeof(server))== -1)
	{
		printf("cannot connect.\n");
		return -1;
	}
	printf("connected.\n");

	return s;
}


