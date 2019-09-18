/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hh_pars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 18:24:19 by bnetschu          #+#    #+#             */
/*   Updated: 2019/05/07 13:29:59 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		hhh_pars(t_norm *norm, int *z)
{
	free(norm->str_f);
	norm->i = *z;
	return (1);
}

static int		hh_pars2(t_norm *norm, int *z)
{
	int k;

	k = 0;
	if (norm->str[norm->i] == 'p')
	{
		norm->str = flag_p(norm->str, norm->argptr, z);
		k = hhh_pars(norm, z);
	}
	else if (norm->str[norm->i] == 'i' || norm->str[norm->i] == 'd')
	{
		norm->str = flag_i(norm->str, norm->argptr, z);
		k = hhh_pars(norm, z);
	}
	else if (norm->str[norm->i] == 'f')
	{
		norm->str = flag_f(norm->str, norm->argptr, z);
		k = hhh_pars(norm, z);
	}
	return (k);
}

static int		hh_pars1(t_norm *norm, int *z)
{
	int k;

	k = 0;
	if (norm->str[norm->i] == 'u' || norm->str[norm->i] == 'U')
	{
		norm->str = flag_u(norm->str, norm->argptr, z);
		k = hhh_pars(norm, z);
	}
	else if (norm->str[norm->i] == 'x' || norm->str[norm->i] == 'X')
	{
		norm->str = flag_x(norm->str, norm->argptr, z);
		k = hhh_pars(norm, z);
	}
	else if (norm->str[norm->i] == 'o')
	{
		norm->str = flag_o(norm->str, norm->argptr, z);
		k = hhh_pars(norm, z);
	}
	else
		k = hh_pars2(norm, z);
	return (k);
}

int				hh_pars(t_norm *norm, int *z, int *nul)
{
	int k;

	k = 0;
	if (norm->str[norm->i] == 's')
	{
		norm->str = flag_s(norm->str, norm->argptr, z);
		k = hhh_pars(norm, z);
	}
	else if (norm->str[norm->i] == 'c')
	{
		norm->str = flag_c(norm->str, norm->argptr, z, nul);
		k = hhh_pars(norm, z);
	}
	else if (norm->str[norm->i] == '%')
	{
		norm->str = non_flag(norm->str, z);
		k = hhh_pars(norm, z);
	}
	else
		k = hh_pars1(norm, z);
	return (k);
}
