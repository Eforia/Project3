#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

#define SOCKET_PATH "/tmp/eshop_socket"

#define MAX_NAME 256
#define TABLE_SIZE 20
#define CUSTOMER_SIZE 5
#define ORDER_NUM 10

// struct to store report data
typedef struct report {
  int total_sales;
  int failed_s; // total failed pruchase attempts
  float total;  // total sum of money generated
} report;

// struct to store product data
typedef struct product {
  char description[MAX_NAME]; // name of product
  int item_count;
  float price;
  int req;  // total requests
  int freq; // failed requests
} product;

report final = {0, 0, 0};
product catalog[TABLE_SIZE];

void init_catalog() {
  product temp_catalog[TABLE_SIZE] = {
      {"Milk", 2, 2.99, 0, 0},     {"Eggs", 2, 4.50, 0, 0},
      {"Bread", 2, 1.99, 0, 0},    {"Butter", 2, 3.49, 0, 0},
      {"Cheese", 2, 5.99, 0, 0},   {"Apples", 2, 1.89, 0, 0},
      {"Bananas", 2, 1.29, 0, 0},  {"Chicken", 2, 4.99, 0, 0},
      {"Beef", 2, 6.99, 0, 0},     {"Rice", 2, 3.99, 0, 0},
      {"Pasta", 2, 1.79, 0, 0},    {"Tomato Sauce", 2, 2.49, 0, 0},
      {"Cereal", 2, 3.99, 0, 0},   {"Orange Juice", 2, 4.29, 0, 0},
      {"Coffee", 2, 8.99, 0, 0},   {"Tea", 2, 3.50, 0, 0},
      {"Potatoes", 2, 2.99, 0, 0}, {"Onions", 2, 1.89, 0, 0},
      {"Sugar", 2, 2.79, 0, 0},    {"Flour", 2, 2.49, 0, 0}};
  for (int i = 0; i < TABLE_SIZE; i++) {
    catalog[i] = temp_catalog[i];
  }
}

void order(int product_id, int write_fd) {
  char answer[MAX_NAME + 50];
  // using snprintf we can store a message in the answer variable and write that
  // the pipe
  if (product_id < 0 || product_id >= TABLE_SIZE) {
    snprintf(answer, sizeof(answer), "Error, nonexistant product ID: %d\n",
             product_id);
  } else if (catalog[product_id].item_count > 0) {
    catalog[product_id].item_count--;
    catalog[product_id].req++;
    final.total += catalog[product_id].price;
    snprintf(answer, sizeof(answer),
             "Purchase succesful: %s , the total was: %.2f\n",
             catalog[product_id].description, catalog[product_id].price);
  } else {
    catalog[product_id].req++;
    catalog[product_id].freq++;
    snprintf(answer, sizeof(answer), "Purchase failed: %s is out of stock\n",
             catalog[product_id].description);
  }
  write(write_fd, answer, strlen(answer) + 1);
}

int main() {
  init_catalog();
  int server_sock, client_sock;
  struct sockaddr_un addr;
  // create a socket
  if ((server_sock = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
    perror("socket");
    exit(1);
  }

  // remove preexisting socket file

  unlink(SOCKET_PATH);

  // set up the address structure

  memset(&addr, 0, sizeof(struct sockaddr_un));
  addr.sun_family = AF_UNIX;
  strcpy(addr.sun_path, SOCKET_PATH);

  // bind the socket to the address
  if (bind(server_sock, (struct sockaddr *)&addr, sizeof(struct sockaddr_un)) ==
      -1) {
    perror("bind");
    exit(1);
  }

  // listen for connections

  if (listen(server_sock, 5) == -1) {
    perror("listen");
    exit(1);
  }

  printf("Server waiting for connections \n");

  int product_id;
  int client_id = 0;
  while (1) {
    // Accept a client connection
    if ((client_sock = accept(server_sock, NULL, NULL)) == -1) {
      perror("accept");
      continue; // Don't exit, just try accepting a new connection
    }

    printf("Client connected.\n");
    client_id++;
    while (1) {
      ssize_t bytes_read = read(client_sock, &product_id, sizeof(product_id));
      if (bytes_read > 0) {
        order(product_id, client_sock);
      } else {
        break;
      }
    }
    printf("client disconnected\n");
    close(client_sock);
    sleep(1);
    if(client_id == 5)
    {
      break;
    }
  }

  for (int i = 0; i < TABLE_SIZE; i++) {
    printf("Product: %s , was requested a total of: %d times with %d units "
           "sold and %d failed purchases due to insufficient stock\n",
           catalog[i].description, catalog[i].req, 2 - catalog[i].item_count,
           catalog[i].freq);
    final.total_sales += catalog[i].req;
    final.failed_s += catalog[i].freq;
  }

  printf("The total number of attempted sales was: %d, of those %d were "
         "completed while %d failed totaling %.3f euros \n",
         final.total_sales, final.total_sales - final.failed_s, final.failed_s,
         final.total);

  close(server_sock);
  unlink(SOCKET_PATH);

  return 0;
}
