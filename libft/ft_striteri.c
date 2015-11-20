/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   striteri.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosamon <jrosamon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 19:19:33 by jrosamon          #+#    #+#             */
/*   Updated: 2014/11/09 22:31:20 by jrosamon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int len;
	int i;

	if (s && f)
	{
		len = ft_strlen(s);
		i = 0;
		while (i < len)
		{
			(*f)(i, s);
			i++;
			s++;
		}
	}
}
