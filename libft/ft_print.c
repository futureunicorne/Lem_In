/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 10:56:42 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/03/23 00:53:04 by hel-hadi         ###   ########.fr       */
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
		printf("content =  %s |", elem->content);
		printf("name =  %s |", elem->name);
		printf("indice = %d |", elem->indice);
		printf("ant = %d | ", elem->ant);
		printf("nb_link =  %d |", elem->nb_link);
		printf("distance = %d |", elem->distance);
		printf("parent = %s \n", elem->parent);
		printf("fils  = %s \n", elem->fils);
		printf("start = %d |", elem->start);

		while (elem->link[i])
		{
			printf(" link = %s\n", elem->link[i]);
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
