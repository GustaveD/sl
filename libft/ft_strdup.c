/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosamon <jrosamon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:02:13 by jrosamon          #+#    #+#             */
/*   Updated: 2015/11/21 18:47:02 by jrosamon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *dup;

	dup = (char*)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (NULL == dup)
		return (dup);
	ft_strcpy(dup, s1);
	return (dup);
}
