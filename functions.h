#ifndef FUNCTIONS_H
#define FUNCTIONS_H

struct Config {
  int port;
  int verbose;
};

struct Config parse_args(int argc, char* argv[]);
void handleConnection(int a_client, int BUFFER_SIZE, int print);


#endif