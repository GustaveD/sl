/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosamon <jrosamon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 16:34:50 by jrosamon          #+#    #+#             */
/*   Updated: 2015/05/04 18:52:43 by jrosamon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*ns;
	unsigned int	i;
	unsigned int	n;

	if (!s1 && !s2)
		return (NULL);
	if (!s1 && s2)
		return (ft_strdup(s2));
	if (s1 && !s2)
		return (ft_strdup(s1));
	i = 0;
	n = (ft_strlen(s1) + (ft_strlen(s2) + 1));
	ns = ft_strnew(n);
	if (!ns)
		return (NULL);
	while (i < n)
	{
		if (i < ft_strlen(s1))
			ns[i] = s1[i];
		else
			ns[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	return (ns);
}
