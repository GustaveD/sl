/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosamon <jrosamon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:32:47 by jrosamon          #+#    #+#             */
/*   Updated: 2015/12/01 14:00:49 by jrosamon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_lstaddbyalph(t_list **head, t_list *new, int (*f)(const char *, 
			const char*), char *opt)
{
	t_list	*tmp;
	t_list	*prev;

	tmp = *head;
	prev = NULL;
	while (tmp && ((!O_R && (f((((t_info*)tmp->content)->dirent->d_name),
				((t_info*)new->content)->dirent->d_name)) < 0) ||
				(O_R && (f((((t_info*)tmp->content)->dirent->d_name),
				 ((t_info*)new->content)->dirent->d_name)) > 0)))
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (prev)
		ft_lstadd(&prev, new);
	else
		ft_lstaddfront(head, new);
}

void		ft_lstaddbytime(t_list **head, t_list *new, char *opt)
{
	t_list	*tmp;
	t_list	*prev;

	tmp = *head;
	prev = NULL;
	while (tmp && ((!O_R &&(((t_info*)tmp->content)->stat->st_ctime >
				((t_info*)new->content)->stat->st_ctime)) ||
				((O_R &&(((t_info*)tmp->content)->stat->st_ctime <
				((t_info*)new->content)->stat->st_ctime)))))
			
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (prev)
		ft_lstadd(&prev, new);
	else
		ft_lstaddfront(head, new);
}
