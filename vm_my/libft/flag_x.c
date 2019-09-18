/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 12:18:45 by bnetschu          #+#    #+#             */
/*   Updated: 2019/05/06 16:52:25 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		h_iter(int *num, char *fr, int i, char *string)
{
	int re;

	re = 0;
	while (num[0] > 0)
	{
		if (num[4] == 0 && num[5] == -2)
		{
			fr[i] = '0';
			re = 1;
		}
		else
			fr[i] = ' ';
		i++;
		num[0]--;
	}
	return (cop_from_str_x(fr, string, num, re));
}

static int		iter(int *num, char *fr, char *string)
{
	int i;

	i = num[2];
	if (num[0] != 0)
	{
		if (num[0] > 0)
			return (h_iter(num, fr, i, string));
		else
		{
			while (num[0] < 0)
			{
				fr[i] = ' ';
				i++;
				num[0]++;
			}
			return (cop_from_str2_x(fr, string, num));
		}
	}
	return (cop_from_str_x(fr, string, num, 0));
}

static void		h_flag_x(char *fr, char *str, int *i, int *num)
{
	i[0] = 0;
	while (i[0] != i[2] && str[i[0]])
	{
		fr[i[0]] = str[i[0]];
		i[0]++;
	}
	i[1] = prom1(i[0], str, 'x', 'X');
	num[1] = nons_minus(num[0]);
	num[2] = i[0];
}

static void		hh_flag_x(char *str, char *fr, int *i)
{
	while (str[i[1]])
	{
		fr[i[0]] = str[i[1]];
		i[1]++;
		i[0]++;
	}
	fr[i[0]] = '\0';
}

char			*flag_x(char *str, va_list *argptr, int *z)
{
	int			i[3];
	char		*fr;
	int			num[8];
	char		*string;

	i[2] = *z;
	found_oktorp_x(str, *z, num);
	num[3] = 0;
	num[4] = -1;
	num[0] = found_line_up_x(str, *z, num);
	string = (ft_itoa_base((ft_cast_x(str, argptr, z)), 16, num[7]));
	num[5] = found_rigor_x(str, *z);
	i[0] = ft_strlen(str) + ft_strlen(string) + nons_minus(num[0]) + num[5];
	fr = (char*)malloc(sizeof(char) * (i[0] + 3));
	ft_bzero1(fr, i[0] + 3);
	h_flag_x(fr, str, i, num);
	i[0] = iter(num, fr, string);
	*z = i[0] - 1;
	hh_flag_x(str, fr, i);
	free(string);
	return (fr);
}
