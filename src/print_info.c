/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosamon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 15:18:10 by jrosamon          #+#    #+#             */
/*   Updated: 2015/12/07 18:10:24 by jrosamon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_print_info(char *opt, t_list *lst, char *max)
{
	(void)max;
		if (O_L)
		{
			ft_print_type(((t_info*)lst->content)->dirent->d_type);
			ft_print_right(((t_info*)lst->content)->stat->st_mode, 0);
			ft_print_xright(((t_info*)lst->content)->dirent->d_name);
			ft_print_link(((t_info*)lst->content)->stat->st_nlink, max);
			ft_print_group(((t_info*)lst->content)->stat, max);
			if (((t_info*)lst->content)->dirent->d_type == DT_CHR ||
					(((t_info*)lst->content)->dirent->d_type == DT_BLK))
				ft_print_device(((t_info*)lst->content)->stat->st_rdev, max);
			else
				ft_print_size(((t_info*)lst->content)->stat->st_size, max);
			ft_print_about(((t_info*)lst->content)->stat);
		}
		ft_putstr(((t_info*)lst->content)->dirent->d_name);
		if (O_L && ((t_info*)lst->content)->dirent->d_type)
			ft_print_lnkabout(((t_info*)lst->content)->dirent->d_name);
		ft_putchar('\n');
		if (O_A)
			;
}

void		ft_print_right(int right, int i)
{
	int		nbr;
	int		mode;

	if (i < 3)
	{
		ft_print_right(right / 8, i + 1);
		mode = right / ft_power(8, 3 - i);
		nbr = right % 8;
		ft_putchar((nbr >= 4) ? 'r' : '-');
		ft_putchar((nbr % 4 >= 2) ? 'w' : '-');
		if ((i == 2 && mode == 4) || (i == 1 && mode == 2))
			ft_putchar((nbr % 2) ? 's' : 'S');
		else if (i == 0 && mode == 1)
			ft_putchar((nbr % 2) ? 't' : 'T');
		else
			ft_putchar((nbr % 2) ? 'x' : '-');
	}
}

void		ft_print_xright(char *path)
{
	int		xattrs;
	acl_t	acl;

	xattrs = (int)listxattr(path, NULL, 1, XATTR_NOFOLLOW);
	if (xattrs > 0)
		ft_putchar('@');
	else
	{
		acl = acl_get_file(path, ACL_TYPE_EXTENDED);
		if (acl)
			ft_putchar('+');
		else
			ft_putchar(' ');
	}
}

void		ft_print_link(int nbr, char *max)
{
	ft_putchar(' ');
	if (max)
		ft_putnbr(max[0]);
	else
		ft_putnbr(nbr);
	ft_putchar(' ');
}

void		ft_print_device(int device, char *max)
{
	(void)max;
	if (max)
		ft_putnbr(MAJOR(device));
	ft_putstr(", ");
	ft_putnbr(MINOR(device));
}

void		ft_print_group(t_stat *stat, char *max)
{
	struct passwd	*usr;
	struct group	*grp;

	(void)max;
	usr = getpwuid(stat->st_uid);
	if (usr)
		ft_putstr(usr->pw_name);
//	else
//		ft_putstr(stat->st_uid);
	ft_putchar(' ');
	grp = getgrgid(stat->st_gid);
	if (grp)
		ft_putstr(grp->gr_name);
	ft_putchar(' ');
}

void		ft_print_size(int size, char *max)
{
	(void)max;
	if (max)
		ft_putnbr(size);
}

void		ft_print_about(t_stat *stat)
{
	time_t	now;
	time_t	mtime;
	time_t	diff;
	char	*mtime_str;

	now = time(NULL);
	mtime = stat->st_mtime;
	mtime_str = ctime(&mtime);
	diff = now - mtime;
	ft_putchar(' ');
	ft_putnstr(&(mtime_str[4]), 6);
	ft_putchar(' ');
	if (diff < (- 3600 * 24 * 30.5 * 6) ||
		diff > (3600 * 24 * 30.6 * 6))
	{
		ft_putchar(' ');
		ft_putnstr(&(mtime_str[20]), 4);
	}
	else
		ft_putnstr(&(mtime_str[11]), 5);
	ft_putchar(' ');
}

void		ft_print_lnkabout(char *path)
{
	int		path_size;
	char	*path_save;

	if (!(path_save = ft_strdup(path)))
		return ;
	path_size = readlink(path, path, 1024);
	if (path_size > 0)
	{
		path[path_size] = '\0';
		ft_putstr(" -> ");
		ft_putstr(path);
	}
	ft_strcpy(path, path_save);
	free(path_save);
}
