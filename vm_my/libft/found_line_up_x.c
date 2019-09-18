/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_line_up_x.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 16:43:15 by bnetschu          #+#    #+#             */
/*   Updated: 2019/09/12 18:59:11 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		h_line_up_x(char *str, int i, int *num, int z)
{
	if ((str[i] == '0' && str[i + 1] >= '0' && str[i + 1] <= '9')
	|| (str[i] == '+' && (str[i + 1] >= '0' && str[i + 1] <= '9')))
		num[4] = 0;
	if (z == 0)
		return (ft_atoi1(&str[i]));
	else if (z == 1)
		return (ft_atoi1(&str[i + 1]));
	return ((-1) * ft_atoi1(&str[i + 1]));
}

int				found_line_up_x(char *str, int i, int *num)
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
					return (h_line_up_x(str, i, num, 2));
				else if (str[i] == '#' && (str[i + 1] >= '0'
				&& str[i + 1] <= '9') && str[i - 1] == '+')
					return (h_line_up_x(str, i, num, 1));
				else if ((str[i] >= '0' && str[i] <= '9') || ((str[i] == '-'
				|| str[i] == '+') && (str[i + 1] >= '0' && str[i + 1] <= '9')))
					return (h_line_up_x(str, i, num, 0));
				i++;
			}
			if (str[i] == 'x' || str[i] == 'X')
				return (0);
		}
		i++;
	}
	return (0);
}

static int		h_cast_x(char *str, int i, int *h)
{
	while (str[i] != 'X' && str[i] != 'x')
	{
		if (str[i] == 'h')
			h[0]++;
		if (str[i] == 'l')
			h[1]++;
		i++;
	}
	return (i);
}

uintmax_t		ft_cast_x(char *str, va_list *argptr, int *z)
{
	int		i;
	int		h[2];

	h[0] = 0;
	h[1] = 0;
	i = *z;
	i = h_cast_x(str, i, h);
	if (h[0] == 0 && h[1] != 0)
	{
		if (h[1] == 1)
			return ((unsigned long int)va_arg(*argptr, void*));
		else if (h[1] >= 2)
			return ((unsigned long long int)va_arg(*argptr, void*));
	}
	else if (h[1] == 0 && h[0] != 0)
	{
		if (h[0] == 2)
			return ((unsigned char)va_arg(*argptr, void*));
		else if (h[0] == 1 || h[0] > 2)
			return ((unsigned short int)va_arg(*argptr, void*));
	}
	return ((unsigned int)va_arg(*argptr, void*));
}

int				found_rigor_x(char *str, int j)
{
	int num;
	int k;

	k = 0;
	num = -2;
	while (str[j] != '%')
		j++;
	while (str[j] != 'x' && str[j] != 'X')
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
