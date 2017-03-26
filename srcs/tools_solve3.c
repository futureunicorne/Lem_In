/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_solve3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 17:17:56 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/03/26 15:39:55 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_list		*switch_tools(t_list *tmp, t_list *elem)
{
	tmp->content = elem->content;
	tmp->name = elem->name;
	tmp->start = elem->start;
	tmp->end = elem->end;
	tmp->ant = elem->ant;
	tmp->distance = elem->distance;
	tmp->nb_link = elem->nb_link;
	tmp->parent = elem->parent;
	tmp->fils = elem->fils;
	tmp->link = elem->link;
	return (tmp);
}

t_list		*switch_start(t_last *lst)
{
	t_list	*elem;
	t_list	*tmp;
	t_list	*tmp1;
	t_last	dup;

	elem = lst->fin;
	tmp1 = NULL;
	tmp = lst->fin;
	ft_init_lst(&dup);
	while (elem != NULL && elem->start != 1)
		elem = elem->prev;
	ft_add_elm_bis(&dup, (char*)"", ft_strlen(elem->content));
	tmp1 = dup.fin;
	tmp1 = switch_tools(tmp1, elem);
	elem = switch_tools(elem, tmp);
	elem = lst->fin;
	tmp1 = dup.fin;
	elem = switch_tools(elem, tmp1);
	ft_free_switch(&dup);
	return (elem);
}

char		*ft_search_fils(t_last *lst, char *name)
{
	t_list *elem;

	elem = lst->fin;
	while (elem != NULL)
	{
		if (ft_strcmp(name, elem->name) == 0)
			break ;
		elem = elem->prev;
	}
	return (elem->name);
}

int			check_link_ob(t_last *lst)
{
	t_list	*elem;

	elem = lst->fin;
	while (elem != NULL)
	{
		if (elem->start == 1)
		{
			if (!elem->link[0])
				return (0);
			break ;
		}
		elem = elem->prev;
	}
	elem = lst->fin;
	while (elem != NULL)
	{
		if (elem->end == 1)
		{
			if (!elem->link[0])
				return (0);
			break ;
		}
		elem = elem->prev;
	}
	return (1);
}

t_list		*ft_move_bis2(t_last *lst, t_list *elem, t_list *tmp, t_ref *ref)
{
	if (elem->ant)
		if (!tmp->ant || (tmp->ant && tmp->end == 1))
		{
			tmp->ant++;
			ref->flag = 1;
			tmp->nb_ant = elem->nb_ant;
			elem->nb_ant = 0;
			elem->ant = 0;
		}
	ref->pere = ft_search_parent(lst, elem->name);
	if (ref->pere != NULL)
		tmp = elem;
	return (tmp);
}
