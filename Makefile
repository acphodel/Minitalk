SERVER = server
CLIENT = client

CFLAGS = -Wall -Werror -Wextra
FLAGS = -Wall -Wextra -Werror -Ift_printf/ft_printf.h -Lft_printf -lftprintf

PRINTF =

all:
	make -s -C ft_printf
	gcc $(FLAGS) server.c -o $(SERVER)
	gcc $(FLAGS) client.c -o $(CLIENT)

clean:
	make clean -s -C ft_printf

fclean: clean
	make fclean -s -C ft_printf
	rm -f $(SERVER) $(CLIENT)

re: fclean all