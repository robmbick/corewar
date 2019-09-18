/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_bot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 16:41:07 by bnetschu          #+#    #+#             */
/*   Updated: 2019/09/17 15:28:53 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		check_line_for_dump(char **argv, int ss)
{
	int		i;
	char	*line;

	i = -1;
	if (ft_strcmp(*argv, "-dump") == 0)
	{
		g_kost_dump++;
		if (g_kost_dump > 1)
		{
			ft_printf(YELLOW"Warning -dump would be rewriting !\n"RESET);
		}
		if (ss == 0)
		{
			ft_printf(RED"ERROR after '-dump' must be number! but now nothing!!\n"RESET);
			exit(1);
		}
		argv++;
		line = *argv;
		while (line[++i])
			if (line[i] <= '0' || line[i] >= '9')
			{
				ft_printf(RED"ERROR after '-dump' must be number!\n"RESET);
				exit(1);
			}
		g_nbr_cycles = ft_atoi(*argv);
		return (1);
	}
	return (0);
}

int		check_deskript_num(int	num)
{
	t_deskriptor	*ch;

	ch = g_deskript;
	while (ch != NULL)
	{
		if (ch->num == num)
			return (0);
		ch = ch->next;
	}
	return (1);
}

void	check_str_for_cor(char *lin)
{
	char *line;

	line = lin;
	while (1)
	{
		if ((line = ft_strstr(line, ".cor")) == NULL)
		{
			ft_printf(RED"ERROR where '.cor' ????\n"RESET);
			exit(1);
		}
		if (ft_strcmp(line, ".cor") != 0)
		{
			line++;
			continue ;
		}
		break ;
	}
}

int		check_line_for_n(char **argv, t_deskriptor *des, int ss)
{
	int		i;
	int		num;
	char	*line;

	i = -1;
	if (ft_strcmp(*argv, "-n") == 0)
	{
		if (ss == 0)
		{
			ft_printf("ERROR after '-n' must be number and player!\n");
			exit(1);
		}
		argv++;
		line = *argv;
		while (line[++i] != '\0')
			if (line[i] <= '0' || line[i] >= '9')
			{
				ft_printf(RED"ERROR after '-n' must be number between 1 and %i!\n"RESET, MAX_PLAYERS);
				exit(1);
			}
		num = ft_atoi(*argv);
		if (num <= 0 || num > MAX_PLAYERS || check_deskript_num(num) == 0)
		{
			ft_printf(RED"ERROR incorect number after '-n'\n"RESET);
			exit(1);
		}
		argv++;
		des->name = *argv;
		check_str_for_cor(des->name);
		des->num = num;
		return (1);
	}
	return (0);
}

void	record_name(char *name, t_deskriptor *des)
{
	int		i;

	i = 0;
	check_str_for_cor(name);
	des->name = name;
	while (++i <= MAX_PLAYERS + 1)
	{
		if (check_deskript_num(i) == 1)
		{
			g_kostul = des;
			des->num = 0; // numer after all -n
			des->next = (t_deskriptor*)malloc(sizeof(t_deskriptor));
			des->next->next = NULL;
			return ;
		}
	}
	ft_printf(RED"ERROR number of player is %i\n"RESET, MAX_PLAYERS);
	exit(1);
}

void	numer_deskript()
{
	t_deskriptor	*des;
	int				i;

	des = g_deskript;
	while (des != NULL)
	{
		if (des->num == 0)
		{
			i = 0;
			while (++i <= MAX_PLAYERS + 1)
			{
				if (check_deskript_num(i) == 1)
				{
					des->num = i;
					break ;
				}
			}
			if (des->num == 0)
			{
				ft_printf(RED"ERROR number of player is %i\n"RESET, MAX_PLAYERS);
				exit(1);
			}
		}
		des = des->next;
	}
}

int		pars_bot(int argc, char **argv)
{
	int				i;
	char			*line;
	t_deskriptor	*des;

	g_kost_dump = 0;
	g_deskript = (t_deskriptor*)malloc(sizeof(t_deskriptor));
	g_deskript->num = 0;
	g_deskript->next = NULL;
	i = 0;
	des = g_deskript;
	while (++i < argc)
	{
		if (check_line_for_n(&argv[i], des, (i + 2 >= argc) ? 0 : 1) == 1)
		{
			g_kostul = des;
			des->next = (t_deskriptor*)malloc(sizeof(t_deskriptor));
			des = des->next;
			des->next = NULL;
			i = i + 2;
		}
		else if (check_line_for_dump(&argv[i], (i + 1 >= argc) ? 0 : 1) == 1)
			i++;
		else
		{
			record_name(argv[i], des);
			des = des->next;
		}
	}
	free(g_kostul->next);
	g_kostul->next = NULL;
	numer_deskript();
	check_file();
	//system("leaks -q a.out");
	return (1);
}