/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memalloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosamon <jrosamon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 11:31:58 by jrosamon          #+#    #+#             */
/*   Updated: 2014/11/21 12:26:03 by jrosamon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void			*mem;
	unsigned int	i;
	char			*tmp;

	i = 0;
	mem = (void*)malloc(size);
	tmp = (char*)mem;
	if (mem != NULL)
	{
		while (i++ < size)
			*tmp++ = 0;
	}
	return (mem);
}
