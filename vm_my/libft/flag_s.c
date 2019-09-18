/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 11:56:59 by bnetschu          #+#    #+#             */
/*   Updated: 2019/05/07 13:22:14 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		found_rigor(char *str, int j)
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

static int		iter(int *num, char *fr, char *string, char *str)
{
	int i;

	i = num[2];
	if (num[0] != 0)
	{
		if (num[0] > 0)
			while (num[0] > 0)
			{
				fr[i] = (num[4] == 0) ? '0' : ' ';
				i++;
				num[0]--;
			}
		else
		{
			while (num[0] < 0)
			{
				fr[i] = ' ';
				i++;
				num[0]++;
			}
			return (cop_from_str2_s(fr, string, num, str));
		}
	}
	return (cop_from_str_s(fr, string, num, str));
}

static char		*h_flag_s(int *num, int *z, char *str, va_list *argptr)
{
	char	*string;

	num[3] = 0;
	num[4] = -1;
	num[0] = found_line_up_s(str, *z, num);
	num[5] = found_rigor(str, *z);
	if (num[5] == 0)
		string = ft_strjoin("\0", "\0");
	else
	{
		string = (char*)va_arg(*argptr, int*);
		if (string == NULL)
		{
			string = ft_strjoin("(null)", "\0");
			num[3] = 1;
		}
	}
	return (string);
}

static void		hh_flag_s(char *str, char *fr, unsigned int *i)
{
	while (str[i[1]])
	{
		fr[i[0]] = str[i[1]];
		i[1]++;
		i[0]++;
	}
	fr[i[0]] = '\0';
}

char			*flag_s(char *str, va_list *argptr, int *z)
{
	unsigned int				i[2];
	char						*string;
	char						*fr;
	int							num[6];

	string = h_flag_s(num, z, str, argptr);
	i[0] = ft_strlen(str) + ft_strlen(string) + nons_minus(num[0]);
	fr = (char*)malloc(sizeof(char) * (i[0] + 1));
	ft_bzero1(fr, i[0] + 1);
	i[0] = 0;
	while (i[0] != (unsigned int)*z && str[i[0]])
	{
		fr[i[0]] = str[i[0]];
		i[0]++;
	}
	i[1] = prom(i[0], str, 's');
	num[1] = nons_minus(num[0]);
	num[2] = i[0];
	i[0] = iter(num, fr, string, str);
	*z = i[0] - 1;
	hh_flag_s(str, fr, i);
	(num[3] == 1) ? free(string) : 0;
	(num[5] == 0) ? free(string) : 0;
	return (fr);
}
