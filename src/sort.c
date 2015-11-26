/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosamon <jrosamon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:32:47 by jrosamon          #+#    #+#             */
/*   Updated: 2015/11/26 19:05:52 by jrosamon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_lstaddbyalph(t_list **head, t_list *new, int (*f)(const char *, 
			const char*))
{
	t_list	*tmp;
	t_list	*prev;

	tmp = *head;
	prev = NULL;
	while (tmp && f((((t_dir*)tmp->content)[0].d_name), ((t_dir*)new->content) [0].d_name) <= 0)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (prev)
		ft_lstadd(&prev, new);
	else
		ft_lstaddfront(head, new);
}

void		ft_lstaddbytime(t_list **head, t_list *new)
{
	t_list	*tmp;
	t_list	*prev;

	tmp = *head;
	prev = NULL;
	while (tmp)
	{
		printf("mode = %llu\t", ((t_stat*)tmp->content)[1].st_ino);
		printf("time = %ld\t", ((t_stat*)tmp->content)[1].st_ctime);
		printf("time2 = %ld\n", ((t_stat*)new->content)[1].st_ctime);
		prev = tmp;
		tmp = tmp->next;
	}
	if (prev)
		ft_lstadd(&prev, new);
	else
		ft_lstaddfront(head, new);
}
