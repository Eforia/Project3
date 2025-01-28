# Project3

Description /////////////

This program is supossed to create a pseudo e-shop that is handled between server and client wherein the client is forked multiple times to simulate a number of customers while the server plays the role of the store.

//////////*


HOW TO RUN PROGRAM /////////////////

1) open terminal in the folder containing the client.c and server.c files
2) run the make file by typing "make" (the make file uses clang compiler as default if you are using gcc or any other compiler go into the make file and change CC = clang to CC = gcc)
3) now there should be two executables named server and client now type "./server" in the terminal that will be the server and "./client" in the terminal that will be the client and the program should run


////////////////////

If done correctly the program should print out something like this for the server(numbers varying due to rng):

Server waiting for connections 
Client connected.
client disconnected
Client connected.
client disconnected
Client connected.
client disconnected
Client connected.
client disconnected
Client connected.
client disconnected
Product: Milk , was requested a total of: 1 times with 1 units sold and 0 failed purchases due to insufficient stock
Product: Eggs , was requested a total of: 3 times with 2 units sold and 1 failed purchases due to insufficient stock
Product: Bread , was requested a total of: 5 times with 2 units sold and 3 failed purchases due to insufficient stock
Product: Butter , was requested a total of: 3 times with 2 units sold and 1 failed purchases due to insufficient stock
Product: Cheese , was requested a total of: 3 times with 2 units sold and 1 failed purchases due to insufficient stock
Product: Apples , was requested a total of: 4 times with 2 units sold and 2 failed purchases due to insufficient stock
Product: Bananas , was requested a total of: 1 times with 1 units sold and 0 failed purchases due to insufficient stock
Product: Chicken , was requested a total of: 1 times with 1 units sold and 0 failed purchases due to insufficient stock
Product: Beef , was requested a total of: 4 times with 2 units sold and 2 failed purchases due to insufficient stock
Product: Rice , was requested a total of: 2 times with 2 units sold and 0 failed purchases due to insufficient stock
Product: Pasta , was requested a total of: 1 times with 1 units sold and 0 failed purchases due to insufficient stock
Product: Tomato Sauce , was requested a total of: 1 times with 1 units sold and 0 failed purchases due to insufficient stock
Product: Cereal , was requested a total of: 8 times with 2 units sold and 6 failed purchases due to insufficient stock
Product: Orange Juice , was requested a total of: 0 times with 0 units sold and 0 failed purchases due to insufficient stock
Product: Coffee , was requested a total of: 0 times with 0 units sold and 0 failed purchases due to insufficient stock
Product: Tea , was requested a total of: 4 times with 2 units sold and 2 failed purchases due to insufficient stock
Product: Potatoes , was requested a total of: 4 times with 2 units sold and 2 failed purchases due to insufficient stock
Product: Onions , was requested a total of: 1 times with 1 units sold and 0 failed purchases due to insufficient stock
Product: Sugar , was requested a total of: 3 times with 2 units sold and 1 failed purchases due to insufficient stock
Product: Flour , was requested a total of: 1 times with 1 units sold and 0 failed purchases due to insufficient stock
The total number of attempted sales was: 50, of those 29 were completed while 21 failed totaling 102.150 euros 


and something like this for the client:

connected to the server 
connected to the server 
connected to the server 
connected to the server 
connected to the server 
server: Purchase succesful: Tomato Sauce , the total was: 2.49
server: Purchase succesful: Coffee , the total was: 8.99
server: Purchase succesful: Orange Juice , the total was: 4.29
server: Purchase succesful: Flour , the total was: 2.49
server: Purchase succesful: Beef , the total was: 6.99
server: Purchase succesful: Apples , the total was: 1.89
server: Purchase succesful: Beef , the total was: 6.99
server: Purchase succesful: Orange Juice , the total was: 4.29
server: Purchase succesful: Rice , the total was: 3.99
server: Purchase succesful: Flour , the total was: 2.49
server: Purchase succesful: Tomato Sauce , the total was: 2.49
server: Purchase succesful: Onions , the total was: 1.89
server: Purchase succesful: Onions , the total was: 1.89
server: Purchase failed: Orange Juice is out of stock
server: Purchase failed: Flour is out of stock
server: Purchase succesful: Chicken , the total was: 4.99
server: Purchase succesful: Potatoes , the total was: 2.99
server: Purchase succesful: Butter , the total was: 3.49
server: Purchase failed: Tomato Sauce is out of stock
server: Purchase succesful: Bananas , the total was: 1.29
server: Purchase failed: Tomato Sauce is out of stock
server: Purchase succesful: Cereal , the total was: 3.99
server: Purchase failed: Tomato Sauce is out of stock
server: Purchase succesful: Milk , the total was: 2.99
server: Purchase succesful: Coffee , the total was: 8.99
server: Purchase succesful: Milk , the total was: 2.99
server: Purchase succesful: Butter , the total was: 3.49
server: Purchase failed: Butter is out of stock
server: Purchase succesful: Chicken , the total was: 4.99
server: Purchase succesful: Bananas , the total was: 1.29
server: Purchase failed: Tomato Sauce is out of stock
server: Purchase failed: Chicken is out of stock
server: Purchase succesful: Pasta , the total was: 1.79
server: Purchase succesful: Eggs , the total was: 4.50
server: Purchase failed: Beef is out of stock
server: Purchase succesful: Sugar , the total was: 2.79
server: Purchase failed: Beef is out of stock
server: Purchase failed: Bananas is out of stock
server: Purchase succesful: Cheese , the total was: 5.99
server: Purchase succesful: Cheese , the total was: 5.99
server: Purchase failed: Tomato Sauce is out of stock
server: Purchase succesful: Sugar , the total was: 2.79
server: Purchase succesful: Bread , the total was: 1.99
server: Purchase failed: Sugar is out of stock
server: Purchase succesful: Bread , the total was: 1.99
server: Purchase succesful: Eggs , the total was: 4.50
server: Purchase failed: Bananas is out of stock
server: Purchase failed: Beef is out of stock
server: Purchase failed: Onions is out of stock
server: Purchase failed: Milk is out of stock


////////////////////////////////////////
