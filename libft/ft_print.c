/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 10:56:42 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/03/23 14:52:46 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print(t_last *list)
{
	t_list	*elem;

	elem = list->fin;
	while (elem != NULL)
	{
		elem = elem->prev;
	}
}

void	ft_print_begin(t_last *list)
{
	t_list *elem;

	elem = list->fin;
	while (elem != NULL)
	{
		ft_putstr(elem->content);
		ft_putchar('\n');
		elem = elem->prev;
	}
}
