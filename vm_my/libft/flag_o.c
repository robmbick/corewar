/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:27:22 by bnetschu          #+#    #+#             */
/*   Updated: 2019/05/07 13:25:15 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		h_iter(int *num, char *fr, char *string, unsigned int *i)
{
	int re;

	re = 0;
	while (num[0] > 0)
	{
		if (num[4] == 0 && num[5] == -2)
		{
			fr[i[0]] = '0';
			re = 1;
		}
		else
			fr[i[0]] = ' ';
		i[0]++;
		num[0]--;
	}
	return (cop_from_str_o(fr, string, num, re));
}

static int		iter(unsigned int *i, char *fr, char *string, int *num)
{
	if (num[0] != 0)
	{
		if (num[0] > 0)
			return (h_iter(num, fr, string, i));
		else
		{
			while (num[0] < 0)
			{
				fr[i[0]] = ' ';
				i[0]++;
				num[0]++;
			}
			return (cop_from_str2_o(fr, string, num));
		}
	}
	return (cop_from_str_o(fr, string, num, 0));
}

static void		h_flag_o(unsigned int *i, int *num, char *str, char *fr)
{
	i[0] = 0;
	while (i[0] != (unsigned int)num[8] && str[i[0]])
	{
		fr[i[0]] = str[i[0]];
		i[0]++;
	}
	i[1] = prom(i[0], str, 'o');
	num[1] = nons_minus(num[0]);
	num[2] = i[0];
}

static void		hh_flag_o(char *str, char *fr, unsigned int *i)
{
	while (str[i[1]])
	{
		fr[i[0]] = str[i[1]];
		i[1]++;
		i[0]++;
	}
	fr[i[0]] = '\0';
}

char			*flag_o(char *str, va_list *argptr, int *z)
{
	unsigned int				i[2];
	char						*fr;
	int							num[9];
	char						*string;

	found_oktorp(str, *z, num);
	num[3] = 0;
	num[4] = -1;
	num[8] = *z;
	num[0] = found_line_up_o(str, *z, num);
	string = (ft_itoa_base((ft_cast_o(str, argptr, z)), 8, num[7]));
	num[5] = found_rigor_o(str, *z);
	i[0] = ft_strlen(str) + ft_strlen(string) + nons_minus(num[0]) + num[5];
	fr = (char*)malloc(sizeof(char) * (i[0] + 3));
	ft_bzero1(fr, i[0] + 3);
	h_flag_o(i, num, str, fr);
	i[0] = iter(i, fr, string, num);
	*z = i[0] - 1;
	hh_flag_o(str, fr, i);
	free(string);
	return (fr);
}
