#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include "functions.h"


struct Config parse_args(int argc, char* argv[]) {

  struct Config config = {1234, 0};

  for (int i = 1; i < argc; i++) {
    if (strcmp(argv[i], "-p") == 0 && i + 1 < argc) {
        config.port = atoi(argv[i+1]);
        i++;
    }
    if (strcmp(argv[i], "-v") == 0) {
        config.verbose = 1;
    }
}
  return config;

}

// Reads from a client and writes back depending on print parameter (true or false)
void handleConnection(int client_fd, int BUFFER_SIZE, int print) {

  int returnval;
  char buffer[BUFFER_SIZE];

  write(client_fd, "Hello from server!\n", 19);

  while((returnval = read(client_fd, (void*)&buffer, sizeof(buffer))) > 0) {
      buffer[returnval] = '\0';

      if (print) {
          printf("Recieved: %s", buffer);
      }

      ssize_t bytes_written = write(client_fd, (void*)buffer, (size_t)returnval);

      if (bytes_written < 0) {
        perror("write");
      }
  }
}
