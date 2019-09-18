/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 18:52:41 by bnetschu          #+#    #+#             */
/*   Updated: 2018/10/30 13:45:56 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (to_find[0] == '\0')
		return ((char*)str);
	while (str[j])
	{
		while (to_find[i] == str[j + i])
		{
			if (to_find[i + 1] == '\0')
			{
				return ((char *)&str[j]);
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (0);
}
