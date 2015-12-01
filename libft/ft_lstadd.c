/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstadd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosamon <jrosamon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 20:56:54 by jrosamon          #+#    #+#             */
/*   Updated: 2015/11/30 10:30:06 by jrosamon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	t_list *tmp;

	tmp = *alst;
	new->next = tmp->next;
	tmp->next = new;

/*	tmp = *alst;
	new->next = tmp;
	(*alst) = new;*/
}
