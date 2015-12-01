/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosamon <jrosamon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:31:41 by jrosamon          #+#    #+#             */
/*   Updated: 2015/12/01 14:59:06 by jrosamon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_process(t_list *lst, char *opt)
{
	if (O_L)
	{
		ft_print_type(((t_info*)lst->content)->dirent->d_type);
	}
		ft_putstr(((t_info*)lst->content)->dirent->d_name);
		ft_putchar('\n');
		if (O_A)
			;
}

void	ft_print_type(unsigned char type)
{
	if (type == DT_UNKNOWN || type == DT_REG)
		ft_putchar('-');
	else if (type == DT_DIR)
		ft_putchar('d');
	else if (type == DT_FIFO)
		ft_putchar('p');
	else if (type == DT_CHR)
		ft_putchar('c');
	else if (type == DT_SOCK)
		ft_putchar('s');
	else if (type == DT_LNK)
		ft_putchar('l');
	else if (type == DT_BLK)
		ft_putchar('b');
	else
		ft_putchar('-');
}
