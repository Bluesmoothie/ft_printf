.PHONY		: 	all clean fclean re norm

NAME		=	libft.a

#			GCC

CC			=	cc
CFLAGS		= 	-Wall -Wextra -Werror -MMD -MP -I $(INCLUDE)

#			COMMON

BUILD_DIR	=	.build/
SRC_DIR		=	./
INCLUDE		=	./

#			SRC

SRC_FILES	=	ft_isalnum 		\
 				ft_isalpha 		\
				ft_isascii 		\
				ft_isdigit 		\
				ft_isprint 		\
				ft_tolower 		\
				ft_toupper 		\
				ft_bzero 		\
				ft_calloc 		\
				ft_memchr		\
				ft_memcmp 		\
				ft_memcpy 		\
				ft_memmove 		\
				ft_memset 		\
				ft_atoi 		\
				ft_uitoa		\
				ft_strchr 		\
				ft_strdup 		\
				ft_strlcat 		\
				ft_strlcpy 		\
				ft_strlen 		\
				ft_strncmp 		\
				ft_strnstr 		\
				ft_strrchr 		\
				ft_pustr_fd 	\
				ft_putchar_fd 	\
				ft_putendl_fd 	\
				ft_putnbr_fd	\
				ft_itoa 		\
				ft_split 		\
				ft_striteri 	\
				ft_strjoin 		\
				ft_strmapi 		\
				ft_strtrim 		\
				ft_substr 		\

SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(BUILD_DIR), $(addsuffix .o, $(SRC_FILES)))
DEPS 		= 	$(addprefix $(BUILD_DIR), $(addsuffix .d, $(SRC_FILES)))

#			BONUS

BONUS_SRC_FILES	=	$(SRC_FILES)

BONUS_SRC_FILES	+=	ft_lstadd_back_bonus 	\
					ft_lstadd_front_bonus	\
					ft_lstclear_bonus		\
					ft_lstdelone_bonus		\
					ft_lstiter_bonus		\
					ft_lstlast_bonus		\
					ft_lstmap_bonus			\
					ft_lstnew_bonus			\
					ft_lstsize_bonus		\

BONUS_SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(BONUS_SRC_FILES)))
BONUS_OBJ 		= 	$(addprefix $(BUILD_DIR), $(addsuffix .o, $(BONUS_SRC_FILES)))
BONUS_DEPS 		= 	$(addprefix $(BUILD_DIR), $(addsuffix .d, $(BONUS_SRC_FILES)))

#			RULES

all				: $(NAME)

$(NAME)			: $(BUILD_DIR) $(OBJ)
				ar -rcs $(NAME) $(OBJ)

$(BUILD_DIR)	:
				mkdir -p $(BUILD_DIR)

$(BUILD_DIR)%.o	: $(SRC_DIR)%.c
				$(CC) $(CFLAGS) -c $< -o $@

-include $(DEPS)

bonus			: $(BUILD_DIR) $(BONUS_OBJ)
				ar -rcs $(NAME) $(BONUS_OBJ)

-include $(BONUS_DEPS)

norm			:
				norminette $(SRC) $(INCLUDE)

clean			:
				rm -rf $(BUILD_DIR)

fclean			: clean
				rm -f $(NAME)

re				: fclean all