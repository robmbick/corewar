/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 17:03:41 by bnetschu          #+#    #+#             */
/*   Updated: 2019/05/07 13:27:51 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			found_line_up(char *str, int i, int *num)
{
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			while ((str[i] == ' ' && str[i]) || (str[i] >= '0' && str[i] <= '9')
			|| (str[i] == '-' && (str[i + 1] >= '0' && str[i + 1] <= '9')) ||
			str[i] == 'h' || str[i] == 'l' || str[i] == 'L' || str[i] == '#'
			|| str[i] == '-')
			{
				if ((str[i] >= '0' && str[i] <= '9') || (str[i] == '-'
				&& (str[i + 1] >= '0' && str[i + 1] <= '9')))
				{
					num[4] = (str[i] == '0' && (str[i + 1] >= '0'
					&& str[i + 1] <= '9')) ? 0 : -1;
					return (ft_atoi1(&str[i]));
				}
				i++;
			}
			if (str[i] == 'c')
				return (0);
		}
		i++;
	}
	return (0);
}

static int			iter(int *num, char *fr, char *string)
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
			return (cop_from_str2_c(fr, string, num));
		}
	}
	return (cop_from_str_c(fr, string, num));
}

static void			h_flag_c(unsigned int *i, char *str, char *fr)
{
	while (str[i[1]])
	{
		fr[i[0]] = str[i[1]];
		i[1]++;
		i[0]++;
	}
	fr[i[0]] = '\0';
}

static char			*hh_flag_c(va_list *argptr, int *num,
									char *string, unsigned int *i)
{
	char *fr;

	fr = NULL;
	string[0] = (char)va_arg(*argptr, void*);
	num[3] = (string[0] == '\0') ? 1 : 0;
	string[1] = '\0';
	fr = (char*)malloc(sizeof(char) * (i[0] + 1));
	ft_bzero1(fr, i[0] + 1);
	i[0] = 0;
	return (fr);
}

char				*flag_c(char *str, va_list *argptr, int *z, int *nul)
{
	char						string[2];
	int							num[5];
	unsigned int				i[2];
	char						*fr;

	num[4] = -1;
	num[0] = found_line_up(str, *z, num);
	i[0] = ft_strlen(str) + 1 + nons_minus(num[0]);
	fr = hh_flag_c(argptr, num, string, i);
	while (i[0] != (unsigned int)*z && str[i[0]])
	{
		fr[i[0]] = str[i[0]];
		i[0]++;
	}
	i[1] = prom(i[0], str, 'c');
	num[1] = nons_minus(num[0]);
	num[2] = i[0];
	i[0] = iter(num, fr, string);
	*z = i[0] - 1;
	nul_c(num, nul, i);
	h_flag_c(i, str, fr);
	return (fr);
}
