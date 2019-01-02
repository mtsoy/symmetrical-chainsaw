#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
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
	int server_sock = socket(domain, type, protocol);
	if(server_sock == -1)
	{
		printf("String 32\n");
		//return 1;
	}
	
	struct sockaddr_in server_addr;
	server_addr.sin_family 	    = AF_UNIX;
	server_addr.sin_port	    = htons(1703);
	server_addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
	int server_addrlen 		    = sizeof(server_addr);
	int err 			        = bind(server_sock, (struct sockaddr*)(&server_addr), server_addrlen);
	if(err == -1)
	{
		printf("String 44\n");
		//return 1;
	}
	
	int backlog = 50;
	err 	    = listen(server_sock, backlog);
	if(err == -1)
	{
		printf("String 52\n");
		//return 1;
	}
	
	struct sockaddr client_addr = {};
	socklen_t client_addrlen = 0;
	int client_sock = accept(server_sock, &client_addr, &client_addrlen);
	if(client_sock == -1)
	{
		printf("String 61\n");
		//return 1;
	}
	
	int len = 20;
	char buf[len];
	err = recv(client_sock, buf, len, 0);
	if(err == -1)
	{
		printf("String 70\n");
		//return 1;
	}
	printf("%s", buf);
	
	scanf("%s", buf);
	err = sendall(client_sock, buf, len, 0);
	{
		printf("String 78\n");
		//return 1;
	}
	
	close(client_sock);
	close(server_sock);
	
	return 0;
}
