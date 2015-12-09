/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosamon <jrosamon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 10:42:27 by jrosamon          #+#    #+#             */
/*   Updated: 2015/12/09 11:26:10 by jrosamon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_set_path(t_dir *dirent, char *dir_path, char *newpath)
{
	ft_strcpy(newpath, dir_path);
	ft_strcat(newpath, "/");
	ft_strcat(newpath, dirent->d_name);
	ft_strcat(newpath, "\0");
	return (newpath);
}

void	ft_free_data(void *content, size_t content_size)
{
	void	**data;

	data = content;
	(void)content_size;
	if (data)
	{
		if ((t_dir*)data[0] != NULL)
			free((t_dir*)data[0]);
		if ((t_stat*)data[1] != NULL)
			free((t_stat*)data[0]);
		free(data);
	}
}

void	ft_free_info(void *content, size_t content_size)
{
	t_info	*info;

	info = content;
	(void)content_size;

	if (info)
	{
		if (info->dirent)
			free(info->dirent);
		if (info->stat)
			free(info->stat);
		free(info);
	}
}
