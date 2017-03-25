/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 16:35:40 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/03/25 10:41:12 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		ft_struc_parent(t_last *lst, t_list *end)
{
	t_list	*elem;
	t_list	*tmp;
	char	*pere;

	elem = end;
	tmp = elem;
	pere = elem->parent;
	while (elem != NULL)
	{
		if (ft_strcmp(pere, elem->name) == 0)
		{
			elem->fils = tmp->name;
			tmp = elem;
			pere = ft_search_parent(lst, elem->name);
			if (pere == NULL)
				break ;
			elem = lst->fin;
		}
		elem = elem->prev;
	}
	elem = lst->fin;
	elem->fils = tmp->name;
}

int			ft_attribute_bfs(t_last *lst, char *name, int dist, char *parent)
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

int			ft_init_start(t_last *lst)
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

t_list		*ft_bfs_bis(t_ref *ref, t_list *elem, t_last *lst)
{
	if (elem->prev == NULL)
	{
		if (ref->m_link == 0)
		{
			ft_putendl("ERROR");
			ft_putchar('\n');
			ref->flag = 1;
			return (NULL);
		}
		elem = lst->fin;
		ref->m_link = 0;
		ref->flag_d++;
	}
	return (elem);
}

t_list		*ft_bfs(t_last *lst)
{
	t_list	*elem;
	t_ref	ref;

	ft_memset(&ref, 0, sizeof(t_ref));
	ref.flag_d = ft_init_start(lst);
	elem = lst->fin;
	ref.m_link = 1;
	while (elem != NULL)
	{
		if (elem->distance == ref.flag_d)
		{
			if (ft_check_distance(lst, elem, ref.flag_d))
				ref.m_link = 1;
			if (elem->end == 1)
				break ;
		}
		elem = ft_bfs_bis(&ref, elem, lst);
		if (elem == NULL)
			break ;
		elem = elem->prev;
	}
	if (ref.flag == 1)
		return (NULL);
	ft_struc_parent(lst, elem);
	return (elem);
}
