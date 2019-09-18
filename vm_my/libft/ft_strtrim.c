/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 14:13:48 by bnetschu          #+#    #+#             */
/*   Updated: 2018/10/31 11:00:32 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*dot1(char *str, int i, char const *s)
{
	int j;

	if (str == NULL)
		return (NULL);
	str[i] = '\0';
	j = i;
	i = 0;
	while (i < j)
	{
		str[i] = *s;
		i++;
		s++;
	}
	return (str);
}

char			*ft_strtrim(char const *s)
{
	int		i;
	char	*str;

	if (s == NULL)
		return (NULL);
	i = ft_strlen((char *)s);
	while (s[i - 1] == ' ' || s[i - 1] == '\n' || s[i - 1] == '\t')
		i--;
	while (*s == ' ' || *s == '\n' || *s == '\t')
	{
		i--;
		s++;
	}
	if (i <= 0)
		i = 0;
	str = (char *)malloc(sizeof(*str) * (i + 1));
	return (dot1(str, i, s));
}
