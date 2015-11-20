/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosamon <jrosamon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:20:34 by jrosamon          #+#    #+#             */
/*   Updated: 2014/11/07 16:56:31 by jrosamon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char *dt;
	char *sc;

	dt = dst;
	sc = (char*)src;
	if (dst <= src)
		return (ft_memcpy(dst, src, n));
	sc += n;
	dt += n;
	while (n--)
		*--dt = *--sc;
	return (dt);
}
