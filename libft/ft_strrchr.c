/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosamon <jrosamon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 19:07:23 by jrosamon          #+#    #+#             */
/*   Updated: 2015/01/01 15:49:21 by jrosamon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*found;

	i = 0;
	found = 0;
	while (i == 0 || (i > 0 && str[i - 1] != '\0'))
	{
		if (str[i] == (char)c)
			found = (char*)(&str[i]);
		i++;
	}
	return (found);
}
