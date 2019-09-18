/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 14:48:46 by bnetschu          #+#    #+#             */
/*   Updated: 2019/05/07 13:32:47 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			h_ft_cast_u(char *str, int i, int *hl)
{
	while (str[i] != 'u' && str[i] != 'U')
	{
		if (str[i] == 'h')
			hl[0]++;
		if (str[i] == 'l')
			hl[1]++;
		i++;
	}
	return (i);
}

static uintmax_t	ft_cast_u(char *str, va_list *argptr, int *z)
{
	int		i;
	int		hl[2];

	hl[0] = 0;
	hl[1] = 0;
	i = *z;
	i = h_ft_cast_u(str, i, hl);
	if (hl[0] == 0 && hl[1] != 0)
	{
		if (hl[1] == 1)
			return ((unsigned long int)va_arg(*argptr, void*));
		else if (hl[1] >= 2)
			return ((unsigned long long int)va_arg(*argptr, void*));
	}
	else if (hl[1] == 0 && hl[0] != 0 && str[i] != 'U')
	{
		if (hl[0] == 2)
			return ((unsigned char)va_arg(*argptr, void*));
		else if (hl[0] == 1 || hl[0] > 2)
			return ((unsigned short int)va_arg(*argptr, void*));
	}
	if (str[i] == 'U')
		return ((unsigned long int)va_arg(*argptr, void*));
	return ((unsigned int)va_arg(*argptr, void*));
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
				fr[i] = (num[4] == 0 && num[5] == -2) ? '0' : ' ';
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
			return (cop_from_str2_u(fr, string, num));
		}
	}
	return (cop_from_str_u(fr, string, num));
}

static void			h_flag_u(int *i, char *str, char *fr, int *num)
{
	ft_bzero1(fr, i[0] + 1);
	i[0] = 0;
	while (i[0] != i[2] && str[i[0]])
	{
		fr[i[0]] = str[i[0]];
		i[0]++;
	}
	i[1] = prom1(i[0], str, 'u', 'U');
	num[1] = nons_minus(num[0]);
	num[2] = i[0];
}

char				*flag_u(char *str, va_list *argptr, int *z)
{
	int				i[3];
	char			*string;
	char			*fr;
	int				num[6];

	i[2] = *z;
	num[3] = 0;
	num[4] = -1;
	num[0] = found_line_up_u(str, *z, num);
	string = ft_itoa_ulong((ft_cast_u(str, argptr, z)));
	num[5] = found_rigor_u(str, *z);
	i[0] = ft_strlen(str) + ft_strlen(string) + nons_minus(num[0]) + num[5];
	fr = (char*)malloc(sizeof(char) * (i[0] + 1));
	h_flag_u(i, str, fr, num);
	i[0] = iter(num, fr, string);
	*z = i[0] - 1;
	while (str[i[1]])
	{
		fr[i[0]] = str[i[1]];
		i[1]++;
		i[0]++;
	}
	fr[i[0]] = '\0';
	free(string);
	return (fr);
}
