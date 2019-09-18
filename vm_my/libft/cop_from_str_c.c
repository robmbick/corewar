/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cop_from_str_c.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 12:23:15 by bnetschu          #+#    #+#             */
/*   Updated: 2019/05/07 13:27:00 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			cop_from_str2_c(char *fr, char *string, int *n)
{
	int j;
	int i;

	i = 0;
	j = 0;
	while (string[j])
		j++;
	while (i < j)
	{
		fr[n[2]] = string[i];
		i++;
		n[2]++;
	}
	while (fr[n[2]] == ' ' && fr[n[2]])
		n[2]++;
	return (n[2]);
}

int			cop_from_str_c(char *fr, char *string, int *n)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (string[j])
		j++;
	if (n[1] - j <= 0)
		while (i <= j)
		{
			fr[n[2]] = string[i];
			i++;
			n[2]++;
		}
	else
	{
		while (i < j)
		{
			fr[n[1] - j + n[2]] = string[i];
			i++;
			n[2]++;
		}
		return (n[1] - j + n[2]);
	}
	return (n[2] - 1);
}

void		nul_c(int *num, int *nul, unsigned int *i)
{
	if (num[3] == 1)
	{
		*nul = i[0];
		if (num[1] != 0)
		{
			nul[1] = 1;
			*nul = i[0] - 1;
		}
	}
}

int			ret_dod_s(int num, char *string, int *i)
{
	while (string[i[1]] && num != 0)
	{
		i[1]++;
		num--;
	}
	return (num);
}

void		h_cop_str2_p(char *fr, int *n, char *string, int *i)
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
				if (n[5] == 0)
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
