NAME = libft.a
CFLAGS = -I ./libft.h -Wall -Wextra -Werror
SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
		ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
		ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
		ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
		ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
		ft_calloc.c ft_strdup.c ft_strncmp.c ft_substr.c \
		ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
		ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
		ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		get_next_line.c myprintf.c myprintf_char.c \
		myprintf_deci.c myprintf_hex.c \
		ft_atoibase.c

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
		ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
		ft_lstclear.c ft_lstiter.c ft_lstmap.c \
		get_next_line_bonus.c 

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(BONUS:.c=.o)

ifdef ALLOW_BONUS
	OBJ_TEMP = $(OBJS) $(OBJS_BONUS)
else 
	OBJ_TEMP = $(OBJS)
endif

all : $(NAME)

$(NAME) : $(OBJ_TEMP)
	ar -rc libft.a $(OBJ_TEMP)

clean:
	rm -rf $(OBJS) $(OBJS_BONUS)

bonus: $(OBJ_TEMP)
	# sleep 1
	@$(MAKE) ALLOW_BONUS=1 $(NAME)

fclean: clean
	rm -rf $(NAME) libftprintf.a

re : fclean all

.PHONY : all clean fclean re 