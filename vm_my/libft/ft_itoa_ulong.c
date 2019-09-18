/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ulong.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 11:11:40 by bnetschu          #+#    #+#             */
/*   Updated: 2019/05/07 13:47:58 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			h_found_line_up_i11(char *str, int *f_k)
{
	while (str[f_k[2]] >= '0' && str[f_k[2]] <= '9')
		f_k[2]++;
}

static void		ft_itoa2(unsigned long long int nb, char *str, int i, int k)
{
	while (i >= k)
	{
		str[i] = nb % 10 + '0';
		nb = nb / 10;
		i--;
	}
}

static int		int_len(unsigned long long int nb)
{
	unsigned int i;

	i = 0;
	while (1)
	{
		i++;
		if (nb < 10)
			break ;
		nb = nb / 10;
	}
	return (i);
}

static char		*ft_point(int i)
{
	char *str;

	str = (char*)malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	str[i] = '\0';
	return (str);
}

char			*ft_itoa_ulong(unsigned long long int nb)
{
	char			*str;
	unsigned int	i;
	unsigned int	k;
	int				check;

	check = 0;
	k = 0;
	i = int_len(nb);
	str = ft_point(i);
	if (str == NULL)
		return (NULL);
	ft_itoa2(nb, str, i - 1, k);
	(check == 1 ? str[1] = '2' : -check);
	return (str);
}
