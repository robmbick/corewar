/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 17:01:50 by bnetschu          #+#    #+#             */
/*   Updated: 2019/05/07 13:28:12 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		h_write_s(int k)
{
	ft_putchar('\0');
	k++;
	return (k);
}

int				write_s(char *s, int *nul)
{
	long long int	i;
	int				k;

	k = 0;
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
		if (*nul == i)
		{
			ft_putchar('\0');
			if (nul[1] == 1)
			{
				k--;
				i++;
			}
			k++;
		}
	}
	if (i == 0)
		if (*nul == i)
			k = h_write_s(k);
	k += i;
	return (k);
}

static int		h_ft_cast(char *str, int i, int *hl)
{
	while (str[i] != 'o')
	{
		if (str[i] == 'h')
			hl[0]++;
		if (str[i] == 'l')
			hl[1]++;
		i++;
	}
	return (i);
}

uintmax_t		ft_cast_o(char *str, va_list *argptr, int *z)
{
	int		i;
	int		hl[2];

	hl[0] = 0;
	hl[1] = 0;
	i = *z;
	i = h_ft_cast(str, i, hl);
	if (hl[0] == 0 && hl[1] != 0)
	{
		if (hl[1] == 1)
			return ((unsigned long int)va_arg(*argptr, void*));
		else if (hl[1] >= 2)
			return ((unsigned long long int)va_arg(*argptr, void*));
	}
	else if (hl[1] == 0 && hl[0] != 0)
	{
		if (hl[0] == 2)
			return ((unsigned char)va_arg(*argptr, void*));
		else if (hl[0] == 1 || hl[0] > 2)
			return ((unsigned short int)va_arg(*argptr, void*));
	}
	return ((unsigned int)va_arg(*argptr, void*));
}

void			found_oktorp(char *str, int i, int *num)
{
	num[6] = 0;
	while (str[i] != 'o')
	{
		if (str[i] == '#')
			num[6] = 1;
		i++;
	}
	num[7] = 97;
}
