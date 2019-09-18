/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_line_up_f.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 12:35:24 by bnetschu          #+#    #+#             */
/*   Updated: 2019/09/12 18:55:06 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				h_f_line_f3(int *num, int z, char *str, int *f_k)
{
	if (z == 1)
	{
		num[8] = 1;
		return (0);
	}
	else
	{
		num[8] = 1;
		return (ft_atoi1(&str[f_k[1] - 1]));
	}
}

void			h_f_line_f4(char *str, int *f_k)
{
	while ((str[f_k[1]] >= '0' && str[f_k[1]] <= '9') ||
		str[f_k[1]] == '.' || str[f_k[1]] == 'L')
		f_k[1]++;
}

int				h_f_line_f(char *str, int *f_k, int *num)
{
	int z;

	z = 0;
	z = h_f_line_f1(str, f_k, z);
	if (str[f_k[1]] == '0' && str[f_k[1] + 1] == '.' && str[f_k[1] + 2] == '0')
		return (h_f_line_f3(num, 1, str, f_k));
	h_f_line_f2(f_k, str);
	if (str[f_k[1]] == 'f')
		return (h_f_line_f3(num, 1, str, f_k));
	else if (z == 1)
		return (h_f_line_f3(num, 0, str, f_k));
	else if (str[f_k[1]] == '0' && str[f_k[1] + 1] >= '0'
	&& str[f_k[1] + 1] <= '9')
	{
		f_k[0] = f_k[1];
		h_f_line_f4(str, f_k);
		if (str[f_k[1]] == 'f')
		{
			num[4] = 0;
			num[8] = 1;
			return (ft_atoi1(&str[f_k[0]]));
		}
	}
	f_k[3] = 0;
	return (0);
}

int				found_line_up_f1(char *str, int i, int *num, int *f_k)
{
	i++;
	while (h_nno(str, i) == 1)
	{
		if (str[i] == '0' && str[i + 1] == '+')
			return (h_found_line_f(num, i, str));
		if ((str[i] >= '0' && str[i] <= '9') || ((str[i] == '-' ||
		str[i] == '+') && (str[i + 1] >= '0' && str[i + 1] <= '9')))
			return (h_found_line_f1(str, num, i, f_k));
		else if (str[i] == '+')
			return (h_found_line_f2(str, num, i));
		else if (str[i] == '-')
			return (h_found_line_f3(str, i, num));
		else if (str[i] == ' ' && str[f_k[1]] == ' ')
		{
			f_k[4] = h_f_line_f(str, f_k, num);
			if (f_k[3] == 1)
				return (f_k[4]);
		}
		i++;
	}
	return (0);
}

int				found_line_up_f(char *str, int i, int *num)
{
	int f_k[5];

	f_k[1] = i + 1;
	while (str[i])
	{
		if (str[i] == '%')
			return (found_line_up_f1(str, i, num, f_k));
		i++;
	}
	return (0);
}
