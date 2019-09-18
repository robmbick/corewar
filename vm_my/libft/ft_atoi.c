/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 19:47:07 by bnetschu          #+#    #+#             */
/*   Updated: 2018/11/07 12:42:45 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long long int i;
	long long int nb;
	long long int j;

	i = 0;
	nb = 0;
	j = 0;
	while (str[i] == 32 || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\r' || str[i] == '\t' || str[i] == '\f')
		i++;
	if (str[i] == 45 || str[i] == 43)
	{
		j = 1;
		if (str[i] == 43)
			j = 0;
		i++;
	}
	while (str[i] <= 57 && str[i] >= 48)
	{
		nb = nb * 10 + (long long int)str[i] - '0';
		i++;
	}
	if (j == 1)
		nb *= (-1);
	return (nb);
}
