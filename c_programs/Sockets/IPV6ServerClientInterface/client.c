/**
 * @file client.c
 * @author Braiden Gole
 * @brief This is the client side to the server/client side interface.
 * @version 0.1
 * @date 2021-04-19
 * @copyright Copyright (c) Braiden Gole 2021
 */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAXSIZE 500
#define IPV6LOCALHOST "0:0:0:0:0:0:0:0"
   
int main(void)
{
    int socketDescriptor = 0;
    struct sockaddr_in6 address;

    socketDescriptor = socket(AF_INET6, SOCK_STREAM, 0);
    if (socketDescriptor == -1)
    {
        fprintf(stderr, "Error in socket !\n");
        return 1;
    }
   
    address.sin6_family = AF_INET6;
    address.sin6_port = htons(PORT);
       
    int conversion = inet_pton(AF_INET6, IPV6LOCALHOST, &address.sin6_addr);
    if(conversion == -1) 
    {
        fprintf(stderr, "Invalid ip address !\n");
        return 1;
    }
    
    int connected = connect(socketDescriptor, (struct sockaddr *)&address, sizeof(address));
    if (connected == -1)
    {
        fprintf(stderr, "CONNECTION FAILED !\n");
        return 1;
    }
    else
    {
        char buffer[MAXSIZE] = {""};
        char message[MAXSIZE] = {"Hi server this is the client"};

        send(socketDescriptor, message, strlen(message), 0);
        printf(" -- Client side -- \n");
        read(socketDescriptor, buffer, MAXSIZE);
        printf("\t%s\n", buffer);
    }
    return 0;
}