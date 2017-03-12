/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 10:56:42 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/03/12 10:57:55 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void 	ft_print(t_last *list)
{
	t_list *elem;

	elem = list->debut;
	while (elem != NULL)
	{
		printf("content = %s\n", elem->content);
		printf("strlen  = %zu\n", ft_strlen(elem->content));
		printf("taille  = %zu\n", list->taille);
		elem = elem->next;
	}
}
