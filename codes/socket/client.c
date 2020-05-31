#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>

#define SERVER_HOST "192.168.0.101"
#define SERVER_PORT 8888
#define RECEIVE_BUFFER_SIZE 1024

unsigned int get_addr();

int main(int argc, char** argv)
{
    int rec_bytes;
    char buffer[RECEIVE_BUFFER_SIZE] = {0};
    printf("client...\n");
    int client_socket;
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(-1 == client_socket)
    {
        perror("socket:");
        return -1;
    }
    printf("socket...\n");

    struct sockaddr_in s_addr, c_addr;
    memset(&s_addr, 0, sizeof(struct sockaddr_in));
    s_addr.sin_family = AF_INET;
    s_addr.sin_addr.s_addr = get_addr();
    s_addr.sin_port = htons(SERVER_PORT);

    if(-1 == connect(client_socket, (struct sockaddr *)(&s_addr), sizeof(struct sockaddr)))
    {
        perror("connect:");
        return -1;
    }
    printf("connect...\n");

    if(-1 != (rec_bytes = read(client_socket, buffer, RECEIVE_BUFFER_SIZE)))
    {
        buffer[rec_bytes] = '\0';
        printf("%s\r\n", buffer);
    }

    close(client_socket);

    return 0;
}

unsigned int get_addr()
{
    int addr_1 = 192;
    int addr_2 = 168;
    int addr_3 = 0;
    int addr_4 = 101;

    unsigned int IP_Int = addr_1 + (addr_2 * 256) + (addr_3 * 256 * 256) + (addr_4 * 256 * 256 *256);
    return IP_Int;
}
