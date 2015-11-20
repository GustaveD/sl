/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtrim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosamon <jrosamon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 11:39:00 by jrosamon          #+#    #+#             */
/*   Updated: 2014/11/28 18:20:52 by jrosamon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_isblank(int c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	else
		return (0);
}

char			*ft_strtrim(char const *s)
{
	char			*ns;
	int				d;
	int				t_s;
	unsigned int	c;

	d = 0;
	c = 0;
	t_s = 0;
	if (!s)
		return (NULL);
	ns = ft_strnew(ft_strlen(s));
	while (c < ft_strlen(s))
	{
		if (!t_s && ft_isblank(s[c]))
			c++;
		else
		{
			t_s = 1;
			ns[d++] = s[c++];
		}
	}
	while (ft_isblank (ns[--d]))
		ns[d] = '\0';
	return (ns);
}
