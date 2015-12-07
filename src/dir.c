/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosamon <jrosamon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/20 15:31:16 by jrosamon          #+#    #+#             */
/*   Updated: 2015/12/07 13:57:53 by jrosamon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ft_dir_process(t_list *dirlst, char *opt)
{
	DIR		*dir;
	t_list	*dir_content;
	t_list	*tmp;

	tmp = dirlst;
	dir_content = NULL;
	dir = opendir(((t_info*)tmp->content)->dirent->d_name);
	if (dir == NULL)
		return (-1);
	ft_get_dir_content(dir, &dir_content, ((t_info*)tmp->content)->dirent->d_name, opt);
	ft_dir_recurs(&dir_content, opt);
//	ft_lstdel(&dir_content, ft_free_data);
		return (0);
}

t_list		*ft_get_dir_content(DIR *dir, t_list **dir_content, char *dir_path, char *opt)
{
	t_list *newdir;
	t_dir *dirent;
	char	newpath[500];

	newdir = NULL;
	while ((dirent = readdir(dir)))
	{
		if (O_A || dirent->d_name[0] != '.' 
				|| (O_BR && dirent->d_type == DT_DIR &&
					ft_strcmp(dirent->d_name, ".") != 0 &&
				ft_strcmp(dirent->d_name, "..") != 0))
		{
			ft_set_path(dirent, dir_path, newpath);
			ft_new_dir2(dir_content, newpath, opt);
		}
	}
	return (*dir_content);
}

void		ft_dir_recurs(t_list **newdir, char *opt)
{
	t_list	*tmp;

	tmp = *newdir;
	while (tmp)
	{
		if (((t_info*)tmp->content)->dirent->d_type == DT_DIR &&
				ft_strcmp(((t_info*)tmp->content)->dirent->d_name, ".") != 0 && 
				ft_strcmp(((t_info*)tmp->content)->dirent->d_name,"..") != 0 && O_BR)
		{
			ft_dir_process(tmp, opt);
			ft_putchar('\n');
		}
		else
			ft_print_process(tmp, opt);
		tmp = tmp->next;
	}
}

void		ft_get_dirlst(t_list **head, char **av, int ac, char *opt)
{
	int i;

	i = 0;
	if (!av[i])
		ft_new_dir2(head, ".", opt);
	while (i < ac && av[i])
	{
		//ft_new_dir(head, av[i], opt);
		ft_new_dir2(head, av[i], opt);
		i++;	
	}
}

t_list		*ft_new_dir2(t_list **head, char *path, char *opt)
{
	t_list	*newdir;
	t_info	*info;
	int		(*f)(const char *, const char *);
	

	info = NULL;
	f = &ft_strcmp;
	if (!(newdir = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!(newdir->content = (void*)malloc(sizeof(void))))
		return (NULL);
	info = ft_new_info(path);
	newdir->content = (t_info*)info;
	newdir = ft_lstnew2(newdir->content, sizeof(void*));
	if (!O_T)
		ft_lstaddbyalph(head, newdir, f, opt);
	else
		ft_lstaddbytime(head, newdir, opt);
	return (newdir);
}

t_info		*ft_new_info(char *path)
{
	t_info	*new;

	if (!(new = (t_info*)malloc(sizeof(t_info))))
		return (NULL);
	if (!(new->dirent = (t_dir*)malloc(sizeof(t_dir))))
		return (NULL);
	if (!(new->stat = (t_stat*)malloc(sizeof(t_stat))))
		return (NULL);
	ft_strcpy(new->dirent->d_name, path);
	new->dirent->d_type = DT_UNKNOWN;
	new->stat = get_data(path, new->dirent, new->stat);
	return (new);
}

t_stat		*get_data(char *path, t_dir *dirent, t_stat *dstat)
{
	if (dirent->d_type == DT_LNK || dirent->d_type == DT_UNKNOWN)
	{
		if (lstat(path, dstat) == -1)
			return (NULL);
	}
	else if (stat(path,dstat) == -1)
		return (NULL);
	if (dirent->d_type == DT_UNKNOWN)
		dirent->d_type = IFTODT(dstat->st_mode);
	return (dstat);
}

void		ft_print_d_name(t_list **head)
{
	t_list *tmp;

	tmp = *head;
	while (tmp)
	{
		printf("dir-name = '%s'\n", ((t_info*)tmp->content)->dirent->d_name);
		tmp = tmp->next;
	}
}
