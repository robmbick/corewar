/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strword.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 15:29:50 by bnetschu          #+#    #+#             */
/*   Updated: 2018/10/31 15:32:03 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lentab1(char *s, char *k, char c, int i)
{
	while (1)
	{
		if (*s == c)
		{
			i++;
			while (*s == c)
				s++;
		}
		if (*s == '\0')
		{
			if (*k == c && *--s == c)
				i--;
			if (*k != c && *--s != c)
				i++;
			break ;
		}
		s++;
	}
	return (i);
}

int			ft_strword(char *s, char c)
{
	int		i;
	char	*k;

	k = s;
	i = 0;
	if (*s == c)
	{
		i++;
		while (*s == c)
			s++;
	}
	i = ft_lentab1(s, k, c, i);
	return (i + 1);
}
