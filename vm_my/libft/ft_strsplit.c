/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 17:57:02 by bnetschu          #+#    #+#             */
/*   Updated: 2019/02/21 11:29:08 by bnetschu         ###   ########.fr       */
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

static int	ft_lentab(char *s, char c)
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

static int	ft_lenstr(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static char	**ft_split(char const *s, char c, char **tab, int k)
{
	char	*str;
	int		i;
	int		j;

	j = 0;
	while (j < k - 1)
	{
		i = 0;
		while (*s == c)
			s++;
		str = (char*)malloc(sizeof(char) * (ft_lenstr((char *)s, c) + 1));
		while (*s != c && *s != '\0')
		{
			str[i] = *s;
			i++;
			s++;
		}
		s++;
		str[i] = '\0';
		tab[j] = str;
		j++;
	}
	tab[j] = NULL;
	return (tab);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		k;

	if (s == NULL)
		return (NULL);
	if (*s == '\0')
	{
		tab = (char**)malloc(sizeof(char*) * 1);
		tab[0] = NULL;
		return (tab);
	}
	k = ft_lentab((char *)s, c);
	tab = (char**)malloc(sizeof(char*) * k);
	if (tab == NULL)
		return (NULL);
	return (ft_split(s, c, tab, k));
}
