/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 16:06:39 by bnetschu          #+#    #+#             */
/*   Updated: 2019/05/10 14:54:00 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long double	ft_cast_f(char *str, va_list *argptr, int *z)
{
	int		i;
	int		h;
	int		l;

	h = 0;
	l = 0;
	i = *z;
	while (str[i] != 'f')
	{
		if (str[i] == 'L')
			l++;
		i++;
	}
	if (l > 0)
		return (va_arg(*argptr, long double));
	return ((double)va_arg(*argptr, double));
}

int					found_rigor_f(char *str, int j)
{
	int num;
	int k;

	k = 0;
	num = -2;
	while (str[j] != '%')
		j++;
	while (str[j] != 'f')
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

static int			h_iter(int *num, char *fr, char *string, int i)
{
	while (num[0] > 0)
	{
		if (num[6] == 1 && num[4] == 0 && num[5] == -2)
		{
			fr[i] = (num[7] == 2) ? '+' : '-';
			num[6] = 2;
		}
		fr[i] = (num[4] == 0 && num[5] == -2) ? '0' : ' ';
		i++;
		num[0]--;
	}
	return (cop_from_str_f(fr, string, num));
}

static int			iter(int *num, char *fr, char *string)
{
	int i;

	i = num[2];
	if (num[0] != 0)
	{
		if (num[0] > 0)
			return (h_iter(num, fr, string, i));
		else
		{
			while (num[0] < 0)
			{
				fr[i] = ' ';
				i++;
				num[0]++;
			}
			return (cop_from_str2_f(fr, string, num));
		}
	}
	return (cop_from_str_f(fr, string, num));
}

char				*flag_f(char *str, va_list *argptr, int *z)
{
	long int		i[2];
	char			*string;
	char			*fr;
	int				num[9];

	hh_flag_f(num, str, z);
	string = ft_itoa_base_double((ft_cast_f(str, argptr, z)), &num[5]);
	i[0] = ft_strlen(str) + ft_strlen(string) + nons_minus(num[0]);
	fr = (char*)malloc(sizeof(char) * (i[0] + 1));
	ft_bzero1(fr, i[0] + 1);
	string = for_minus_string(num, string);
	i[0] = 0;
	while (i[0] != *z && str[i[0]])
	{
		fr[i[0]] = str[i[0]];
		i[0]++;
	}
	i[1] = prom(i[0], str, 'f');
	num[1] = nons_minus(num[0]);
	num[2] = i[0];
	i[0] = iter(num, fr, string);
	*z = i[0] - 1;
	h_flag_f(str, fr, i);
	free(string);
	return (fr);
}
