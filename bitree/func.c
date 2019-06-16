#include <fcntl.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <sys/socket.h>
extern  uint	gLoop=0;
extern	int		iepollfd;
extern int		ilistenfd;



int setnonblocking( int fd )  
{  
    if( fcntl( fd, F_SETFL, fcntl( fd, F_GETFD, 0 )|O_NONBLOCK ) == -1 )  
    {  
        printf("Set blocking error : %d\n", errno);  
        return -1;  
    }  
    return 0;  
}
void iTimeout(){
	gLoop=0;	
}

int GetEpollfd(){
	epoll_fd = epoll_create( MAXEPOLL ); 
	return 	iepollfd;
}

int Setsockopt(int sockfd){
	int	opt=1;
	if (setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt)) == -1)
	{
		perror("setnonblocking");
		exit(EXIT_FAILURE);
	}
	
}
int GetSocket(){
	struct sockaddr_in servraddr;
	struct sockaddr_in clietaddr;	
	struct rlimit	rlt;
	int		len=sizeof(clietaddr);
	servraddr.sin_family	=	AF_INET;
	servraddr.sin_addr.s_addr= htonl(INADDR_ANY);
	servraddr.sin_port=htons(PORT);
	rlt.rlim_max = rlt.rlim_cur = MAXEPOLL;
	
	if ( setrlimit(RLIMIT_NOFILE,&rlt) == -1 )
	{
		printf("Setrlimit Error : %d\n", errno);  
    exit( EXIT_FAILURE );  
	}
	if ( ilistenfd = socket(AF_INET,SOCK_STREAM,0) == -1 )
	{
		perror("socket");
		exit(EXIT_FAILURE);
	}
	if (setnonblocking(ilistenfd))
	{
		perror("setnonblocking");
		exit(EXIT_FAILURE);
	}
	Setsockopt(ilistenfd);
	if ( bind(ilistenfd,(struct sockaddr*)&servraddr,len) == -1)
	{
		printf("Bind Error : %d\n", errno);  
    exit( EXIT_FAILURE );  	
	}
	
}

void  daemon(){
	
}