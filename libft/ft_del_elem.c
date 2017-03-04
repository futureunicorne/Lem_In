/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_elem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 16:15:01 by hel-hadi          #+#    #+#             */
/*   Updated: 2016/12/22 17:11:06 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_del_elem(t_last *list, t_list *elem)
{
	t_list	*tmp;
	t_list	*prev;
	int		stop;

	tmp = list->debut;
	stop = 0;
	prev = NULL;
	while (tmp && !stop)
	{
		if (tmp == elem)
		{
			if (prev)
				prev->next = tmp->next;
			else
				list->debut = tmp->next;
			free(elem);
			stop = 1;
		}
		else
		{
			prev = tmp;
			tmp = tmp->next;
		}
	}
}
