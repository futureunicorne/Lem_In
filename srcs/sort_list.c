/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 16:04:59 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/03/15 18:32:05 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int ft_sort_list(t_last *lst, t_last *dup)
{
	t_list *elem;

	elem = lst->fin;
	ft_begin()
	while (elem != NULL)
	{
		if (ft_check_space(elem->content))
			ft_add_elm_bis(dup, (char*)elem->content, ft_strlen(elem->content));
		elem = elem->prev;
	}
	return (1);
}
