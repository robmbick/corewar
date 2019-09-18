/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 11:12:17 by bnetschu          #+#    #+#             */
/*   Updated: 2019/05/07 13:24:17 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_itoa_base(unsigned long long int nbr, int base, int x)
{
	char					*str;
	int						i;
	unsigned long long int	n;

	i = 1;
	n = nbr;
	while (n >= (unsigned long long)base)
	{
		i++;
		n /= base;
	}
	str = (char*)malloc(sizeof(char) * (i + 1));
	ft_bzero1(str, i + 2);
	while (i-- > 0)
	{
		str[i] = (nbr % base) + (nbr % base > 9 ? x - 10 : '0');
		nbr /= base;
	}
	return (str);
}

static char	*h_itoa_double(long double nbr_d, int *n, char *s)
{
	char		*str;
	__int128_t	nbr;
	char		*str_else;
	int			i[3];

	str_else = (char*)malloc(sizeof(char) * (38 + *n));
	i[0] = 0;
	nbr = nbr_d;
	str = ft_itoa_base_stan(nbr);
	nbr_d -= nbr;
	(nbr_d < 0.0000000000000000) ? nbr_d *= (-1) : 0;
	i[2] = *n;
	f_else_double(i, nbr_d, nbr, str_else);
	str = ft_round_f(str, str_else, *n);
	if (*n == -1 || n == 0)
		s = str;
	else
	{
		s = ft_strjoin_f(str, str_else);
		free(str);
	}
	free(str_else);
	*n = -2;
	return (s);
}

char		*ft_itoa_base_double(long double nbr_d, int *n)
{
	char		*s;

	s = (char*)malloc(sizeof(char) * 5);
	ft_bzero1(s, 5);
	if (nbr_d == (0.0 / 0.0) || nbr_d != nbr_d)
	{
		s[0] = 'n';
		s[1] = 'a';
		s[2] = 'n';
	}
	else if (nbr_d == 3.0 / 0.0)
		s = f_inf(s, 0);
	else if (nbr_d == -3.0 / 0.0)
		s = f_inf(s, -1);
	else
	{
		free(s);
		return (h_itoa_double(nbr_d, n, s));
	}
	*n = -1;
	return (s);
}

static void	ret_i(__int128_t n, int *i)
{
	while (n >= 10)
	{
		i[0]++;
		n /= 10;
	}
}

char		*ft_itoa_base_stan(__int128_t nbr)
{
	char		*str;
	int			i[2];

	i[0] = 1;
	i[1] = (nbr > 9223372036854775807) ? 1 : 0;
	if (nbr < 0)
	{
		i[1] = 1;
		nbr *= -1;
	}
	ret_i(nbr, i);
	str = (char*)malloc(sizeof(char) * (i[0] + 2 + i[1]));
	ft_bzero1(str, i[0] + 2 + i[1]);
	while (i[0]-- > 0)
	{
		str[i[0] + i[1]] = (nbr % 10) + (nbr % 10 > 9 ? 'a' - 10 : '0');
		nbr /= 10;
	}
	(i[1] == 1) ? str[0] = '-' : 0;
	return (str);
}
