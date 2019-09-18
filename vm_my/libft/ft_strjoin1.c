/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 11:53:31 by bnetschu          #+#    #+#             */
/*   Updated: 2019/05/06 17:53:37 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_strjoin1(char const *s1, char const *s2)
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

static void		h_cop_str2_x(int *n, char *string, char *fr, int *i)
{
	if (n[5] > 0)
		while (n[5] != 0)
		{
			if (n[6] == 1 && string[0] != '0')
			{
				fr[n[2]] = '0';
				(n[7] == 65) ? fr[n[2] + 1] = 'X' : 0;
				(n[7] == 97) ? fr[n[2] + 1] = 'x' : 0;
				n[2] += 2;
				n[6] = 0;
				n[5] -= 2;
				if (n[5] == 0)
					break ;
			}
			fr[n[2]] = '0';
			n[2]++;
			n[5]--;
		}
	while (string[i[0]])
	{
		fr[n[2]] = string[i[0]];
		i[0]++;
		n[2]++;
	}
}

int				cop_from_str2_x(char *fr, char *string, int *n)
{
	int i[3];

	i[0] = 0;
	i[1] = 0;
	while (string[i[1]])
	{
		i[1]++;
		if (n[5] > 0)
			n[5]--;
	}
	if (n[6] == 1 && string[0] != '0')
	{
		if (n[5] <= -1)
			n[5] = 0;
		n[5] += 2;
	}
	if (n[5] == -1 && string[0] == '0')
		string[0] = ' ';
	h_cop_str2_x(n, string, fr, i);
	while (fr[n[2]] == ' ' && fr[n[2]])
		n[2]++;
	return (n[2]);
}

int				h_cop_x(int *n, char *fr, char *string, int w)
{
	int sav;

	sav = 0;
	if (n[4] == 0 && n[5] == -2 && w == 1 && n[6] == 1)
	{
		(n[7] == 65) ? fr[n[2] + 1] = 'X' : 0;
		(n[7] == 97) ? fr[n[2] + 1] = 'x' : 0;
	}
	if (n[6] == 1 && string[0] != '0' && w != 1)
	{
		if (n[5] <= -1)
			n[5] = 0;
		n[5] += 2;
		sav = 2;
	}
	return (sav);
}
