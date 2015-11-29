/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosamon <jrosamon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/20 12:10:50 by jrosamon          #+#    #+#             */
/*   Updated: 2015/11/29 19:59:40 by jrosamon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_init_opt(char *opt, char *arg)
{
	int i;

	i = 1;
	while (arg[i])
	{
		IS_OPT = 1;
		if (arg[i] == 'l')
			O_L = 1;
		else if (arg[i] == 'r')
			O_R = 1;
		else if (arg[i] == 'R')
			O_BR = 1;
		else if (arg[i] == 'a')
			O_A = 1;
		else if (arg[i] == 't')
			O_T = 1;
		else
		{
			ft_putstr("illegal options\n");
			ft_putstr("managed option: -lRrat\n");
		}
		i++;
	}
}

int		ft_get_opt(char *opt, char **av, int ac)
{
	int i;

	i = 1;
	ft_bzero(opt, 6);
	while (i < ac && av[i][0] == '-' && av[i])
	{
		ft_init_opt(opt, av[i]);
		i++;	
	}
	return (i);
}
