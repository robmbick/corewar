/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 11:53:31 by bnetschu          #+#    #+#             */
/*   Updated: 2018/10/31 10:05:42 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	unsigned int	i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	str = (char *)malloc(sizeof(*str) * (i + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (*s1)
	{
		str[i] = (char)*s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		str[i] = (char)*s2;
		s2++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
