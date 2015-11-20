/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosamon <jrosamon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/09 21:53:35 by jrosamon          #+#    #+#             */
/*   Updated: 2015/08/09 22:43:24 by jrosamon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(const void *src, size_t size)
{
	size_t	i;
	void	*cpy;
	const char *src_char;
	char		*cpy_char;

	i = 0;
	cpy = malloc(size);
	src_char = src;
	cpy_char = cpy;
	if (cpy != NULL)
	{
		while (i < size)
		{
			cpy_char[i] = src_char[i];
			i++;
		}
		return (cpy);
	}
	else
		return (NULL);
}
