/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_line_up_i.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 17:56:27 by bnetschu          #+#    #+#             */
/*   Updated: 2019/09/12 18:57:40 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		hh_f_i1(char *str, int *f_k)
{
	if (str[f_k[2]] == '.')
	{
		f_k[2]++;
		while (str[f_k[2]] >= '0' && str[f_k[2]] <= '9')
			f_k[2]++;
	}
	while (str[f_k[2]] == 'h' || str[f_k[2]] == 'l')
		f_k[2]++;
	if (str[f_k[2]] == '0' && (str[f_k[2] + 1] == 'd'
	|| str[f_k[2] + 1] == 'i'))
		f_k[2]++;
}

static int		hh_found_line_up_i(int *num, char *str, int z, int *f_k)
{
	if (z == 1)
	{
		num[8] = 1;
		return (0);
	}
	else
	{
		num[8] = 1;
		return (ft_atoi1(&str[f_k[2] - 1]));
	}
}

static int		h_found_line_up_i(char *str, int *num, int *f_k)
{
	int z;

	z = 0;
	z = hh_f_i(z, str, f_k);
	if (str[f_k[2]] == '0' && str[f_k[2] + 1] == '.' && str[f_k[2] + 2] == '0')
		return (hh_found_line_up_i(num, str, 1, f_k));
	hh_f_i1(str, f_k);
	if (str[f_k[2]] == 'i' || str[f_k[2]] == 'd')
		return (hh_found_line_up_i(num, str, 1, f_k));
	else if (z == 1)
		return (hh_found_line_up_i(num, str, 0, f_k));
	else if (str[f_k[2]] == '0' && str[f_k[2] + 1] >= '0'
	&& str[f_k[2] + 1] <= '9')
	{
		f_k[0] = f_k[2];
		h_found_line_up_i11(str, f_k);
		if (str[f_k[2]] == 'd' || str[f_k[2]] == 'i')
		{
			num[4] = 0;
			num[8] = 1;
			return (ft_atoi1(&str[f_k[0]]) - 1);
		}
	}
	f_k[1] = 0;
	return (-1000);
}

static int		h_found_line(char *str, int i, int *num, int *f_k)
{
	i++;
	while (h_nno(str, i) == 1)
	{
		if (str[i] == '0' && str[i + 1] == '+')
			return (h_f_up_i1(str, num, i));
		else if ((str[i] >= '0' && str[i] <= '9') || ((str[i] == '-'
		|| str[i] == '+') && (str[i + 1] >= '0' && str[i + 1] <= '9')))
			return (h_f_up_i(str, num, f_k[2], i));
		else if (str[i] == '+')
			return (h_f_up_i2(str, num, i));
		else if (str[i] == '-')
			return (h_f_up_i_3(str, num, i));
		else if (str[i] == ' ' && str[f_k[2]] == ' ')
		{
			f_k[1] = 1;
			f_k[3] = h_found_line_up_i(str, num, f_k);
			if (f_k[1] == 1)
				return (f_k[3]);
		}
		i++;
	}
	return (0);
}

int				found_line_up_i(char *str, int i, int *num)
{
	int f_k[4];

	f_k[2] = i + 1;
	while (str[i])
	{
		if (str[i] == '%')
			return (h_found_line(str, i, num, f_k));
		i++;
	}
	return (0);
}
