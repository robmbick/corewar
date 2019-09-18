/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_line_up_non.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 10:58:18 by bnetschu          #+#    #+#             */
/*   Updated: 2019/05/06 11:03:01 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int				h_found_line_up_non(int *num, int i, char *str, int k)
{
	i++;
	num[3] = 0;
	while (str[i] == '+')
		i++;
	while (str[i] == '#')
		i++;
	if (str[i] == '-')
	{
		k = -1;
		i++;
		while (str[i] == '-')
			i++;
	}
	while (str[i] == '#' || str[i] == '-' || str[i] == '+')
		i++;
	return (((k) * ft_atoi1(&str[i])));
}

static int				h_found_line_up_non1(int *num, int i, char *str, int k)
{
	if ((str[i] == '0' && (str[i + 1] >= '0' && str[i + 1] <= '9')) ||
	(str[i] == '0' && str[i + 1] == '#') || (str[i] == '0' &&
	(str[i + 1] == '-' || str[i + 1] == '+')))
	{
		num[3] = 0;
		i++;
	}
	if (str[i] == '-')
	{
		k = -1;
		i++;
	}
	while (str[i] == '#' || str[i] == '-' || str[i] == '+')
		i++;
	return ((k * ft_atoi1(&str[i])));
}

static int				h_found_line_up_non2(char *str, int i, int *num, int z)
{
	if (str[i] == '0' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
		num[3] = 0;
	if (z == 0)
		return ((-1) * ft_atoi1(&str[i + 1]));
	return (ft_atoi1(&str[i + 1]));
}

static int				hh_nno(char *str, int i)
{
	if ((str[i] >= '0' && str[i] <= '9') || ((str[i] == '-'
	|| str[i] == '+') && (str[i + 1] >= '0' && str[i + 1] <= '9')))
		return (1);
	return (0);
}

int						found_line_up_non(char *str, int i, int *num, int k)
{
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			while (h_nno(str, i) == 1)
			{
				if (str[i] == '0' && str[i + 1] == '+')
					return (h_found_line_up_non(num, i, str, k));
				else if (str[i] == '#' && (str[i + 1] >= '0' &&
				str[i + 1] <= '9') && str[i - 1] == '-')
					return (h_found_line_up_non2(str, i, num, 0));
				else if (str[i] == '#' && (str[i + 1] >= '0' &&
				str[i + 1] <= '9') && str[i - 1] == '+')
					return (h_found_line_up_non2(str, i, num, 1));
				else if (hh_nno(str, i) == 1)
					return (h_found_line_up_non1(num, i, str, k));
				i++;
			}
			if (str[i] == '%')
				return (0);
		}
		i++;
	}
	return (0);
}
