/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlnby.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosamon <jrosamon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/06 18:31:00 by jrosamon          #+#    #+#             */
/*   Updated: 2015/08/09 18:22:54 by jrosamon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlnby(t_list **alst, void *data, size_t csize,
						int (*f)(const void *, const void *, size_t, size_t))
{
		t_list		*new;

		if (alst != NULL && f != NULL)
		{
			new = ft_lstnew2(data, csize);
			if (new != NULL)
				ft_lstaddby(alst, new, f);
			return (new);
		}
		return (NULL);
}
