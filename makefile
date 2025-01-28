# Compiler
CC = clang

# This makes it so the compiler shows all warning messages
CFLAGS = -Wall

# Source files
SRC_CLIENT = client.c
SRC_SERVER = server.c

# Object files
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)

# Executables
EXEC_CLIENT = client
EXEC_SERVER = server

# Default target to build both the client and server
all: $(EXEC_CLIENT) $(EXEC_SERVER)

# Rule to link the client object files and create the client executable
$(EXEC_CLIENT): $(OBJ_CLIENT)
	$(CC) $(OBJ_CLIENT) -o $(EXEC_CLIENT)

# Rule to link the server object files and create the server executable
$(EXEC_SERVER): $(OBJ_SERVER)
	$(CC) $(OBJ_SERVER) -o $(EXEC_SERVER)

# Rule to compile .c files into .o files for client
$(OBJ_CLIENT): $(SRC_CLIENT)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to compile .c files into .o files for server
$(OBJ_SERVER): $(SRC_SERVER)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files and executables
clean:
	rm -f $(OBJ_CLIENT) $(OBJ_SERVER) $(EXEC_CLIENT) $(EXEC_SERVER)


