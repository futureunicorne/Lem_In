/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_solve2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 15:14:56 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/03/23 15:29:07 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

char	*ft_search_parent(t_last *lst, char *name)
{
	t_list *elem;

	elem = lst->fin;
	while (elem != NULL)
	{
		if (ft_strcmp(name, elem->name) == 0)
			break ;
		elem = elem->prev;
	}
	if (elem->parent != NULL)
		return (elem->parent);
	return (NULL);
}

int		ft_starter(t_last *lst)
{
	t_list	*elem;

	elem = lst->fin;
	while (elem != NULL)
	{
		if (ft_strcmp("start", elem->content) == 0)
			elem->prev->start = 1;
		elem = elem->prev;
	}
	elem = lst->fin;
	while (elem != NULL)
	{
		if (ft_strcmp("end", elem->content) == 0)
			elem->prev->end = 1;
		elem = elem->prev;
	}
	return (0);
}
