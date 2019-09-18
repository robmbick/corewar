/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cop_from_str_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 15:19:25 by bnetschu          #+#    #+#             */
/*   Updated: 2019/05/07 13:30:48 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	h_cop_u(int *n, char *fr, char *string, int *i)
{
	if (n[5] > 0)
		while (n[5] != 0)
		{
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

static int	hh_cop_u(int *n, char *fr, char *string, int *i)
{
	if (n[5] > 0)
		while (i[3] != 0)
		{
			fr[n[2] + n[1] - i[1] - n[5]] = '0';
			n[2]++;
			i[3]--;
		}
	while (string[i[0]] && i[2] == 0)
	{
		fr[n[1] - i[1] + n[2] - n[5]] = string[i[0]];
		i[0]++;
		n[2]++;
	}
	return (n[1] - i[1] + n[2] - n[5]);
}

int			cop_from_str_u(char *fr, char *string, int *n)
{
	int i[4];

	i[1] = 0;
	i[0] = 0;
	i[2] = ((n[5] == -1 || n[5] == 0) &&
		n[1] == 0 && string[0] == '0') ? -1 : 0;
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
	i[3] = n[5];
	if (n[1] - i[1] - n[5] <= 0)
		h_cop_u(n, fr, string, i);
	else
		return (hh_cop_u(n, fr, string, i));
	return (n[2]);
}

static int	h_cop2_u(char *string, char *fr, int i, int *n)
{
	while (string[i])
	{
		fr[n[2]] = string[i];
		i++;
		n[2]++;
	}
	return (i);
}

int			cop_from_str2_u(char *fr, char *string, int *n)
{
	int j;
	int i;

	i = 0;
	j = 0;
	while (string[j])
	{
		j++;
		if (n[5] != 0)
			n[5]--;
	}
	if (n[5] > 0)
		while (n[5] != 0)
		{
			fr[n[2]] = '0';
			n[2]++;
			n[5]--;
		}
	i = h_cop2_u(string, fr, i, n);
	while (fr[n[2]] == ' ' && fr[n[2]])
		n[2]++;
	return (n[2]);
}
