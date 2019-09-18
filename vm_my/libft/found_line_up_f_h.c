/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_line_up_f_h.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 15:14:14 by bnetschu          #+#    #+#             */
/*   Updated: 2019/09/12 18:54:21 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				h_found_line_f1(char *str, int *num, int i, int *f_k)
{
	if (str[i] == '+')
		num[7] = 1;
	if ((str[i] == '0' && str[i + 1] >= '0' && str[i + 1] <= '9') ||
	(str[i] == '+' && (str[i + 1] == '0' && str[i + 2] >= '0' &&
	str[i + 2] <= '9')))
		num[4] = 0;
	else if (str[i] >= '0' && str[i] <= '9')
	{
		f_k[1] = i - 1;
		while (str[f_k[1]] != 'f')
		{
			if (str[f_k[1]] == ' ')
				num[8] = 1;
			f_k[1]++;
		}
	}
	return (ft_atoi1(&str[i]));
}

int				h_found_line_f2(char *str, int *num, int i)
{
	if (str[i] == '+')
		num[7] = 1;
	while (str[i] == '+')
		i++;
	if (str[i] == '0' && str[i + 1] >= '0' && str[i + 1] <= '9')
		num[4] = 0;
	return (ft_atoi1(&str[i]));
}

int				h_found_line_f3(char *str, int i, int *num)
{
	while (str[i] == '+' || str[i] == '-' || str[i] == ' ')
	{
		if (str[i] == ' ')
			num[8] = 1;
		if (str[i] == '+')
			num[7] = 1;
		i++;
	}
	return ((ft_atoi1(&str[i]) > 0) ? ((-1) *
	ft_atoi1(&str[i])) : (ft_atoi1(&str[i])));
}

int				h_f_line_f1(char *str, int *f_k, int z)
{
	f_k[3] = 1;
	while (str[f_k[1]] == ' ' || str[f_k[1]] == '-')
	{
		if (str[f_k[1]] == '-')
			z = 1;
		f_k[1]++;
	}
	return (z);
}

void			h_f_line_f2(int *f_k, char *str)
{
	if (str[f_k[1]] == '.')
	{
		f_k[1]++;
		while (str[f_k[1]] >= '0' && str[f_k[1]] <= '9')
			f_k[1]++;
	}
	while (str[f_k[1]] == 'h' || str[f_k[1]] == 'l' || str[f_k[1]] == 'L')
		f_k[1]++;
	if (str[f_k[1]] == '0' && (str[f_k[1] + 1] == 'f'))
		f_k[1]++;
}
