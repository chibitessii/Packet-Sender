#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <stdio.h>
#include <netdb.h>
#include <unistd.h>
 
#define BUF_SIZE 1024
 
int main(){
 
struct addrinfo hints, *res;
int sockfd;
 
memset(&hints, 0, sizeof hints);
hints.ai_family = AF_UNSPEC;  
hints.ai_socktype = SOCK_STREAM;
 
getaddrinfo("www.google.com", "80", &hints, &res);
 
sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
 
if (connect(sockfd, res->ai_addr, res->ai_addrlen) == 0) {
 
    printf("connected\n");
   
    char *msg = "PING!\n";
    int len, bytes_sent;
    int leng, bytes_recv, size;
    char buf[BUF_SIZE];

    bytes_sent = send(sockfd, msg, len, 0);
 
 
    while (bytes_recv = recv(sockfd, &buf, sizeof(buf), MSG_PEEK)){
 
        int count = recv(sockfd, &buf, sizeof(buf), 0);
        if (count == -1)
        {
            perror("error");
            close(sockfd);
        }
        if (count == 0)
        {
            close(sockfd);
            printf("Buffer is %.*s\n", count, buf);
 
        }
        if (count > 0)
        {
            fprintf(stdout, "Buffer is %.*s\n", count, buf);
        }
 
}
 
    close(sockfd);
 
}
 
else {
   
    printf("NOT CONNECTED\n");
 
    }
 
return 0;
 
}