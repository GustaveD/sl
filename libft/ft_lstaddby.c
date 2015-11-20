/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddby.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosamon <jrosamon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/06 18:40:57 by jrosamon          #+#    #+#             */
/*   Updated: 2015/11/20 17:30:27 by jrosamon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddby(t_list **alst, t_list *new,
					int (*f)(const void *, const void *, size_t, size_t))
{
	t_list		*view;
	t_list		*view_prev;

	if (alst != NULL && new != NULL && f != NULL)
	{
		view = *alst;
		view_prev = NULL;
		while (view != NULL && (*f) (new->content, view->content,
					new->content_size, view->content_size <= 0))
		{
			view_prev = view;
			view = view->next;
		}
		if (view_prev != NULL)
			ft_lstaddafter(view_prev, new);
		else
			ft_lstaddfront(alst, new);
	}
}
