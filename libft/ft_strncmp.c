/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosamon <jrosamon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 17:39:45 by jrosamon          #+#    #+#             */
/*   Updated: 2015/01/01 15:42:32 by jrosamon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int l1;
	unsigned int l2;

	if (!s1 && !s2)
		return (0);
	else if (!s1)
		return (-1);
	else if (!s2)
		return (1);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	if (n > l1)
		n = l1 + 1;
	if (n > l2)
		n = l2 + 1;
	return (ft_memcmp(s1, s2, n));
}
