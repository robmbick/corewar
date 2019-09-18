# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/29 12:01:09 by bnetschu          #+#    #+#              #
#    Updated: 2019/06/06 16:02:36 by bnetschu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c ft_bzero.c ft_cat.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_sqrt.c ft_str_capitalizer.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_strword.c ft_tolower.c ft_toupper.c ft_concat_params.c get_next_line.c ft_abs.c fff.c ft_atoi1.c ft_printf.c flag_c.c ft_putchar1.c ft_bzero1.c flag_s.c ft_strjoin1.c non_flag.c flag_u.c ft_itoa_ulong.c ft_itoa_base.c flag_x.c flag_p.c flag_o.c flag_i.c flag_f.c ft_round_f.c ft_round_hf.c cop_from_str_c.c cop_from_str_s.c found_line_up_s.c write_s.c hh_pars.c found_line_up_non.c cop_from_str_o.c cop_from_str_p.c found_line_up_p.c cop_from_str_u.c cop_from_str_x.c found_line_up_x.c found_line_up_i.c cop_from_str_i.c ft_cast_i.c found_line_up_i_h.c found_line_up_f.c cop_from_str_f.c found_line_up_f_h.c dod_f.c

HEADER = libft.h

OBJ = $(SRC:.c=.o)

all:$(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ) $(HEADER)
$(OBJ):	$(SRC) $(HEADER)
	@gcc -Wall -Wextra -Werror -c -I $(HEADER) $(SRC)
clean:
	@rm -f $(OBJ)
fclean:clean
	@rm -f $(NAME)
re:fclean all
