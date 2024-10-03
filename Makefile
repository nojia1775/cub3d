CC = cc

CFLAGS = -Wall -Wextra -Werror -g

OBJS_DIR = obj

SRCS = src/main.c \
	src/parsing.c \
	src/init.c \
	src/chained_list.c \
	src/free.c \
	src/utils.c \
	src/utils2.c \
	src/parsing_floor_ceiling.c \
	src/extract_map.c

OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)

NAME = cub3d

$(NAME): $(OBJS)
	@make bonus -C libft/
	@make -C minilibx-linux/
	$(CC) $(CFLAGS) $^ -o $@ libft/libft.a minilibx-linux/libmlx_Linux.a -lm -lXext -lX11 -lz -g
	
$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

all: $(NAME)

clean:
	@make clean -C libft/
	@make clean -C minilibx-linux/
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)
	@make fclean -C libft/

re: fclean all

.PHONY: all clean fclean re