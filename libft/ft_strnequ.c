/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnequ.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosamon <jrosamon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 15:52:35 by jrosamon          #+#    #+#             */
/*   Updated: 2014/11/09 23:23:07 by jrosamon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int eq;

	if (!s1 || !s2)
		return (0);
	eq = (ft_strncmp(s1, s2, n) == 0 ? 1 : 0);
	return (eq);
}
