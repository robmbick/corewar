/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   non_flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 12:23:58 by bnetschu          #+#    #+#             */
/*   Updated: 2019/05/06 15:30:29 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		prom2(int i, char *str)
{
	int e;

	e = 0;
	while (str[i])
	{
		if (str[i] == '%')
			e++;
		if (e == 2)
			break ;
		i++;
	}
	i++;
	return (i);
}

static int		h_iter(int *num, char *fr, int i)
{
	while (num[0] > 0)
	{
		fr[i] = (num[3] == 0) ? '0' : ' ';
		i++;
		num[0]--;
	}
	num[2] = i;
	return (cop_from_str_non(fr, num, 0));
}

static int		iter(int *num, char *fr)
{
	int i;

	i = num[2];
	if (num[0] != 0)
	{
		if (num[0] > 0)
			return (h_iter(num, fr, i));
		else
		{
			while (num[0] < 0)
			{
				fr[i] = ' ';
				i++;
				num[0]++;
			}
			cop_from_str_non(fr, num, 2);
			return (i);
		}
	}
	return (cop_from_str_non(fr, num, 1));
}

static void		h_non_flag(char *str, char *fr, int k, int i)
{
	while (str[k])
	{
		fr[i] = str[k];
		k++;
		i++;
	}
	fr[i] = '\0';
}

char			*non_flag(char *str, int *z)
{
	int		i;
	int		num[4];
	char	*fr;
	int		k;

	num[3] = -1;
	num[0] = found_line_up_non(str, *z, num, 1);
	i = ft_strlen(str) + nons_minus(num[0]);
	fr = (char*)malloc(sizeof(char) * (i + 1));
	ft_bzero1(fr, i + 1);
	i = 0;
	while (i != *z && str[i])
	{
		fr[i] = str[i];
		i++;
	}
	k = prom2(i, str);
	num[1] = nons_minus(num[0]);
	num[2] = i;
	i = iter(num, fr);
	*z = i - 1;
	h_non_flag(str, fr, k, i);
	return (fr);
}
