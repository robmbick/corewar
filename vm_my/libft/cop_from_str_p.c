/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cop_from_str_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 13:25:00 by bnetschu          #+#    #+#             */
/*   Updated: 2019/09/13 14:22:10 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		h_cop_p(char *fr, int *n, char *string, int *i)
{
	if (n[5] > 0)
		while (n[5] != 0)
		{
			if (n[6] == 1)
			{
				fr[n[2]] = '0';
				(n[7] == 65) ? fr[n[2] + 1] = 'X' : 0;
				(n[7] == 97) ? fr[n[2] + 1] = 'x' : 0;
				n[2] += 2;
				n[6] = 0;
				n[5] -= 2;
				if (n[5] <= 0)
					break ;
			}
			fr[n[2]] = '0';
			n[2]++;
			n[5]--;
		}
	while (string[i[0]] && i[2] == 0)
	{
		fr[n[2]] = string[i[0]];
		i[0]++;
		n[2]++;
	}
}

static int		hh_cop_p(char *fr, int *n, char *string, int *i)
{
	if (n[5] > 0)
		while (i[3] != 0)
		{
			if (n[6] == 1)
			{
				fr[n[2] + n[1] - i[1] - n[5]] = '0';
				if (n[7] == 65)
					fr[n[2] + n[1] - i[1] - n[5] + 1] = (i[4] == 1) ? ' ' : 'X';
				else if (n[7] == 97)
					fr[n[2] + n[1] - i[1] - n[5] + 1] = (i[4] == 1) ? ' ' : 'x';
				n[2] += 2;
				n[6] = 0;
				i[3] -= 2;
				if (i[3] <= 0)
					break ;
			}
			fr[n[2] + n[1] - i[1] - n[5]] = '0';
			n[2]++;
			i[3]--;
		}
	hhh_cop_p(string, i, n, fr);
	return (n[1] - i[1] + n[2] - n[5]);
}

static void		h_copstr_p(char *string, int *i, int *n, int w)
{
	while (string[i[1]])
	{
		i[1]++;
		if (n[5] > 0)
			n[5]--;
	}
	if (n[6] == 1 && w != 1)
	{
		if (n[5] <= -1)
			n[5] = 0;
		n[5] += 2;
	}
}

int				cop_from_str_p(char *fr, char *string, int *n, int w)
{
	int i[4];

	i[2] = 0;
	i[1] = 0;
	i[0] = 0;
	if (n[4] == 0 && n[5] == -2 && w == 1 && n[6] == 1)
	{
		(n[7] == 65) ? fr[n[2] + 1] = 'X' : 0;
		(n[7] == 97) ? fr[n[2] + 1] = 'x' : 0;
	}
	if ((n[5] == -1 || n[5] == 0) && n[1] == 0 && string[0] == '0')
		i[2] = -1;
	if (n[5] == -1 && string[0] == '0')
		string[0] = ' ';
	if (n[5] == 0 && string[0] == '0')
		string[0] = ' ';
	h_copstr_p(string, i, n, w);
	if (n[5] <= -1)
		n[5] = 0;
	i[3] = n[5];
	if (n[1] - i[1] - n[5] <= 0)
		h_cop_p(fr, n, string, i);
	else
		return (hh_cop_p(fr, n, string, i));
	return (n[2]);
}

int				cop_from_str2_p(char *fr, char *string, int *n)
{
	int i[3];

	i[2] = 0;
	i[0] = 0;
	i[1] = 0;
	while (string[i[1]])
	{
		i[1]++;
		if (n[5] > 0)
			n[5]--;
	}
	if (n[6] == 1)
	{
		if (n[5] <= -1)
			n[5] = 0;
		n[5] += 2;
	}
	if (n[5] == -1 && string[0] == '0')
		string[0] = ' ';
	h_cop_str2_p(fr, n, string, i);
	while (fr[n[2]] == ' ' && fr[n[2]])
		n[2]++;
	return (n[2]);
}
