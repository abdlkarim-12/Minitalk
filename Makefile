CC = CC

CFLAGS = -Wall -Wextra -Werror

SRC = utils.c

SRC_C = client.c

SRC_S = server.c

SERVER = server

CLIENT = client

all : $(SERVER) $(CLIENT)

$(SERVER): $(SRC_S) $(SRC)
	$(CC) $(CFLAGS) $^ -o $@

$(CLIENT): $(SRC_C) $(SRC)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf $(SERVER) $(CLIENT)

fclean: clean

re: fclean all

.PHONY: clean