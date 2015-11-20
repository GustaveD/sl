/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosamon <jrosamon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:12:08 by jrosamon          #+#    #+#             */
/*   Updated: 2014/12/03 16:31:04 by jrosamon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char	*fill;

	fill = dest;
	while (n > 0 && *src != '\0')
	{
		*fill++ = *src++;
		--n;
	}
	while (n > 0)
	{
		*fill++ = '\0';
		--n;
	}
	return (dest);
}
