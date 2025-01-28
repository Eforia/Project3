#ifndef PROJECTSTD_H
#define PROJECTSTD_H

#define MAX_NAME 256
#define TABLE_SIZE 20
#define CUSTOMER_SIZE 5
#define ORDER_NUM 10

void init_catalog();                      // init of catalog
void order(int product_id, int write_fd); // func for product orders

#endif // end of header file
