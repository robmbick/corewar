/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 18:10:42 by bnetschu          #+#    #+#             */
/*   Updated: 2018/11/07 13:10:17 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int ch)
{
	int		i;
	char	*str;

	str = (char*)s;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ch)
			return (&str[i]);
		i++;
	}
	if ((char)ch == '\0')
		return (&str[i]);
	return (NULL);
}
