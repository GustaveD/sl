/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosamon <jrosamon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 17:39:45 by jrosamon          #+#    #+#             */
/*   Updated: 2015/11/26 15:21:54 by jrosamon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned const char	*ss1;
	unsigned const char	*ss2;
	int					i;

	ss1 = (unsigned const char*)s1;
	ss2 = (unsigned const char*)s2;
	i = 0;
	while (ss1[i] && ss2[i] && ss1[i] == ss2[i])
		i++;
	return (ss1[i] - ss2[i]);
}

int ft_strcmp2(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] -s2[i]);
}
