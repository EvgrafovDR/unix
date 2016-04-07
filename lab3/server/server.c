#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
int nsock;
int main () {
	int sockfd;
	struct sockaddr_in server;
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(7000);
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		perror("socket error");
		exit(1);
	}
	if (bind(sockfd, (struct sockaddr *) &server, sizeof(server)) == -1) {
		perror("bind error");
		exit(1);
	}
	if (listen(sockfd, 5) == -1) {
		perror("listen error");
		exit(1);
	}
	char c;
        char rc;
	for (;;) {
		if ((nsock = accept(sockfd, NULL, NULL)) == -1) {
			perror("accept error");
			continue;
		}
		int cpid;
		cpid = fork();
		if (cpid == 0) {
			while (recv(nsock, &c, 1, 0) > 0) {
				printf("%c", c);
			}
			close(nsock);
			exit(0);
		}
		else if(cpid != -1){
			for (rc = '\n';;) {
				if (rc == '\n') {
					//printf("Enter message:\n");
				}
				c = getchar();
				send(nsock, &c, 1, 0);
			}
		}
		close(nsock);
		exit(0);
	}
	return 0;
}
