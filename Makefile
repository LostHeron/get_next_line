NAME = main.out 
CC = cc
FLAGS = -Wall -Wextra -Werror -g3

SRC  = get_next_line.c \
	   add_node_change_buff.c \
	   ft_strlen.c \
	   get_string.c \
	   lst_clear.c \
	   lst_print.c \
	   main.c \

OBJ = $(SRC:.c=.o)

DFILES = $(OBJ:.o=.d)

all : $(NAME)

$(NAME) : $(OBJ) 
	$(CC) $(FLAGS) $^ -o $@

-include $(DFILES)

%.o : %.c
	$(CC) -c $(FLAGS) -MMD -MP $< -o $@

clean : 
	rm -f $(OBJ)
	rm -f $(DFILES)

fclean :
	$(MAKE) clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all
