/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 19:24:55 by bnetschu          #+#    #+#             */
/*   Updated: 2018/10/30 13:48:26 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	unsigned int i;
	unsigned int j;

	if (to_find[0] == '\0')
		return ((char*)str);
	j = 0;
	while (str[j] != '\0' && j < len)
	{
		i = 0;
		while (to_find[i] == str[j + i] && (j + i) < len)
		{
			if (to_find[i + 1] == '\0')
			{
				return ((char *)&str[j]);
			}
			i++;
		}
		j++;
	}
	return (0);
}
