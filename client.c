#include "Projectstd.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/un.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

#define SOCKET_PATH "/tmp/eshop_socket"

int main() {


  int sock;
  char buffer[306];
  pid_t ppid[5];
  struct sockaddr_un addr;

  int product_id;
  for (int i = 0; i < 5; i++) {
    if ((ppid[i] = fork()) == -1) {
      perror("fork");
      exit(1);
    }

    if (ppid[i] == 0) {

      // create socket
      if ((sock = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
      }

      // set up address structure

      memset(&addr, 0, sizeof(struct sockaddr_un));
      addr.sun_family = AF_UNIX;
      strcpy(addr.sun_path, SOCKET_PATH);

      // connect to the server

      if (connect(sock, (struct sockaddr *)&addr, sizeof(struct sockaddr_un)) ==
          -1) {
        perror("connect");
        exit(1);
      }

      printf("connected to the server \n");

      // send product id
      for (int i = 0; i < 10; i++) {
        // seed random number gen
        srand((unsigned int)time(NULL));
        product_id = rand() % 20;
        write(sock, &product_id, sizeof(product_id));
        sleep(1);

        ssize_t bytes_read = read(sock, buffer, sizeof(buffer));
        if (bytes_read > 0) {
          buffer[bytes_read] = '\0';
          printf("server: %s", buffer);
        }
        sleep(1);
      }
      close(sock);
      exit(0);
    }
  }

  for (int i = 0; i < 5; i++) {
    waitpid(ppid[i], NULL, 0);  // Wait for each child to finish
  }

  return 0;
}
