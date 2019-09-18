/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_i.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 13:00:30 by bnetschu          #+#    #+#             */
/*   Updated: 2019/05/07 13:38:35 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	h_iter(int *num, char *fr, int i)
{
	while (num[0] > 0)
	{
		if (num[6] == 1 && num[4] == 0 && num[5] == -2)
		{
			fr[i] = (num[7] == 2) ? '+' : '-';
			num[6] = 2;
		}
		else if (num[4] == 0 && num[5] == -2)
			fr[i] = '0';
		else
			fr[i] = ' ';
		i++;
		num[0]--;
	}
}

static int	iter(int *num, char *fr, char *string)
{
	int i;

	i = num[2];
	if (num[0] != 0)
	{
		if (num[0] > 0)
			h_iter(num, fr, i);
		else
		{
			while (num[0] < 0)
			{
				fr[i] = ' ';
				i++;
				num[0]++;
			}
			return (cop_from_str2_i(fr, string, num));
		}
	}
	return (cop_from_str_i(fr, string, num));
}

static void	h_flag_i(char *fr, char *str, int *i)
{
	while (str[i[1]])
	{
		fr[i[0]] = str[i[1]];
		i[1]++;
		i[0]++;
	}
	fr[i[0]] = '\0';
}

static void	hh_flag_i(int *i, char *str, int *num, char *fr)
{
	i[0] = 0;
	while (i[0] != i[2] && str[i[0]])
	{
		fr[i[0]] = str[i[0]];
		i[0]++;
	}
	i[1] = prom1(i[0], str, 'd', 'i');
	num[1] = nons_minus(num[0]);
	num[2] = i[0];
}

char		*flag_i(char *str, va_list *argptr, int *z)
{
	int		i[3];
	char	*string;
	char	*fr;
	int		num[9];

	i[2] = *z;
	num[8] = 0;
	num[7] = 0;
	num[6] = 0;
	num[3] = 0;
	num[4] = -1;
	num[0] = found_line_up_i(str, *z, num);
	string = ft_itoa_base_stan((ft_cast_i(str, argptr, z)));
	num[5] = found_rigor_i(str, *z);
	i[0] = ft_strlen(str) + ft_strlen(string) + nons_minus(num[0]) + num[5];
	fr = (char*)malloc(sizeof(char) * (i[0] + 1));
	ft_bzero1(fr, i[0] + 1);
	string = for_minus_string(num, string);
	hh_flag_i(i, str, num, fr);
	i[0] = iter(num, fr, string);
	*z = i[0] - 1;
	h_flag_i(fr, str, i);
	free(string);
	return (fr);
}
