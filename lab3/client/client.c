#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <arpa/inet.h>
int nsock;
int main () {
	int sockfd;
	char c, rc;
	struct sockaddr_in server;
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	server.sin_port = htons(7000);
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		perror("socket error");
		exit(1);
	}
	if (connect(sockfd, (struct sockaddr *) &server, sizeof(server)) == -1) {
		perror("connect error");
		exit(1);
	}
        int cpid;
        cpid = fork();
	if (cpid == 0) {
	    while (recv(sockfd, &c, 1, 0) > 0) {
                 printf("%c", c);
            }
            close(sockfd);
            exit(0);
        }
        else if(cpid != -1){
	    for (rc = '\n';;) {
                if (rc == '\n') {
                        //printf("Enter message:\n");
                }
                c = getchar();
                send(sockfd, &c, 1, 0);
            }
	}
	return 0;
}
