/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosamon <jrosamon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 21:11:56 by jrosamon          #+#    #+#             */
/*   Updated: 2015/11/26 15:23:40 by jrosamon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*head;
	t_list	*nlst;

	if (!lst && !f)
		return (NULL);
	tmp = f(lst);
	nlst = ft_lstnew(tmp->content, tmp->content_size);
	if (!nlst)
		return (NULL);
	head = nlst;
	while (lst)
	{
		tmp = (*f)(lst->next);
		nlst = ft_lstnew(tmp->content, tmp->content_size);
		if (!nlst->next)
		{
			ft_lstdel(&head, &ft_bzero);
			return (NULL);
		}
		lst = lst->next;
	}
	return (head);
}
