/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 09:55:11 by bnetschu          #+#    #+#             */
/*   Updated: 2019/05/03 18:27:09 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			h_pars(t_norm *norm, int *z, int *nul)
{
	if (hh_pars(norm, z, nul) == 1)
		;
	else
	{
		norm->i = *z;
		while (norm->str[norm->i + norm->t])
		{
			norm->str[norm->i] = norm->str[norm->i + norm->t];
			norm->i++;
		}
		norm->str[norm->i] = '\0';
		norm->i = *z;
	}
}

static t_norm		w_pars_str(t_norm norm)
{
	while ((norm.str[norm.i] == ' ' && norm.str[norm.i]) ||
		(norm.str[norm.i] >= '0' && norm.str[norm.i] <= '9') ||
		(norm.str[norm.i] == '-' && (norm.str[norm.i + 1] >= '0' &&
		norm.str[norm.i + 1] <= '9')) || norm.str[norm.i] == '.' ||
		norm.str[norm.i] == '-' || norm.str[norm.i] == '+' ||
		norm.str[norm.i] == '#' || norm.str[norm.i] == 'l' ||
		norm.str[norm.i] == 'h' || norm.str[norm.i] == 'L' ||
		norm.str[norm.i] == '#')
	{
		norm.t++;
		norm.i++;
	}
	return (norm);
}

static char			*pars_str(char *st, va_list *argpt, int *nul)
{
	int		z;
	t_norm	norm;

	norm.t = 1;
	norm.argptr = argpt;
	norm.str = st;
	norm.i = 0;
	while (norm.str[norm.i])
	{
		if (norm.str[norm.i] == '%')
		{
			norm.t = 1;
			norm.str_f = norm.str;
			z = norm.i;
			norm.i++;
			norm = w_pars_str(norm);
			h_pars(&norm, &z, nul);
		}
		norm.i++;
	}
	return (norm.str);
}

int					ft_printf(const char *str, ...)
{
	int		nul[2];
	int		sum;
	char	*s;
	va_list	argptr;

	nul[0] = -1;
	nul[1] = -1;
	va_start(argptr, str);
	s = pars_str(ft_strjoin(str, "\0"), &argptr, nul);
	sum = write_s(s, nul);
	free(s);
	va_end(argptr);
	return (sum);
}
