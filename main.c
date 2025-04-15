#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

#define port 1234
#define LISTEN_BACKLOG 10

int main() {

    // Initialize the socket
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    // Create a struct to hold the socket_address
    struct sockaddr_in socket_address;

    // Set the memory of socket_address to zeros
    memset(&socket_address, '\0', sizeof(socket_address));

    socket_address.sin_family = AF_INET;    //socket_address.socket_addr_in_family = address family: internet meaning IPv4
    socket_address.sin_addr.s_addr = htonl(INADDR_ANY); //socket_address.socket_address_in.socket_address = hostToNetworkLong(Inaddress_any)
                                                            //Binds socket to any IP address available on this machine
    socket_address.sin_port = htons(port);      //socket_address.socket_address_in_port = hostToNetworkLong(port)
                                                            //sets port number socket will listen on 

    printf("Binding to port %d\n", port);

    int returnval;
    returnval = bind(   //associates the socket with the specified IP/port
        socket_fd, (struct sockaddr*)&socket_address, sizeof(socket_address));  //binds to the socket_fd a socketaddress typecasted and the size 
    
    if (returnval < 0) {
        perror("bind");
        return 1;
    }

        //listn in the socket for some love up to 10 
    returnval = listen(socket_fd, LISTEN_BACKLOG);

    // Respond when someone connects
    struct sockaddr_in client_address;
    socklen_t client_address_len = sizeof(client_address);

    while (1) {
        pthread_t thread;
        int* client_fd_buf = malloc(sizeof(int));

        *client_fd_buf = accept(
            socket_fd, (struct sockaddr*)&client_address, &client_address_len);

        printf("Accepted connection on %d\n", *client_fd_buf);
    }

    return 0;
}