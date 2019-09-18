/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 16:11:18 by bnetschu          #+#    #+#             */
/*   Updated: 2018/11/02 09:12:17 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

#include "libft.h"

static void	ft_perebor(char **argv, char *str, int ct, int td)
{
	int i;

	i = 1;
	while (argv[i])
	{
		td = open(argv[i], O_RDONLY);
		if (td < 0)
		{
			ft_putstr(argv[i]);
			write(1, " : No such file or directory\n", 29);
		}
		while (1)
		{
			ct = read(td, str, 4096);
			if (ct <= 0)
				break ;
			str[ct] = '\0';
			write(1, str, ct);
		}
		i++;
	}
	close(td);
}

void		ft_cat(int argc, char **argv)
{
	int		td;
	int		ct;
	char	str[4096 + 1];

	ct = 0;
	td = 0;
	if (argc == 1)
	{
		while (1)
		{
			ct = read(0, str, 4096);
			write(1, str, ct);
		}
	}
	if (argc < 2)
		;
	else
	{
		ft_perebor(argv, str, ct, td);
	}
}
