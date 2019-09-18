/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_line_up_s.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 14:26:33 by bnetschu          #+#    #+#             */
/*   Updated: 2019/05/06 12:55:07 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	h(char *str, int *num, int i, int k)
{
	if (k == 1)
	{
		if ((str[i] == '0' && str[i + 1] >= '0' && str[i + 1] <= '9')
		|| (str[i] == '+' && (str[i + 1] >= '0' && str[i + 1] <= '9')))
			num[4] = 0;
		return (ft_atoi1(&str[i]));
	}
	if ((str[i] == '0' && str[i + 1] >= '0' && str[i + 1] <= '9') ||
	(str[i] == '+' && (str[i + 1] >= '0' && str[i + 1] <= '9')))
		num[4] = 0;
	return ((-1) * ft_atoi1(&str[i + 1]));
}

int			found_line_up_s(char *str, int i, int *num)
{
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			while ((str[i] == ' ' && str[i]) || (str[i] >= '0' && str[i] <= '9')
			|| ((str[i] == '-' || str[i] == '+') && (str[i + 1] >= '0'
			&& str[i + 1] <= '9')) || str[i] == 'h' || str[i] == 'l' ||
			str[i] == 'L' || str[i] == '#' || str[i] == '-' || str[i] == '+')
			{
				if ((str[i] >= '0' && str[i] <= '9') || ((str[i] == '-' ||
				str[i] == '+') && (str[i + 1] >= '0' && str[i + 1] <= '9')))
					return (h(str, num, i, 1));
				i++;
			}
			if (str[i] == 's')
				return (0);
		}
		i++;
	}
	return (0);
}

int			found_rigor_o(char *str, int j)
{
	int num;
	int k;

	k = 0;
	num = -2;
	while (str[j] != '%')
		j++;
	while (str[j] != 'o')
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

void		h_cop2_o(int *n, char *fr, char *string, int *i)
{
	if (n[5] > 0)
		while (n[5] != 0)
		{
			if (n[6] == 1 && string[0] != '0')
			{
				fr[n[2]] = '0';
				n[2] += 1;
				n[6] = 0;
				n[5] -= 2;
				if (n[5] == 0)
					break ;
			}
			fr[n[2]] = '0';
			n[2]++;
			n[5]--;
		}
	while (string[i[0]] && i[2] == 0)
	{
		fr[n[2]] = string[i[0]];
		i[0]++;
		n[2]++;
	}
}
