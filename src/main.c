/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosamon <jrosamon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/05 17:02:12 by jrosamon          #+#    #+#             */
/*   Updated: 2015/11/23 15:13:24 by jrosamon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int ac, char **av)
{
	char	opt[6];
	int		i;
	t_list	*dir;

	dir = NULL;
	i = ft_get_opt(opt, av, ac);
	ft_get_dirlst(&dir, &av[i], ac);
	ft_ls(&dir, opt);
	return (0);
}

void	ft_ls(t_list **dirlst, char *opt)
{
	t_list	*tmp;

	tmp = *dirlst;
	while (tmp)
	{
		if (((t_dir*)tmp->content)[0].d_type == DT_DIR)
		{
		//	printf("type = %hhu\n", ((t_dir*)tmp->content)[0].d_type);
			ft_dir_process(tmp, opt);
		}
		else
		{
			ft_print_process(((t_dir*)tmp->content)[0].d_name, opt);
		//	printf("File's name = '%s'\n", ((t_dir*)tmp->content)[0].d_name);
		}
		tmp = tmp->next;
	}	
}
