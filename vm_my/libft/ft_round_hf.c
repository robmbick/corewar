/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round_hf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 13:51:15 by bnetschu          #+#    #+#             */
/*   Updated: 2019/05/06 15:53:12 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char					*ft_strjoin_f(char const *s1, char const *s2)
{
	char			*str;
	unsigned int	i;

	i = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	str = (char *)malloc(sizeof(*str) * (i + 2));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (*s1)
	{
		str[i] = (char)*s1;
		s1++;
		i++;
	}
	str[i] = '.';
	i++;
	while (*s2)
	{
		str[i] = (char)*s2;
		s2++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char					*ft_round_hf(char *str, char *str_else, int n)
{
	int i;

	i = n - 1;
	while (str_else[i] == '9' && i > 0)
		i--;
	if (str_else[i] >= '0' && str_else[i] < '9')
	{
		str_else[i]++;
		str_else[n] = '\0';
		nine_to_nul(str_else, i + 1);
	}
	else
	{
		str = h_nul_rigor(str);
		str_else[n] = '\0';
		nine_to_nul(str_else, 0);
	}
	return (str);
}

static int				h_found_line_up_u(char *str, int i, int *num, int z)
{
	if ((str[i] == '0' && str[i + 1] >= '0' && str[i + 1] <= '9')
	|| (str[i] == '+' && (str[i + 1] >= '0' && str[i + 1] <= '9')))
		num[4] = 0;
	if (z == 0)
		return (ft_atoi1(&str[i]));
	else if (z == 1)
		return (ft_atoi1(&str[i + 1]));
	return ((-1) * ft_atoi1(&str[i + 1]));
}

int						found_line_up_u(char *str, int i, int *num)
{
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			while (h_nno(str, i) == 1)
			{
				if (str[i] == '#' && (str[i + 1] >= '0' &&
				str[i + 1] <= '9') && str[i - 1] == '-')
					return (h_found_line_up_u(str, i, num, 2));
				if (str[i] == '#' && (str[i + 1] >= '0' &&
				str[i + 1] <= '9') && str[i - 1] == '+')
					return (h_found_line_up_u(str, i, num, 1));
				if ((str[i] >= '0' && str[i] <= '9') || ((str[i] == '-' ||
				str[i] == '+') && (str[i + 1] >= '0' && str[i + 1] <= '9')))
					return (h_found_line_up_u(str, i, num, 0));
				i++;
			}
			if (str[i] == 'u' || str[i] == 'U')
				return (0);
		}
		i++;
	}
	return (0);
}

int						found_rigor_u(char *str, int j)
{
	int num;
	int k;

	k = 0;
	num = -2;
	while (str[j] != '%')
		j++;
	while (str[j] != 'u' && str[j] != 'U')
	{
		if (k == 0 && str[j] == '.')
			num = -1;
		if (str[j] == '.' && (str[j + 1] >= '0' && str[j + 1] <= '9'))
		{
			k = 1;
			num = ft_atoi1(&str[j + 1]);
			if (num == 2147483647)
				num = 0;
		}
		j++;
	}
	return (num);
}
