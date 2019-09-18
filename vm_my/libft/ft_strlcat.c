/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 17:20:42 by bnetschu          #+#    #+#             */
/*   Updated: 2018/11/08 13:22:59 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t			ret;
	unsigned int	i;
	unsigned int	j;

	j = 0;
	i = 0;
	ret = 0;
	while (src[ret])
		ret++;
	while (dest[j] != '\0' && j < n)
		j++;
	ret = ret + j;
	while (src[i] != '\0' && j < n - 1 && n != 0)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	if (j < n)
		dest[j] = '\0';
	return (ret);
}
