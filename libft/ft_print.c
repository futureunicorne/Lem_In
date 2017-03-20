/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 10:56:42 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/03/20 18:43:54 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print(t_last *list)
{
	t_list	*elem;
	int		i;

	elem = list->fin;
	while (elem != NULL)
	{
		i = 0;
		ft_putstr(elem->content);
		ft_putstr(elem->name);
		ft_putnbr(elem->indice);
		ft_putnbr(elem->ant);
		ft_putnbr(elem->nb_link);
		ft_putnbr(elem->distance);
		ft_putstr(elem->parent);
		while (elem->link[i])
		{
			ft_putstr(elem->link[i]);
			i++;
		}
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
