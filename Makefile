UTL_DIR =	utils
UTL_FILES =	ft_atoi.c \
			ft_bzero.c \
			ft_memset.c \
			ft_split.c \
			ft_strdup.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strnstr.c \
			ft_substr.c \
			ft_toupper.c \
			get_next_line.c \
			get_next_line_utils.c
UTL =	$(addprefix $(UTL_DIR)/, $(UTL_FILES))

SRC_DIR =	./srcs
SRC_FILES =	main.c \
			ft_mlx_pixel_put.c \
			ft_line_splited_words.c \
			ft_open_window.c \
			ft_calculation.c \
			ft_color_check.c \
			ft_bresenham_line.c \
			ft_free_struct.c \
			ft_map_init.c \
			ft_struct_init.c
SRC =	$(UTL) $(addprefix $(SRC_DIR)/, $(SRC_FILES))

UTL_BONUS_DIR =		utils/bonus
UTL_BONUS_FILES =	ft_atoi_bonus.c \
					ft_bzero_bonus.c \
					ft_memset_bonus.c \
					ft_split_bonus.c \
					ft_strdup_bonus.c \
					ft_strlcpy_bonus.c \
					ft_strlen_bonus.c \
					ft_strnstr_bonus.c \
					ft_substr_bonus.c \
					ft_toupper_bonus.c \
					get_next_line_bonus.c \
					get_next_line_utils_bonus.c
UTL_BONUS =	$(addprefix $(UTL_BONUS_DIR)/, $(UTL_BONUS_FILES))

BON_DIR =	./bonus
BON_FILES =	main_bonus.c \
			ft_line_splited_words_bonus.c \
			ft_open_window_bonus.c \
			ft_calculation_bonus.c \
			ft_color_check_bonus.c \
			ft_bresenham_line_bonus.c \
			ft_free_struct_bonus.c \
			ft_map_init_bonus.c \
			ft_mlx_pixel_put_bonus.c \
			ft_struct_init_bonus.c
BONUS =	$(UTL_BONUS) $(addprefix $(BON_DIR)/, $(BON_FILES))

OBJ_DIR = ./objs
OBJ =	$(addprefix $(OBJ_DIR)/, $(UTL:.c=.o)) $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

OBJ_BONUS_DIR = ./objs/bonus
OBJ_BONUS =	$(addprefix $(OBJ_BONUS_DIR)/utils/, $(UTL_BONUS_FILES:.c=.o)) $(addprefix $(OBJ_BONUS_DIR)/, $(BON_FILES:.c=.o))

NAME = fdf

BONUS_NAME = fdf_bonus

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -O3 -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/$(UTL_DIR)/%.o: $(UTL_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_NAME): $(OBJ_BONUS)
	$(CC) $(CFLAGS) -O3 -lmlx -framework OpenGL -framework AppKit -o $(BONUS_NAME) $(OBJ_BONUS)

$(OBJ_BONUS_DIR)/%.o: $(BON_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_BONUS_DIR)/utils/%.o: $(UTL_BONUS_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

clean_bonus:
	rm -f $(OBJ_BONUS)

fclean_bonus: clean_bonus
	rm -f $(BONUS_NAME)

re: fclean all

re_bonus: fclean_bonus bonus

.PHONY: all clean fclean re bonus clean_bonus fclean_bonus re_bonus
