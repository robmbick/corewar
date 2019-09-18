/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 18:39:38 by bnetschu          #+#    #+#             */
/*   Updated: 2018/11/02 18:32:24 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_itoa2(int nb, char *str, int i, int k)
{
	while (i >= k)
	{
		str[i] = nb % 10 + '0';
		nb = nb / 10;
		i--;
	}
}

static int		int_len(int nb)
{
	int i;

	i = 0;
	if (nb == -2147483648)
	{
		nb = -147483648;
		i++;
	}
	if (nb < 0)
	{
		nb *= (-1);
		i++;
	}
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

char			*ft_itoa(int nb)
{
	char	*str;
	int		i;
	int		k;
	int		check;

	check = 0;
	k = 0;
	i = int_len(nb);
	str = ft_point(i);
	if (str == NULL)
		return (NULL);
	if (nb == -2147483648)
	{
		check = 1;
		nb = -147483648;
	}
	if (nb < 0)
	{
		k = 1;
		nb *= (-1);
		str[0] = '-';
	}
	ft_itoa2(nb, str, i - 1, k);
	(check == 1 ? str[1] = '2' : -check);
	return (str);
}
