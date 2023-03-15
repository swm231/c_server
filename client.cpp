#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void errif(bool condition, const char *errmsg){
    if(condition){
        perror(errmsg);
        exit(EXIT_FAILURE);
    }
}

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in serv_addr;
    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("8.130.110.118");
    serv_addr.sin_port = htons(8888);

    errif(connect(sockfd, (sockaddr*)&serv_addr, sizeof(serv_addr)) == -1, "socket connect erroe");
    
    char message[100];
    // scanf("%s", message);
    int cnt=10;
    while(cnt --){
        bzero(&message, sizeof message);
        scanf("%s", message);
        char buf[100];
        bzero(&buf, sizeof buf);
        ssize_t write_byte = write(sockfd, &message, strlen(message));
        if(write_byte == -1){
            printf("socket already disconnect");
            break;
        }
        /*
        bzero(&buf, sizeof buf);
        ssize_t read_bytes = read(sockfd, buf, sizeof buf);
        buf[read_bytes]='\0';
        if(read_bytes > 0)
            printf("%s\n",buf);
        if(read_bytes == 0) break;
        else errif(true, "socket read error");
        */
    }
    close(sockfd);
    return 0;
}
