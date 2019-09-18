/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 10:16:23 by bnetschu          #+#    #+#             */
/*   Updated: 2019/09/13 14:27:43 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		h_iter(int *num, int *i, char *fr, char *string)
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
	return (cop_from_str_p(fr, string, num, re));
}

static int		iter(int *num, char *fr, char *string, int *i)
{
	if (num[0] != 0)
	{
		if (num[0] > 0)
			return (h_iter(num, i, fr, string));
		else
		{
			while (num[0] < 0)
			{
				fr[i[0]] = ' ';
				i[0]++;
				num[0]++;
			}
			return (cop_from_str2_p(fr, string, num));
		}
	}
	return (cop_from_str_p(fr, string, num, 0));
}

static void		h_flag_p(int *i, char *str, char *fr, int *num)
{
	i[0] = 0;
	while (i[0] != i[2] && str[i[0]])
	{
		fr[i[0]] = str[i[0]];
		i[0]++;
	}
	i[1] = prom(i[0], str, 'p');
	num[1] = nons_minus(num[0]);
	num[2] = i[0];
}

static void		hh_flag_p(char *str, int *i, char *fr)
{
	while (str[i[1]])
	{
		fr[i[0]] = str[i[1]];
		i[1]++;
		i[0]++;
	}
	fr[i[0]] = '\0';
}

char			*flag_p(char *str, va_list *argptr, int *z)
{
	int		i[3];
	char	*fr;
	int		num[8];
	char	*string;

	found_oktorp_p(str, *z, num);
	num[3] = 0;
	num[4] = -1;
	i[2] = *z;
	num[0] = found_line_up_p(str, *z, num);
	string = (ft_itoa_base(((unsigned long long int)
					va_arg(*argptr, void*)), 16, num[7]));
	num[5] = found_rigor_p(str, *z);
	i[0] = ft_strlen(str) + ft_strlen(string) + nons_minus(num[0]) + num[5];
	fr = (char*)malloc(sizeof(char) * (i[0] + 3));
	ft_bzero1(fr, i[0] + 3);
	h_flag_p(i, str, fr, num);
	i[0] = iter(num, fr, string, i);
	*z = i[0] - 1;
	hh_flag_p(str, i, fr);
	free(string);
	return (fr);
}
