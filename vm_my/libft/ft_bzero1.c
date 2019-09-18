/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 09:55:21 by bnetschu          #+#    #+#             */
/*   Updated: 2019/05/06 11:59:36 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						prom(int i, char *str, char flag)
{
	while (str[i] != flag)
		i++;
	i++;
	return (i);
}

void					ft_bzero1(void *s, unsigned int n)
{
	unsigned long long int	i;
	unsigned char			*dest;

	dest = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
}

int						h_nno(char *str, int i)
{
	if ((str[i] == ' ' && str[i]) || (str[i] >= '0' && str[i] <= '9')
		|| ((str[i] == '-' || str[i] == '+') && (str[i + 1] >= '0' &&
		str[i + 1] <= '9')) || str[i] == 'h' || str[i] == 'l' || str[i] == 'L'
		|| str[i] == '#' || str[i] == '-' || str[i] == '+')
		return (1);
	return (0);
}

static int				h_found_line_up_o(char *str, int i, int *num, int z)
{
	if ((str[i] == '0' && str[i + 1] >= '0' && str[i + 1] <= '9')
	|| (str[i] == '+' && (str[i + 1] >= '0' && str[i + 1] <= '9')))
		num[4] = 0;
	if (z == 0)
		return (ft_atoi1(&str[i]));
	else if (z == 1)
		return (ft_atoi1(&str[i + 1]));
	else
		return ((-1) * ft_atoi1(&str[i + 1]));
}

int						found_line_up_o(char *str, int i, int *num)
{
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			while (h_nno(str, i) == 1)
			{
				if (str[i] == '#' && (str[i + 1] >= '0'
				&& str[i + 1] <= '9') && str[i - 1] == '-')
					return (h_found_line_up_o(str, i, num, 2));
				if (str[i] == '#' && (str[i + 1] >= '0'
				&& str[i + 1] <= '9') && str[i - 1] == '+')
					return (h_found_line_up_o(str, i, num, 1));
				if ((str[i] >= '0' && str[i] <= '9') || ((str[i] == '-'
				|| str[i] == '+') && (str[i + 1] >= '0' && str[i + 1] <= '9')))
					return (h_found_line_up_o(str, i, num, 0));
				i++;
			}
			if (str[i] == 'o')
				return (0);
		}
		i++;
	}
	return (0);
}
