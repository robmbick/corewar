/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 18:47:40 by bnetschu          #+#    #+#             */
/*   Updated: 2019/05/10 14:52:47 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar1(char c)
{
	write(1, &c, 1);
}

void	ft_ever_nul(char *str, int i, int n)
{
	while (i < n)
	{
		str[i] = '0';
		i++;
	}
}

void	f_else_double(int *i, long double nbr_d, __int128_t nbr, char *str_else)
{
	int r;

	while (1)
	{
		i[1] = 0;
		nbr_d *= 10;
		r = nbr_d;
		nbr = nbr_d;
		nbr_d -= r;
		str_else[i[0]] = (nbr % 10) + '0';
		i[1]++;
		if (i[1] >= 6 || i[0] > i[2] + 6)
		{
			(i[0] - i[1] > 6) ? (str_else[i[0] - i[1] + 1] = '\0')
								: (str_else[6] = '\0');
			break ;
		}
		i[0]++;
	}
}

char	*f_inf(char *s, int i)
{
	if (i == 0)
	{
		s[0] = 'i';
		s[1] = 'n';
		s[2] = 'f';
	}
	else
	{
		s[0] = '-';
		s[1] = 'i';
		s[2] = 'n';
		s[3] = 'f';
	}
	return (s);
}
