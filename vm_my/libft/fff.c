/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 14:21:46 by bnetschu          #+#    #+#             */
/*   Updated: 2019/09/13 14:29:29 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		nine_to_nul(char *str, int i)
{
	while (str[i])
	{
		str[i] = '0';
		i++;
	}
}

void		hhh_cop_p(char *string, int *i, int *n, char *fr)
{
	while (string[i[0]] && i[2] == 0)
	{
		fr[n[1] - i[1] + n[2] - n[5]] = string[i[0]];
		i[0]++;
		n[2]++;
	}
}

int			found_rigor_s(char *str, int j)
{
	int num;
	int k;

	k = 0;
	num = -2;
	while (str[j] != '%')
		j++;
	while (str[j] != 's')
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
