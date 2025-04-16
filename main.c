#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include "functions.h"

#define LISTEN_BACKLOG 10
#define BUFFER_SIZE 1024



int main(int argc, char* argv[]) {

    struct Config config = parse_args(argc, argv);
    int port = config.port;
    int print = config.verbose;

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
        close(socket_fd);
        return 1;
    }
    printf("Successfully binded to port %d\n", port);


        //listn in the socket for some love up to 10 
    returnval = listen(socket_fd, LISTEN_BACKLOG);

    if (returnval < 0) {
        perror("listen");
        close(socket_fd);
        return 1;
    }

    printf("Server listening on port: %d\n", port);
    

    while (1) {

    // Respond when someone connects
    struct sockaddr_in client_address;  //create a place to hold clientes address
    socklen_t client_address_len = sizeof(client_address);  ////create a place to hold length of the addr

    int connection_fd = accept(
            socket_fd, (struct sockaddr*)&client_address, &client_address_len);  //accept by linking the incoming request to the fd and client variables

    if (connection_fd < 0) {
        perror("accept");
        continue;
    }

    printf("Accepted a client\n");
    handleConnection(connection_fd, BUFFER_SIZE, print);
    printf("Client disconnected.\n");
    close(connection_fd);

    }   
    close(socket_fd);



    return 0;
}