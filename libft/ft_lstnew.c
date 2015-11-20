/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstnew.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosamon <jrosamon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 20:25:54 by jrosamon          #+#    #+#             */
/*   Updated: 2015/11/20 17:08:27 by jrosamon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(const void *content, size_t content_size)
{
	t_list	*out;
	void	*data;

	out = (t_list *)malloc(sizeof(t_list));
	if (out == NULL)
		return (NULL);
	out->content_size = (content != NULL) ? content_size : 0;
	data = ft_memalloc(out->content_size);
	data = ft_memcpy(data, content, out->content_size);
	out->content = data;
	out->next = NULL;
	return (out);
}

t_list	*ft_lstnew2(void *data, size_t size)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (lst != NULL)
	{
		if (data != NULL)
			lst->content_size = size;
		else
			lst->content_size = 0;
		lst->content = data;
		lst->next = NULL;
	}
	return (lst);
}
