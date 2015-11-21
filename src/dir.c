/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosamon <jrosamon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/20 15:31:16 by jrosamon          #+#    #+#             */
/*   Updated: 2015/11/21 19:59:25 by jrosamon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ft_dir_process(t_list *dirlst)
{
	DIR		*dir;
	t_list	*dir_content;
	t_list	*tmp;

	tmp = dirlst;
	dir_content = NULL;
	dir = opendir(((t_dir*)tmp->content)[0].d_name);
		printf("opendir '%s'\n", ((t_dir*)tmp->content)[0].d_name);
	if (dir == NULL)
		return (-1);
	ft_get_dir_content(dir, &dir_content, ((t_dir*)tmp->content)[0].d_name);
	ft_print_d_name(&dir_content);
	ft_dir_recurs(&dir_content);
		return (0);
}

t_list		*ft_get_dir_content(DIR *dir, t_list **dir_content, char *dir_path)
{
	t_list *newdir;
	t_dir *dirent;
	char	newpath[500];

	newdir = NULL;
	while ((dirent = readdir(dir)))
	{
		if(dirent->d_name[0] != '.')
		{
			ft_strcpy(newpath, dir_path);
			ft_strcat(newpath, "/");
			ft_strcat(newpath, dirent->d_name);
			ft_strcat(newpath, "\0");
			ft_new_dir(dir_content, newpath);
		}
	}
	return (*dir_content);
}

void		ft_dir_recurs(t_list **newdir)
{
	t_list	*tmp;

	tmp = *newdir;
	while (tmp)
	{
		printf("type == %d\n", ((t_dir*)tmp->content)[0].d_type == DT_DIR);
		if (((t_dir*)tmp->content)[0].d_type == DT_DIR && ((t_dir*)tmp->content)[0].d_name[2] != '.')
			ft_dir_process(tmp);
		else
			printf("nom du fichier = %s\n", ((t_dir*)tmp->content)[0].d_name);
		tmp = tmp->next;
	}
}

void		ft_get_dirlst(t_list **head, char **av, int ac)
{
	int i;

	i = 0;
	if (!av[i])
		ft_new_dir(head, ".");
	while (i < ac && av[i])
	{
		ft_new_dir(head, av[i]);
		i++;	
	}
}

t_list		*ft_new_dir(t_list **head, char *path)
{
	t_list	*newdir;
	t_dir	*dirent;
	t_stat	*stat;
	void	**data;

	if (!(data = (void**)malloc(sizeof(void*) * 2)))
		return (NULL);
	if (!(dirent = (t_dir*)malloc(sizeof(t_dir))))
		return (NULL);
	if (!(stat = (t_stat*)malloc(sizeof(t_stat))))
		return (NULL);
	data[0] = (t_dir*)dirent;
	data[1] = (t_stat*)stat;

	ft_strcpy(((t_dir*)data[0])->d_name, path);
	stat = get_data(path, ((t_dir*)data[0]), stat);
	newdir = ft_lstnew2(*data, sizeof(data));
	ft_lstadd(head, newdir);
	return (newdir);
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
		printf("dir-name = '%s'\n", ((t_dir*)tmp->content)->d_name);
		tmp = tmp->next;
	}
}
