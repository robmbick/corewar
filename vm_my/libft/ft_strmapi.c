/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 19:29:17 by bnetschu          #+#    #+#             */
/*   Updated: 2018/10/31 09:46:44 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
			dest[i] = f(i, *s);
			s++;
			i++;
		}
		dest[i] = '\0';
	}
	return (dest);
}
