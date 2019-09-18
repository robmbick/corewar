/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dod_f.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 14:09:57 by bnetschu          #+#    #+#             */
/*   Updated: 2019/09/12 18:53:08 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		h_found_line_f(int *num, int i, char *str)
{
	i++;
	num[7] = 1;
	num[4] = 0;
	while (str[i] == '+')
		i++;
	return (ft_atoi1(&str[i]));
}

void	h_cop_fr_str2_f(int *n, int *i, char *fr, char *string)
{
	if (n[8] == 1 && n[6] == 0)
	{
		fr[n[2]] = ' ';
		n[2]++;
	}
	if (n[6] == 1)
	{
		fr[n[2]] = (n[7] == 2) ? '+' : '-';
		n[2]++;
	}
	if (n[5] > 0)
		while (n[5] != 0)
		{
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

void	h_flag_f(char *str, char *fr, long int *i)
{
	while (str[i[1]])
	{
		fr[i[0]] = str[i[1]];
		i[1]++;
		i[0]++;
	}
	fr[i[0]] = '\0';
}

void	hh_flag_f(int *num, char *str, int *z)
{
	num[8] = 0;
	num[7] = 0;
	num[6] = 0;
	num[3] = 0;
	num[4] = -1;
	num[0] = found_line_up_f(str, *z, num);
	num[5] = found_rigor_f(str, *z);
}
