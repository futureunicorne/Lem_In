/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_elem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 16:16:40 by hel-hadi          #+#    #+#             */
/*   Updated: 2016/12/22 17:11:03 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_get_elem(t_last *list, size_t nb)
{
	t_list	*elem;
	int		stop;

	elem = list->debut;
	stop = 0;
	while (elem && !stop)
	{
		if (elem->content_size == nb)
			stop = 1;
		else
			elem = elem->next;
	}
	return (elem);
}
