/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strmapi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosamon <jrosamon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 20:46:03 by jrosamon          #+#    #+#             */
/*   Updated: 2014/11/10 20:28:08 by jrosamon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ns;
	int		len;
	int		i;

	if (s == NULL)
		return (NULL);
	if (f == NULL)
		return (NULL);
	len = ft_strlen(s);
	ns = ft_strnew(len);
	i = 0;
	if (ns)
	{
		while (i < len)
		{
			ns[i] = (*f)(i, s[i]);
			i++;
		}
		return (ns);
	}
	else
		return (NULL);
}
