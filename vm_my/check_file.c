/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 14:46:34 by bnetschu          #+#    #+#             */
/*   Updated: 2019/09/17 16:20:19 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

///char		*ft_itoa_base(unsigned long long int nbr, int base, int x) x = 'a'

void        check_open(t_deskriptor *des)
{
	char	buf[100];
	char	*magic;

	ft_bzero(buf, 100);
	if ((des->fd = open(des->name, O_RDONLY)) < 0)
	{
		ft_printf(RED"ERROR not found %s\n"RESET, des->name);
		exit (1);
	}
	magic = ft_itoa_base(COREWAR_EXEC_MAGIC, 16, 'a');
	ft_printf("%s\n", magic);
	if (read(des->fd, buf, 20) <= 0)
	{
		ft_printf("%s\n", buf);
		ft_printf(RED"ERROR where magic header ?\n"RESET);
		exit(1);
	}
	ft_printf("%s\n", buf);
	if (ft_strcmp(magic, &buf[2]))
	{
		ft_printf(RED"ERROR in magic header!!\n"RESET);
		exit(1);
	}
}

void        check_file()
{
    t_deskriptor    *des;

    des = g_deskript;
    while (des != NULL)
    {
        check_open(des);
        des = des->next;
    }
}