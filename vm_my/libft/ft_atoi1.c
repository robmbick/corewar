/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 19:47:07 by bnetschu          #+#    #+#             */
/*   Updated: 2019/05/06 17:38:38 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void				found_oktorp_x(char *str, int i, int *num)
{
	num[6] = 0;
	while (str[i] != 'x' && str[i] != 'X')
	{
		if (str[i] == '#')
			num[6] = 1;
		i++;
	}
	num[7] = 97;
	if (str[i] == 'X')
		num[7] = 65;
}

int					prom1(int i, char *str, char k, char l)
{
	while (str[i] != k && str[i] != l)
		i++;
	i++;
	return (i);
}

int					nons_minus(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

long long int		ft_atoi1(const char *str)
{
	long long int i;
	long long int nb;
	long long int j;

	i = 0;
	nb = 0;
	j = 0;
	while (str[i] == 32 || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\r' || str[i] == '\t' || str[i] == '\f')
		i++;
	if (str[i] == 45 || str[i] == 43)
	{
		j = 1;
		if (str[i] == 43)
			j = 0;
		i++;
	}
	while (str[i] <= 57 && str[i] >= 48)
	{
		nb = nb * 10 + (long long int)str[i] - '0';
		i++;
	}
	if (j == 1)
		nb *= (-1);
	return (nb);
}
