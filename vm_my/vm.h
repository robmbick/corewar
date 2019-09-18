/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 16:36:35 by bnetschu          #+#    #+#             */
/*   Updated: 2019/09/17 15:32:02 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "op.h"
# include "libft/libft.h"
# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN    "\x1b[36m"
# define RESET   "\x1b[0m"

typedef	struct	s_deskriptor
{
	char				*name; // name
	int					num; // numer player of this bot
	int					fd;
	char				*name_bot;
	char				*comment;
	struct s_code		*code;
	struct s_deskriptor	*next;
}				t_deskriptor;

typedef struct	s_code
{
	char			*code;
	struct s_code	*next;
}				t_code;

t_deskriptor	*g_kostul;
int				g_kost_dump;
t_deskriptor	*g_deskript;
int				g_nbr_cycles;

void	check_file();
int		pars_bot(int argc, char **argv);

#endif