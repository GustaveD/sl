/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosamon <jrosamon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:39:20 by jrosamon          #+#    #+#             */
/*   Updated: 2015/01/01 15:42:34 by jrosamon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	const char	*ss1;
	const char	*ss2;
	int			len;

	ss1 = (const char*)s1;
	ss2 = (const char*)s2;
	len = ft_strlen(s2);
	if (len == 0)
		return ((char*)ss1);
	while (*ss1 && ss2)
	{
		if (ft_strncmp(ss1, ss2, len) == 0)
			return ((char*)ss1);
		ss1++;
	}
	return (NULL);
}
