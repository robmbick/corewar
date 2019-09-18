/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 14:42:55 by bnetschu          #+#    #+#             */
/*   Updated: 2019/09/13 14:29:22 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*h_nul_rigor(char *str)
{
	char	*s;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(str);
	while (len - 1 - i > 0 && str[len - 1 - i] == '9')
		i++;
	if (str[len - 1 - i] >= '0' && str[len - 1 - i] < '9')
	{
		str[len - 1 - i]++;
		nine_to_nul(str, len - i);
	}
	else
	{
		s = str;
		str = (char*)malloc(sizeof(char) * (len + 2));
		ft_bzero1(str, len + 2);
		str[0] = '1';
		nine_to_nul(str, len);
		free(s);
	}
	return (str);
}

static char	*h_rig(char *str)
{
	if (str[ft_strlen(str) - 1] == '9')
		str = h_nul_rigor(str);
	else
		str[ft_strlen(str) - 1]++;
	return (str);
}

static char	*nul_rigor(char *str, char *str_else)
{
	int i;
	int ch;

	i = 0;
	while (str_else[i])
	{
		ch = 0;
		while (str_else[i + ch] == '9')
			ch++;
		if (ch > 6 || (ch >= 6 && i != 0))
		{
			if (i == 0)
				str = h_rig(str);
			else
				str_else[i - 1]++;
			nine_to_nul(str_else, i);
			break ;
		}
		i++;
	}
	str_else[6] = '\0';
	return (str);
}

static int	h_f_r(char *str_else)
{
	unsigned int i;

	i = 0;
	while (str_else[i] && i <= 27)
	{
		if (str_else[i] != '0')
			return (1);
		i++;
	}
	return (0);
}

char		*ft_round_f(char *str, char *str_else, int n)
{
	if (n == -2)
		str = nul_rigor(str, str_else);
	else if (n == -1 || n == 0)
	{
		if (str_else[0] <= '9' && str_else[0] >= '6')
			str = h_nul_rigor(str);
		else if (str_else[0] == '5' && (str[ft_strlen(str) - 1] % 2 != 0
		|| str[ft_strlen(str) - 1] == '0' || h_f_r(&str_else[1])))
			str = h_nul_rigor(str);
		str_else[0] = '\0';
	}
	else
	{
		if (str_else[n] <= '9' && str_else[n] >= '6')
			str = ft_round_hf(str, str_else, n);
		else if (str_else[n] == '5' && (((str_else[n - 1] % 2 != 0 ||
		h_f_r(&str_else[n + 1]) == 1)) || str_else[n - 1] == '0'))
			str = ft_round_hf(str, str_else, n);
		str_else[n] = '\0';
	}
	return (str);
}
