/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cop_from_str_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 16:13:47 by bnetschu          #+#    #+#             */
/*   Updated: 2019/05/08 10:47:07 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		hh_cop_x(char *fr, char *string, int *n, int *i)
{
	if (n[5] > 0)
		while (n[5] > 0)
		{
			if (n[6] == 1 && string[0] != '0')
			{
				fr[n[2]] = (i[4] == 1) ? ' ' : '0';
				if (n[7] == 65)
					fr[n[2] + 1] = (i[4] == 1) ? ' ' : 'X';
				else if (n[7] == 97)
					fr[n[2] + 1] = (i[4] == 1) ? ' ' : 'x';
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
}

static void		hh_cop_x1(char *fr, char *string, int *n, int *i)
{
	if (n[5] > 0)
		while (i[2] != 0)
		{
			if (n[6] == 1 && string[0] != '0')
			{
				fr[n[2] + n[1] - i[1] - n[5]] = (i[4] == 1) ? ' ' : '0';
				if (n[7] == 65)
					fr[n[2] + n[1] - i[1] - n[5] + 1] = (i[4] == 1) ? ' ' : 'X';
				else if (n[7] == 97)
					fr[n[2] + n[1] - i[1] - n[5] + 1] = (i[4] == 1) ? ' ' : 'x';
				n[2] += 2;
				n[6] = 0;
				i[2] -= 2;
				if (i[2] <= 0)
					break ;
			}
			fr[n[2] + n[1] - i[1] - n[5]] = '0';
			n[2]++;
			i[2]--;
		}
}

static void		h_copstr_x(int *n, int *i, char *string, char *fr)
{
	i[4] = 0;
	i[3] = 0;
	i[1] = 0;
	i[0] = 0;
	i[5] = h_cop_x(n, fr, string, i[6]);
	if ((n[5] == -1 || n[5] == 0) && n[1] == 0 && string[0] == '0')
		i[3] = -1;
	if (n[5] == -1 && string[0] == '0')
		string[0] = ' ';
	if (n[5] == 0 && string[0] == '0')
	{
		i[4] = 1;
		string[0] = ' ';
	}
	while (string[i[1]])
	{
		i[1]++;
		if (n[5] > 0)
			n[5]--;
	}
	n[5] += i[5];
	if (n[5] <= -1)
		n[5] = 0;
	i[2] = n[5];
}

static void		hhh_cs_x(char *fr, char *string, int *n, int *i)
{
	hh_cop_x(fr, string, n, i);
	while (string[i[0]] && i[3] == 0)
	{
		fr[n[2]] = string[i[0]];
		i[0]++;
		n[2]++;
	}
}

int				cop_from_str_x(char *fr, char *string, int *n, int w)
{
	int i[7];

	i[6] = w;
	h_copstr_x(n, i, string, fr);
	if (n[1] - i[1] - n[5] <= 0)
		hhh_cs_x(fr, string, n, i);
	else
	{
		hh_cop_x1(fr, string, n, i);
		while (string[i[0]] && i[3] == 0)
		{
			fr[n[1] - i[1] + n[2] - n[5]] = string[i[0]];
			i[0]++;
			n[2]++;
		}
		return (n[1] - i[1] + n[2] - n[5]);
	}
	return (n[2]);
}
