/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cop_from_str_o.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 11:52:04 by bnetschu          #+#    #+#             */
/*   Updated: 2019/05/06 12:55:37 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	h_c(char *string, int *n, int j)
{
	if (n[5] == -1 && string[0] == '0' && n[6] != 1)
		string[0] = ' ';
	if (n[5] == 0 && string[0] == '0' && n[6] != 1)
		string[0] = ' ';
	while (string[j])
	{
		j++;
		if (n[5] > 0)
			n[5]--;
	}
	return (j);
}

static void	h_cop(char *string, char *fr, int *n, int *i)
{
	if (n[5] > 0)
		while (n[5] != 0)
		{
			if (n[6] == 1 && string[0] != '0')
			{
				fr[n[2]] = '0';
				n[2] += 1;
				n[6] = 0;
				n[5] -= 2;
				if (n[5] <= 0)
					break ;
			}
			fr[n[2]] = '0';
			n[2]++;
			n[5]--;
		}
	while (string[i[0]] && i[3] == 0)
	{
		fr[n[2]] = string[i[0]];
		i[0]++;
		n[2]++;
	}
}

static int	h_cop1(char *string, int *n, char *fr, int *i)
{
	if (n[5] > 0)
		while (i[2] != 0)
		{
			if (n[6] == 1 && string[0] != '0')
			{
				fr[n[2] + 1 + n[1] - i[1] - n[5]] = '0';
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
	while (string[i[0]] && i[3] == 0)
	{
		fr[n[1] - i[1] + n[2] - n[5]] = string[i[0]];
		i[0]++;
		n[2]++;
	}
	return (n[1] - i[1] + n[2] - n[5]);
}

int			cop_from_str_o(char *fr, char *string, int *n, int w)
{
	int i[5];

	i[1] = 0;
	i[0] = 0;
	i[3] = ((n[5] == -1 || n[5] == 0) && n[1] == 0 &&
			string[0] == '0' && n[6] != 1) ? -1 : 0;
	i[1] = h_c(string, n, i[1]);
	if (n[6] == 1 && string[0] != '0' && w != 1)
	{
		if (n[5] <= -1)
			n[5] = 0;
		n[5] += 2;
	}
	if (n[5] <= -1)
		n[5] = 0;
	i[2] = n[5];
	if (n[1] - i[1] - n[5] < 0)
		h_cop(string, fr, n, i);
	else
		return (h_cop1(string, n, fr, i));
	return (n[2]);
}

int			cop_from_str2_o(char *fr, char *string, int *n)
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
	if (n[6] == 1 && string[0] != '0')
	{
		if (n[5] <= -1)
			n[5] = 0;
		n[5] += 2;
	}
	if (n[5] == -1 && string[0] == '0' && n[6] != 1)
		string[0] = ' ';
	h_cop2_o(n, fr, string, i);
	while (fr[n[2]] == ' ' && fr[n[2]])
		n[2]++;
	return (n[2]);
}
