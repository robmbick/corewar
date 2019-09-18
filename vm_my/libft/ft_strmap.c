/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 19:16:42 by bnetschu          #+#    #+#             */
/*   Updated: 2018/10/31 09:45:24 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*dest;
	unsigned int	i;

	if (s == NULL || f == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
		i++;
	dest = (char *)malloc(sizeof(*dest) * (i + 1));
	i = 0;
	if (dest != NULL)
	{
		while (*s != '\0' && s != NULL)
		{
			dest[i] = f(*s);
			s++;
			i++;
		}
		dest[i] = '\0';
	}
	return (dest);
}
