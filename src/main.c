/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosamon <jrosamon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/05 17:02:12 by jrosamon          #+#    #+#             */
/*   Updated: 2015/11/20 19:39:45 by jrosamon         ###   ########.fr       */
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
	printf("i = %d\n", i);
	ft_get_dirlst(&dir, &av[i], ac);
//	printf("dir->name ='%s'\n", ((t_dir*)dir->content)->d_name);
//	ft_print_d_name(&dir);
	ft_ls(&dir);
	return (0);
}

void	ft_ls(t_list **dirlst)
{
	t_list	*tmp;

	tmp = *dirlst;
	while (tmp)
	{
		if (((t_dir*)tmp->content)[0].d_type == DT_DIR)
		{
			printf("type = %hhu\n", ((t_dir*)tmp->content)[0].d_type);
			ft_dir_process(tmp);
		}
		else
			printf("File's name = '%s'\n", ((t_dir*)tmp->content)[0].d_name);
		tmp = tmp->next;
	}	
}
