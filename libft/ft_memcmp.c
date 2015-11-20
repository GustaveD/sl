/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosamon <jrosamon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 17:45:02 by jrosamon          #+#    #+#             */
/*   Updated: 2014/11/09 21:54:19 by jrosamon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char *ss1;
	unsigned const char *ss2;
	size_t				i;

	if (n < 1)
		i = -1;
	else
		i = 0;
	ss1 = (unsigned const char*)s1;
	ss2 = (unsigned const char*)s2;
	while (ss1[i] && ss2[i] && ss1[i] == ss2[i] && i < (n - 1))
		i++;
	return (ss1[i] - ss2[i]);
}
