/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 14:36:56 by bnetschu          #+#    #+#             */
/*   Updated: 2019/09/17 15:31:06 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		main(int argc, char **argv)
{
	g_nbr_cycles = -1;
	if (argc > 1)
	{
		if (pars_bot(argc, argv))
		{
			printf(MAGENTA"NICE !\n"RESET);
		}
	}
	else
	{
		printf("FAIL!\n");// usage here
	}
	return (0);
}
