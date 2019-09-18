/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_capitalizer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 16:01:37 by bnetschu          #+#    #+#             */
/*   Updated: 2018/10/31 16:06:35 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_capitalizer(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (((str[i - 1] == ' ' || str[i - 1] == '\n') &&
					(str[i] >= 'a' && str[i] <= 'z')) ||
				(i == 0 && str[i] >= 'a' && str[i] <= 'z'))
			ft_putchar(str[i] - 32);
		else if (((str[i] >= 'A' && str[i] <= 'Z') && (str[i - 1] != ' ' &&
					str[i - 1] != '\n')) && i != 0)
			ft_putchar(str[i] + 32);
		else
			ft_putchar(str[i]);
		i++;
	}
}

void		ft_str_capitalizer(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc < 2)
		ft_putchar('\n');
	else
	{
		while (i < argc)
		{
			ft_capitalizer(argv[i]);
			ft_putchar('\n');
			i++;
		}
	}
}
