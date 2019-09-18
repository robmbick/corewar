/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 18:41:30 by bnetschu          #+#    #+#             */
/*   Updated: 2018/10/31 10:31:45 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	while (i != 0 && str[i] != ((char)ch))
		i--;
	if (str[i] == (char)ch)
		return ((char *)&str[i]);
	return (NULL);
}
