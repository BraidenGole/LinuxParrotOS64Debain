/**
 * @file sockets.c
 * @author Braiden Gole
 * @brief This is the server side portion of the socket interface.
 * ---------------------------------------------------------------------------
 * (socket(2) - Linux manual page)
 * [SOURCE/DOCUMENTATION]: https://man7.org/linux/man-pages/man2/socket.2.html
 * ---------------------------------------------------------------------------
 * (socket(7) - Linux manual page)
 * [SOURCE/DOCUMENTATION]: https://man7.org/linux/man-pages/man7/socket.7.html
 * --------------------------------------------------------------------------------------------------
 * (<netinet/in.h> - The open Group Base Specifications)
 * [SOURCE/DOCUMENTATION]: https://pubs.opengroup.org/onlinepubs/009695399/basedefs/netinet/in.h.html
 * --------------------------------------------------------------------------------------------------
 * @version 0.1
 * @date 2021-04-18
 * @copyright Copyright (c) Braiden Gole 2021 
 */
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080
#define MAXSIZE 500

int main(void)
{   
    // AF_INET6: IPV6
    // TCP: SOCK_STREAM
    int socketDescriptor = 0;
    socketDescriptor = socket(AF_INET6, SOCK_STREAM, 0);
    if (socketDescriptor == 0)
    {   
        fprintf(stderr, "Socket failed !");
        return 1;
    }

    // Set the socket option to true, or false
    // SOL_SOCKET: This is the actual socket layer itself.
    // SO_REUSEADDR: Indicates that the rules used in validating the addresses
    //               supplied in a bind(2) call should allow the reuse of local addresses.
    // SO_REUSEPORT: Permits multiple AF_INET or AF_INET6 sockets to be bound to an identical socket address.
    int option = 1;
    int setSockOp = setsockopt(socketDescriptor, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &option, sizeof(option));
    if (setSockOp == -1)
    {
        fprintf(stderr, "Problem 2");
        return 1;
    }

    struct sockaddr_in6 address;
    socklen_t addressSize = sizeof(address);
    address.sin6_family = AF_INET6;

    // Bind socket to any available interface.
    address.sin6_addr = in6addr_any;

    // Convert a unsigned short int from host byte order to network byte order.
    address.sin6_port = htons(PORT);

    int bound = bind(socketDescriptor, (struct sockaddr*)&address, addressSize);
    if (bound == -1)
    {   
        fprintf(stderr, "Problem 3");
        return 1;
    }

    int backlog = 4;
    int listened = listen(socketDescriptor, backlog);
    if (listened == -1)
    {
        fprintf(stderr, "Problem 4");
        return -1;
    }

    
    int newDescriptor = accept(socketDescriptor, (struct sockaddr*)&address, &addressSize);
    if (newDescriptor == -1)
    {
        fprintf(stderr, "accept");
        return 1;
    }
    
    char buffer[MAXSIZE] = {""};
    read(newDescriptor, buffer, MAXSIZE);

    printf("%s\n", buffer);
    char message[MAXSIZE] = {"Braiden Gole"};

    send(newDescriptor, message, strlen(message), 0);
    printf("Message was sent !\n");
    return 0;
}
