/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 16:18:44 by hel-hadi          #+#    #+#             */
/*   Updated: 2016/12/22 17:11:00 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_lst(t_last *list)
{
	t_list *elem;

	elem = list->debut;
	while (elem != NULL)
	{
		ft_putnbr(elem->content_size);
		elem = elem->next;
	}
}
