/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 16:35:40 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/03/20 19:19:36 by hel-hadi         ###   ########.fr       */
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

void	ft_print_parent(t_last *lst, t_list *end)
{
	t_list	*elem;
	char	*pere;

	elem = end;
	pere = elem->parent;
	ft_putstr(elem->name);
	while (elem != NULL)
	{
		if (ft_strcmp(pere, elem->name) == 0)
		{
			ft_putstr("->");
			ft_putstr(elem->name);
			pere = ft_search_parent(lst, elem->name);
			if (pere == NULL)
				break ;
			elem = lst->fin;
		}
		elem = elem->prev;
	}
	elem = lst->fin;
	ft_putstr("->");
	ft_putstr(elem->name);
}

int		ft_attribute_bfs(t_last *lst, char *name, int dist, char *parent)
{
	t_list	*elem;

	elem = lst->fin;
	while (elem != NULL)
	{
		if (ft_strcmp(name, elem->name) == 0)
			break ;
		elem = elem->prev;
	}
	if (elem->passe == 1)
		return (0);
	elem->passe = 1;
	elem->distance = dist;
	elem->parent = parent;
	return (1);
}

int		ft_init_start(t_last *lst)
{
	t_list *elem;

	elem = lst->fin;
	while (elem != NULL && elem->start != 1)
		elem = elem->prev;
	elem->distance = 0;
	elem->parent = NULL;
	elem->passe = 1;
	return (elem->distance);
}

int		ft_bfs(t_last *lst)
{
	t_list	*elem;
	int		flag_d;

	flag_d = ft_init_start(lst);
	elem = lst->fin;
	while (elem != NULL)
	{
		if (elem->distance == flag_d)
		{
			ft_check_distance(lst, elem, flag_d);
			if (elem->end == 1)
				break ;
		}
		if (elem->prev == NULL)
		{
			elem = lst->fin;
			flag_d++;
		}
		elem = elem->prev;
	}
	ft_print_parent(lst, elem);
	return (0);
}
