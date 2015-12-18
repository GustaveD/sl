/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosamon <jrosamon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/05 17:02:12 by jrosamon          #+#    #+#             */
/*   Updated: 2015/12/18 18:27:55 by jrosamon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int ac, char **av)
{
	char	opt[8];
	int		i;
	t_list	*dir;

	dir = NULL;
	i = ft_get_opt(opt, av, ac);
	ft_get_dirlst(&dir, &av[i], ac, opt);
//	ft_print_d_name(&dir);
//	if (O_R)
//		ft_reverslst(&dir);
	ft_ls(&dir, opt);
	return (0);
}

void	ft_ls(t_list **dirlst, char *opt)
{
	t_list	*tmp;

	tmp = *dirlst;
	IS_OPT = (tmp->next == NULL) ? 3 : 2; // ". || dir1 dir2"
	while (tmp)
	{
		if (((t_info*)tmp->content)->dirent->d_type == DT_DIR)
		{
			ft_dir_process(tmp, opt);
		}
		else
			ft_print_info(opt, tmp, NULL);
		tmp = tmp->next;
		IS_OPT = 1;
	}	
}
