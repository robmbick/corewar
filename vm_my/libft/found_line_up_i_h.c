/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_line_up_i_h.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 12:27:50 by bnetschu          #+#    #+#             */
/*   Updated: 2019/09/12 18:55:51 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		h_f_up_i(char *str, int *num, int k, int i)
{
	if (str[i] == '+')
		num[7] = 1;
	if ((str[i] == '0' && str[i + 1] >= '0' && str[i + 1] <= '9') ||
	(str[i] == '+' && (str[i + 1] == '0' && str[i + 2] >= '0' &&
	str[i + 2] <= '9')))
		num[4] = 0;
	else if (str[i] >= '0' && str[i] <= '9')
	{
		k = i - 1;
		while (str[k] != 'i' && str[k] != 'd')
		{
			if (str[k] == ' ')
				num[8] = 1;
			k++;
		}
	}
	return (ft_atoi1(&str[i]));
}

int		h_f_up_i1(char *str, int *num, int i)
{
	i++;
	num[7] = 1;
	num[4] = 0;
	while (str[i] == '+')
		i++;
	return (ft_atoi1(&str[i]));
}

int		h_f_up_i2(char *str, int *num, int i)
{
	if (str[i] == '+')
		num[7] = 1;
	while (str[i] == '+')
		i++;
	if (str[i] == '0' && str[i + 1] >= '0' && str[i + 1] <= '9')
		num[4] = 0;
	return (ft_atoi1(&str[i]));
}

int		h_f_up_i_3(char *str, int *num, int i)
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

int		hh_f_i(int z, char *str, int *f_k)
{
	z = 0;
	while (str[f_k[2]] == ' ' || str[f_k[2]] == '-')
	{
		if (str[f_k[2]] == '-')
			z = 1;
		f_k[2]++;
	}
	return (z);
}
