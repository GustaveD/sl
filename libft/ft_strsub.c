/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strsub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosamon <jrosamon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 16:06:13 by jrosamon          #+#    #+#             */
/*   Updated: 2014/11/25 15:36:32 by jrosamon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*ns;
	unsigned int	i;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < len)
		return (NULL);
	ns = ft_strnew(len + 1);
	i = 0;
	if (!ns)
		return (NULL);
	while (i < len + 1)
	{
		ns[i] = s[start + i];
		i++;
	}
	ns[i - 1] = '\0';
	return (ns);
}
