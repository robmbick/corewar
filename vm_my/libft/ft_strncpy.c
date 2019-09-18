/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 13:59:54 by bnetschu          #+#    #+#             */
/*   Updated: 2018/11/07 13:03:28 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	unsigned int i;

	i = 0;
	while (src[i] != '\0' && n != 0)
	{
		dest[i] = src[i];
		i++;
		n--;
	}
	if (dest[i] != '\0')
	{
		while (n != 0)
		{
			dest[i] = '\0';
			i++;
			n--;
		}
	}
	return (dest);
}
