/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddafter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosamon <jrosamon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/09 17:35:45 by jrosamon          #+#    #+#             */
/*   Updated: 2015/11/20 17:31:43 by jrosamon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddafter(t_list *lst, t_list *new)
{
	if (lst != NULL && new != NULL)
	{
		new->next = lst->next;
		lst->next = new;
	}
}
