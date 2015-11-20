/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosamon <jrosamon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:43:37 by jrosamon          #+#    #+#             */
/*   Updated: 2015/01/01 15:57:31 by jrosamon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *dst, int c, size_t n)
{
	unsigned char	*dt;
	unsigned char	*found;
	size_t			i;

	dt = (unsigned char*)dst;
	found = (unsigned char*)NULL;
	i = 0;
	while (!found && (i < n) && dt)
	{
		if (dt[i] == (unsigned char)c)
			found = &(dt[i]);
		i++;
	}
	return (found);
}
