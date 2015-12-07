/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosamon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 12:34:18 by jrosamon          #+#    #+#             */
/*   Updated: 2015/12/07 15:53:24 by jrosamon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	get_max(t_list *lst, char *buff)
{
	int			lnk;
	uid_t		uid;
	gid_t		gid;
	t_stat		*stat;

	lnk	= 0;
	uid = 0;
	gid	= 0;
	ft_bzero(buff, 5);
	while (lst)
	{
		stat = ((t_info*)lst->content)->stat;
		lnk = (stat->st_nlink > lnk) ? stat->st_nlink : lnk;
		get_uid_gid(buff, stat, &uid, &gid);
		get_max_size(buff, ((t_info*)lst->content)->dirent, stat);
		lst = lst->next;
	}
	buff[0] = (char)ft_nbrlen(lnk);
}

void		get_uid_gid(char *buf, t_stat *stat, uid_t *uid, gid_t *gid)
{
	int		size;
	struct passwd	*usr;
	struct	group	*grp;

	usr = NULL;
	if (stat->st_uid != *uid)
	{
		usr = getpwuid(stat->st_uid);
		if (usr && (size = ft_strlen(usr->pw_name)) && size > buf[1])
		{
			buf[1] = size;
			*uid = stat->st_uid;
		}
	}
	if (usr && buf[1] < 4)
		buf[1] = 4;
	if (stat->st_gid != *gid)
	{
		grp	= getgrgid(stat->st_gid);
		if (grp && (size = ft_strlen(grp->gr_name)) && size > buf[2])
		{
			buf[2] = size;
			*gid = stat->st_gid;
		}
	}
}

void		get_max_size(char *buf, t_dir *dir, t_stat *stat)
{
	int		len;

	if ((len = ft_nbrlen(stat->st_size)) > buf[3])
		buf[3] = len;
	if (dir->d_type == DT_CHR || dir->d_type == DT_BLK)
	{
		if ((len = ft_nbrlen(MINOR(stat->st_rdev))) > buf[4])
			buf[4] = len;
		if ((len = ft_nbrlen(MAJOR(stat->st_rdev)) + 2 + buf[4] + 1) > buf[3])
			buf[3] = len;
	}
}

