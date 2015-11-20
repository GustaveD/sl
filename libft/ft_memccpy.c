/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosamon <jrosamon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:29:02 by jrosamon          #+#    #+#             */
/*   Updated: 2014/11/09 17:54:30 by jrosamon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*dt;
	char	*sc;
	char	nc;

	dt = dst;
	sc = (char*)src;
	nc = c;
	while ((n-- != 0))
	{
		if (*sc == nc)
		{
			*dt++ = *sc++;
			return (dt);
		}
		*dt++ = *sc++;
	}
	return (NULL);
}
