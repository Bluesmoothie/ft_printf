.PHONY		:	all clean fclean re norm FORCE bonus

NAME		=	libftprintf.a

#			GCC

CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra -MMD -MP -I $(INCLUDE) -g3

#			COMMON

BUILD_DIR	=	.build/
SRC_DIR		=	src/
INCLUDE		=	include/

#			LIBS

LIBFT			=	libft/
LIBFT_A			=	$(addprefix $(LIBFT), libft.a)

#			SRC

SRC_FILES	=	libftprintf		\
				printer_1		\
				printer_2		\
				hex				\
				flags			\
				flags_func		\
				flags_printf	\

SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(BUILD_DIR), $(addsuffix .o, $(SRC_FILES)))
DEPS 		= 	$(addprefix $(BUILD_DIR), $(addsuffix .d, $(SRC_FILES)))

#			RULES

all				:	$(NAME)

$(NAME)			:	$(BUILD_DIR) $(OBJ) $(LIBFT_A)
				cp $(LIBFT_A) .
				mv libft.a $(NAME)
				ar -rcs $(NAME) $(OBJ)

$(BUILD_DIR)	:
				mkdir -p $(BUILD_DIR)

$(BUILD_DIR)%.o	: $(SRC_DIR)%.c
				$(CC) $(CFLAGS) -c $< -o $@

-include $(DEPS)

$(LIBFT_A)		:	FORCE
				$(MAKE) -s -C $(LIBFT)

FORCE:

bonus			:	$(NAME)

norm			:
				norminette $(SRC) $(INCLUDE)

clean			:
				$(MAKE) clean -s -C $(LIBFT)
				rm -rf $(BUILD_DIR)

fclean			:	clean
				$(MAKE) fclean -s -C $(LIBFT)
				rm -f $(NAME)

re				:	fclean all
