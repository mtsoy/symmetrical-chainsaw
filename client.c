#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdio.h>

int sendall(int s, char *buf, int len, int flags)
{
	int total = 0;
	int n;
	
	while(total < len)
	{
		n = send(s, buf + total, len - total, flags);
		if(n == -1) {
			break;
		}
		
		total += n;
	}
	
	return (n == -1 ? -1 : total);
}

int main()
{
	int domain      = AF_UNIX;
	int type        = SOCK_STREAM;
	int protocol    = 0;
	int my_sock = socket(domain, type, protocol);
	if(my_sock == -1)
	{
		printf("String 32\n");
		//return 1;
	}
	
	struct sockaddr_in server_addr;
	server_addr.sin_family 	    = AF_UNIX;
	server_addr.sin_port	    = htons(1703);
	server_addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
	int server_addrlen 		    = sizeof(server_addr);
	int err = connect(my_sock, (struct sockaddr*)(&server_addr), server_addrlen);
	if(err == -1)
	{
		printf("String 44\n");
		//return 1;
	}
	
	int len = 20;
	char buf[len];
	scanf("%s", buf);
	err = sendall(my_sock, buf, len, 0);
	{
		printf("String 53\n");
		//return 1;
	}
	
	err = recv(my_sock, buf, len, 0);
	if(err == -1)
	{
		printf("String 60\n");
		//return 1;
	}
	printf("%s", buf);
	
	close(my_sock);
	
	return 0;
}
