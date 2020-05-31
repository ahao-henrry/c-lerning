#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

#define SERVER_PORT 8888

int main(int argc, char** argv)
{
    printf("server...\n");
    int server_socket, client_socket;
    struct sockaddr_in s_addr, c_addr;
    
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(-1 == server_socket)
    {
        perror("new socket:");
        return -1;
    }
    printf("socket inited...\n");

    memset(&s_addr, 0, sizeof(struct sockaddr_in));
    s_addr.sin_family = AF_INET;
    s_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    s_addr.sin_port = htons(SERVER_PORT);
    if(-1 == bind(server_socket, (struct sockaddr *)(&s_addr), sizeof(struct sockaddr)))
    {
        perror("bind:");
        return -1;
    }
    printf("bind...\n");

    if(-1 == listen(server_socket, 10))
    {
        perror("listen:\n");
        return -1;
    }
    printf("listen...\n");

    int sin_size;
    while(1)
    {
        sin_size = sizeof(struct sockaddr_in);
        client_socket = accept(server_socket, (struct sockaddr *)(&c_addr), &sin_size);
        if(-1 == client_socket)
        {
            perror("accept:\n");
            return -1;
        }
        printf("accept...\n");

        if(-1 == write(client_socket, "Hi, surgeon.\r\n", 32))
        {
            perror("write:\n");
            return -1;
        }
        printf("write...\n");

        close(client_socket);
    }
    close(server_socket);

    return 0;
}
