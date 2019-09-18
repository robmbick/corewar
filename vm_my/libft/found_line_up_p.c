/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_line_up_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 14:06:28 by bnetschu          #+#    #+#             */
/*   Updated: 2019/09/12 18:59:45 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		h_line_up_p(char *str, int i, int *num, int z)
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

int				found_line_up_p(char *str, int i, int *num)
{
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			while (h_nno(str, i) == 1)
			{
				if (str[i] == '#' && (str[i + 1] >= '0' &&
				str[i + 1] <= '9') && str[i - 1] == '-')
					return (h_line_up_p(str, i, num, 2));
				if (str[i] == '#' && (str[i + 1] >= '0' &&
				str[i + 1] <= '9') && str[i - 1] == '+')
					return (h_line_up_p(str, i, num, 1));
				if ((str[i] >= '0' && str[i] <= '9') || ((str[i] == '-'
				|| str[i] == '+') && (str[i + 1] >= '0' && str[i + 1] <= '9')))
					return (h_line_up_p(str, i, num, 0));
				i++;
			}
			if (str[i] == 'p')
				return (0);
		}
		i++;
	}
	return (0);
}

int				found_rigor_p(char *str, int j)
{
	int num;
	int k;

	k = 0;
	num = -2;
	while (str[j] != '%')
		j++;
	while (str[j] != 'p')
	{
		if (k == 0 && str[j] == '.')
			num = -1;
		if (str[j] == '.' && (str[j + 1] >= '0' && str[j + 1] <= '9'))
		{
			k = 1;
			num = ft_atoi1(&str[j + 1]);
			if (num == 2147483647)
				num = 0;
		}
		j++;
	}
	return (num);
}

void			found_oktorp_p(char *str, int i, int *num)
{
	num[6] = 1;
	while (str[i] != 'p')
	{
		if (str[i] == '#')
			num[6] = 1;
		i++;
	}
	num[7] = 97;
}
