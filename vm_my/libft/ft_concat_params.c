/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_paramas.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 17:06:52 by bnetschu          #+#    #+#             */
/*   Updated: 2018/11/07 15:52:46 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_strlen_dynamic(int argc, char **argv)
{
	int i;
	int j;
	int k;

	k = 1;
	i = 0;
	while (k < argc)
	{
		j = 0;
		while (argv[k][j] != '\0')
		{
			i++;
			j++;
		}
		i++;
		k++;
	}
	return (i);
}

char			*ft_concat_params(int argc, char **argv)
{
	char	*dest;
	int		i;
	int		j;
	int		k;
	int		t;

	k = 0;
	j = 1;
	t = ft_strlen_dynamic(argc, argv);
	dest = (char*)malloc(t);
	while (j < argc)
	{
		i = 0;
		while (argv[j][i])
		{
			dest[k] = argv[j][i];
			i++;
			k++;
		}
		dest[k] = '\n';
		k++;
		j++;
	}
	dest[k - 1] = '\0';
	return (dest);
}
