/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 18:26:10 by bnetschu          #+#    #+#             */
/*   Updated: 2019/09/12 18:56:31 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			h_cast_i(char *str, int *h, int i)
{
	while (str[i] != 'i' && str[i] != 'd')
	{
		if (str[i] == 'h')
			h[0]++;
		if (str[i] == 'l')
			h[1]++;
		i++;
	}
	return (i);
}

__int128_t			ft_cast_i(char *str, va_list *argptr, int *z)
{
	int		i;
	int		h[2];

	h[0] = 0;
	h[1] = 0;
	i = *z;
	i = h_cast_i(str, h, i);
	if (h[0] == 0 && h[1] != 0)
	{
		if (h[1] == 1)
			return ((long int)va_arg(*argptr, void*));
		else if (h[1] >= 2)
			return ((long long int)va_arg(*argptr, void*));
	}
	else if (h[1] == 0 && h[0] != 0 && str[i] != 'U')
	{
		if (h[0] == 2)
			return ((signed char)va_arg(*argptr, void*));
		else if (h[0] == 1 || h[0] > 2)
			return ((short int)va_arg(*argptr, void*));
	}
	if (str[i] == 'U')
		return ((long int)va_arg(*argptr, void*));
	return ((int)va_arg(*argptr, void*));
}

char				*for_minus_string(int *n, char *str)
{
	int i;

	i = 0;
	if (n[7] == 1 && str[0] != '-')
	{
		n[6] = 1;
		n[7] = 2;
		return (str);
	}
	else if (str[0] != '-')
		return (str);
	while (str[i + 1])
	{
		str[i] = str[i + 1];
		i++;
	}
	str[i] = '\0';
	n[6] = 1;
	return (str);
}

int					found_rigor_i(char *str, int j)
{
	int num;
	int k;

	k = 0;
	num = -2;
	while (str[j] != '%')
		j++;
	while (str[j] != 'i' && str[j] != 'd')
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

void				h_cop_fr_str_i(char *fr, int *n, int *i, char *string)
{
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
	while (fr[n[2]] == ' ' && fr[n[2]])
		n[2]++;
}
