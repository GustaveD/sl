/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosamon <jrosamon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:06:57 by jrosamon          #+#    #+#             */
/*   Updated: 2014/11/10 15:53:46 by jrosamon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*dt;
	char	*sc;
	size_t	n;
	size_t	dlen;

	dt = dst;
	sc = (char*)src;
	n = size;
	while ((*dt != '\0') && (n-- != 0))
		dt++;
	dlen = dt - dst;
	n = size - dlen;
	if (n == 0)
		return (dlen + strlen(sc));
	while (*sc != '\0')
	{
		if (n != 1)
		{
			*dt++ = *sc;
			n--;
		}
		sc++;
	}
	*dt = '\0';
	return (dlen + (sc - src));
}
