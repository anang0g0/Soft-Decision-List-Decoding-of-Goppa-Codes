#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>


int	setup_server(hostname,port)
char *hostname;
u_short port;
{
	struct hostent	*myhost;
	struct	sockaddr_in	me;
	int	s,s_writing;

	if((myhost=gethostbyname(hostname))==NULL)
	{
		printf("badd hostname\n");
		return -1;
	}

	bzero((char *)&me,sizeof(me));
	me.sin_family=AF_INET;
	me.sin_port=port;
	bcopy(myhost->h_addr,(char *)&me.sin_addr,myhost->h_length);
	if ((s_waiting=socket(AF_INET,SOCK_STREAM,0))<0)
	{
		printf("socket allocation failed.\n");
		return -1;
	}

	if(bind(s_waiting,&me,sizeof(me))== -1)
	{
		printf("cannot bind.\n");
		return -1;
	}
	printf("successfully bound,now listens.\n");

	listen(s_waiting,1);
	s=accept(s_waiting,NULL,NULL);
	close(s_waiting);
	return s;
}


