/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosamon <jrosamon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/05 17:03:42 by jrosamon          #+#    #+#             */
/*   Updated: 2015/11/26 17:11:35 by jrosamon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <stdio.h>
# include <dirent.h>
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
# define NEED_PATH (O_L || O_BR || O_T)

typedef struct dirent	t_dir;
typedef struct stat  	t_stat;

//OPTIONS
int						ft_get_opt(char *opt, char **av, int ac);
void					ft_init_opt(char *opt, char *argv);

//DIR
t_list					*ft_new_dir(t_list **head, char *path, char *opt);
void					ft_get_dirlst(t_list **head, char **av, int ac, char *opt);
int						ft_dir_process(t_list *dirlst, char *opt);
t_list					*ft_get_dir_content(DIR *dir, t_list **dir_content, char *dir_path, char *opt);
void					ft_dir_recurs(t_list **newdir, char *opt);

//DEBUG
void					ft_print_d_name(t_list **head);

//DATA
t_stat					*get_data(char *path, t_dir *dirent, t_stat *dstat);

//LS
void					ft_ls(t_list **dirlst, char *opt);

//TOOLS
char					*ft_set_path(t_dir *dirent, char *dir_path, char *newpath);
void					ft_free_data(void *content, size_t content_size);

//PRINT
void					ft_print_process(char *name, char *opt);

//SORT
void					ft_lstaddbyalph(t_list **head, t_list *n,
										int(*f)(const char*, const char*));	
void					ft_lstaddbytime(t_list **head, t_list *n);
										
#endif
