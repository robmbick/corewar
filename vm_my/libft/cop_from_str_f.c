/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cop_from_str_f.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 12:39:18 by bnetschu          #+#    #+#             */
/*   Updated: 2019/05/07 14:39:01 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	h_cop_from_str_f(int *n, char *fr, char *string, int *i)
{
	if (n[6] == 1)
	{
		fr[n[2]] = (n[7] == 2) ? '+' : '-';
		n[2]++;
	}
	if (n[5] > 0)
		while (n[5] != 0)
		{
			fr[n[2]] = '0';
			n[2]++;
			n[5]--;
		}
	(fr[n[2]] == '-' || fr[n[2]] == '+') ? n[2]++ : 0;
	while (string[i[0]] && i[3] == 0)
	{
		fr[n[2]] = string[i[0]];
		i[0]++;
		n[2]++;
	}
}

static int	h_f(int *n, int *i, char *fr, char *string)
{
	if (n[6] == 1)
		fr[n[2] + n[1] - i[1] - n[5] - 1] = (n[7] == 2) ? '+' : '-';
	if (n[5] > 0)
		while (i[2] != 0)
		{
			fr[n[2] + n[1] - i[1] - n[5]] = '0';
			n[2]++;
			i[2]--;
		}
	while (string[i[0]] && i[3] == 0)
	{
		fr[n[1] - i[1] + n[2] - n[5]] = string[i[0]];
		i[0]++;
		n[2]++;
	}
	return (n[1] - i[1] + n[2] - n[5]);
}

void		hh_cop_f(char *string, int *i, int *n)
{
	while (string[i[1]])
	{
		i[1]++;
		if (n[5] > 0)
			n[5]--;
	}
}

int			cop_from_str_f(char *fr, char *string, int *n)
{
	int i[4];

	i[1] = 0;
	i[0] = 0;
	i[3] = 0;
	if ((n[5] == -1 || n[5] == 0) && n[1] == 0 && string[0] == '0')
		i[3] = -1;
	(n[5] == -1 && string[0] == '0') ? string[0] = ' ' : 0;
	(n[5] == 0 && string[0] == '0') ? string[0] = ' ' : 0;
	hh_cop_f(string, i, n);
	(n[5] <= -1) ? n[5] = 0 : 0;
	if (n[8] == 1 && n[6] == 0)
	{
		fr[n[2]] = ' ';
		if (ft_strlen(string) < (size_t)n[1])
			n[1]--;
		n[2]++;
	}
	i[2] = n[5];
	if (n[1] - i[1] - n[5] <= 0)
		h_cop_from_str_f(n, fr, string, i);
	else
		return (h_f(n, i, fr, string));
	return (n[2]);
}

int			cop_from_str2_f(char *fr, char *string, int *n)
{
	int i[3];

	i[2] = 0;
	i[0] = 0;
	i[1] = 0;
	if ((n[5] == -1 || n[5] == 0) && n[1] == 0 && string[0] == '0')
		i[2] = -1;
	if (n[5] == -1 && string[0] == '0')
		string[0] = ' ';
	if (n[5] == 0 && string[0] == '0')
		string[0] = ' ';
	while (string[i[1]])
	{
		i[1]++;
		if (n[5] > 0)
			n[5]--;
	}
	if (n[5] <= -1)
		n[5] = 0;
	h_cop_fr_str2_f(n, i, fr, string);
	while (fr[n[2]] == ' ' && fr[n[2]])
		n[2]++;
	return (n[2]);
}
