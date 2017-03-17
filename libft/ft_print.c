/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 10:56:42 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/03/17 17:58:52 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void 	ft_print(t_last *list)
{
	t_list *elem;
	int i;

	elem = list->fin;
	while (elem != NULL)
	{
		i = 0;
		printf("content = %s |", elem->content);
		printf("nom de salle %s |", elem->name );
		printf("elem->indice = %d |", elem->indice);
		printf("ant = %d |", elem->ant);
		printf("elem->nb_link = %d\n", elem->nb_link);
		while (elem->link[i])
		{
			printf("lien = %s\n", elem->link[i]);
			i++;
		}
		elem = elem->prev;
	}
}

void 	ft_print_begin(t_last *list)
{
	t_list *elem;

	elem = list->fin;
	while (elem != NULL)
	{
		printf("%s\n", elem->content);
		elem = elem->prev;
	}

}
