CC = cc

CFLAGS = -Wall -Wextra -Werror

CNAME = client

SNAME = server

RM = rm -f

SRC = utils.c

SRC_C = client.c

SRC_S = server.c

HEADER = minitalk.h

OBJ = $(SRC:.c=.o)

COBJ = $(SRC_C:.c=.o)

SOBJ = $(SRC_S:.c=.o)

all: $(CNAME) $(SNAME)

$(CNAME): $(OBJ) $(COBJ)
	$(CC) $(CFLAGS) $^ -o $@

$(SNAME): $(OBJ) $(SOBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(COBJ) $(SOBJ)

fclean: clean
	$(RM) $(SNAME) $(CNAME)

re: fclean all

.PHONY: clean