/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 16:15:49 by hel-hadi          #+#    #+#             */
/*   Updated: 2016/12/22 17:11:05 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_lst(t_last *list)
{
	t_list *elem;
	t_list *tmp;

	elem = list->debut;
	while (elem != NULL)
	{
		tmp = elem->next;
		free(elem);
		elem = tmp;
	}
}
