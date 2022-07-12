CLIENT_NAME = client
SERVER_NAME = server
SOURCES = 	./utils.c 					\
			./helpers/ft_atoi.c			\
			./helpers/ft_itoa.c			\
			./helpers/ft_putnbr_fd.c	\
			./helpers/ft_putchar_fd.c	\
			./helpers/ft_putstr_fd.c	\
			./helpers/ft_strlen.c		\

CLIENT = client.c $(SOURCES)
SERVER = server.c $(SOURCES)

CLIENTOBJ =	$(CLIENT:.c=.o)
SERVEROBJ =	$(SERVER:.c=.o)

MINITALK_HDR = ./minitalk.h
LIBFT_HDR = ./libft.h

CC = cc
FLAGS = -fsanitize=address -g -Wall -Wextra -Werror
RM = rm -f

all: $(CLIENT_NAME) $(SERVER_NAME)
$(CLIENT_NAME): $(MINITALK_HDR) $(LIBFT_HDR) $(CLIENTOBJ)
	$(CC) $(FLAGS) $(CLIENTOBJ) -o $(CLIENT_NAME)

$(SERVER_NAME): $(MINITALK_HDR) $(LIBFT_HDR) $(SERVEROBJ)
	$(CC) $(FLAGS) $(SERVEROBJ) -o $(SERVER_NAME)

clean:
	$(RM) *.o
	$(RM) */*.o
	$(RM) *.out

fclean: clean
	$(RM) $(CLIENT_NAME)
	$(RM) $(SERVER_NAME)

re:	fclean all

.PHONY: all clean fclean