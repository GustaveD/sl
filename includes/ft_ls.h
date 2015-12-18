/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosamon <jrosamon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/05 17:03:42 by jrosamon          #+#    #+#             */
/*   Updated: 2015/12/18 17:09:10 by jrosamon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <stdio.h>
# include <dirent.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/xattr.h>
# include <sys/acl.h>
# include <uuid/uuid.h>
# include <sys/errno.h>
# include <unistd.h>

# define IS_OPT (opt[0])
# define O_L (opt[1])
# define O_BR (opt[2])
# define O_A (opt[3])
# define O_R (opt[4])
# define O_T (opt[5])
# define O_1 (opt[6])
# define O_END (opt[7])
# define NEED_PATH (O_L || O_BR || O_T)

# define MINOR(x) ((x) & 0xffffff)
# define MAJOR(x) (((x) >> 24) & 0xff)

typedef struct dirent	t_dir;
typedef struct stat  	t_stat;

typedef struct 			s_info
{
	t_dir				*dirent;
	t_stat				*stat;
}						t_info;

//OPTIONS
int						ft_get_opt(char *opt, char **av, int ac);
void					ft_init_opt(char *opt, char *argv);

//DIR
t_list					*ft_new_dir(t_list **head, char *path, char *opt);
t_list					*ft_new_dir2(t_list **head, char *path, char *opt);
void					ft_get_dirlst(t_list **head, char **av, int ac, char *opt);
int						ft_dir_process(t_list *dirlst, char *opt);
t_list					*ft_get_dir_content(DIR *dir, t_list **dir_content, char *dir_path, char *opt);
void					ft_dir_recurs(t_list **newdir, char *opt);

//INFO
t_info					*ft_new_info(char *path);

//DEBUG
void					ft_print_d_name(t_list **head);

//DATA
t_stat					*get_data(char *path, t_dir *dirent, t_stat *dstat);

//LS
void					ft_ls(t_list **dirlst, char *opt);

//TOOLS
char					*ft_set_path(t_dir *dirent, char *dir_path, char *newpath);
void					ft_free_data(void *content, size_t content_size);
void					ft_free_info(void *content, size_t content_size);
int						ft_is_hidden(char *s);

//PRINT
void					ft_print_process(t_list **lst, char *opt);
void					ft_print_type(unsigned char type);
void					ft_print_right(int right, int i);
void					ft_print_info(char *opt, t_list *lst, char *max);
void					ft_print_dir_name(char *str);


//SORT
void					ft_lstaddbyalph(t_list **head, t_list *n,
										int(*f)(const char*, const char*), char *opt);
void					ft_lstaddbytime(t_list **head, t_list *n, char *opt);
void					ft_lstaddbyalph_r(t_list **head, t_list *n,
										int(*f)(const char*, const char*));
void					ft_lstaddbytime_r(t_list **head, t_list *n);
void					ft_reverslst(t_list **head);

//OPT_L
void					get_max(t_list *lst, char *max);
void					get_uid_gid(char *buf, t_stat *stat, uid_t *uid, gid_t *gid);
void					get_max_size(char *buf, t_dir *dir, t_stat *stat);
void					ft_print_totaldir(t_list *lst);
void					ft_print_xright(char *fpath);
void					ft_print_link(int nbr, char *max);
void					ft_print_group(t_stat *stat, char *max);
void					ft_print_size(int size, char *max);
void					ft_print_device(int device, char *max);
void					ft_print_about(t_stat *stat);
void					ft_print_lnkabout(char *path);
void					ft_print_name(t_info* info, char *opt);
void					ft_print_name_file(char *name);

//ERROR
void					ft_error(char *s);
#endif
