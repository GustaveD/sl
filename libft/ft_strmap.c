/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosamon <jrosamon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 20:17:32 by jrosamon          #+#    #+#             */
/*   Updated: 2014/11/11 21:26:40 by jrosamon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
			ns[i] = (*f)(s[i]);
			i++;
		}
		return (ns);
	}
	else
		return (NULL);
}
