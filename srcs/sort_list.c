/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 16:04:59 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/03/21 16:24:56 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		ft_nb_info(t_last *lst, t_last *dup)
{
	t_list	*elem;
	t_list	*elem2;
	t_ref	ref;

	elem = lst->fin;
	elem2 = dup->fin;
	ft_memset(&ref, 0, sizeof(t_ref));
	while (elem2 != NULL)
	{
		ref.auth = 0;
		elem = lst->fin;
		while (elem != NULL)
		{
			if (ft_check_tiret(elem->content))
			{
				if (ft_control_name(elem2->name, elem->content) == 1)
					ref.auth++;
			}
			elem = elem->prev;
		}
		elem2->nb_link = ref.auth;
		elem2 = elem2->prev;
	}
	return (0);
}

void	ft_check_info_bis(t_list *elem, t_list *elem2, t_ref *ref)
{
	while (elem != NULL)
	{
		if (ft_check_tiret(elem->content))
		{
			if (ft_control_name(elem2->name, elem->content) == 1)
			{
				ref->dup = ft_listu(elem2->name, elem->content);
				if (ft_control_dbl(ref->dup, elem2->link) == 1)
				{
					elem2->link[ref->i] = ft_listu(elem2->name, elem->content);
					ref->i++;
				}
				free(ref->dup);
			}
		}
		elem = elem->prev;
	}
}

int		ft_check_info(t_last *lst, t_last *dup)
{
	t_list	*elem;
	t_list	*elem2;
	t_ref	ref;

	elem = lst->fin;
	elem2 = dup->fin;
	ft_memset(&ref, 0, sizeof(t_ref));
	while (elem2 != NULL)
	{
		elem = lst->fin;
		ref.i = 0;
		ft_check_info_bis(elem, elem2, &ref);
		elem2 = elem2->prev;
	}
	return (0);
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

int		ft_sort_list(t_last *lst, t_last *dup)
{
	t_list	*elem;
	t_list	*elem2;

	elem = lst->fin;
	while (elem != NULL)
	{
		if (ft_check_space(elem->content))
		{
			ft_add_elm_bis(dup, (char*)elem->content, ft_strlen(elem->content));
			elem2 = dup->debut;
			elem2->name = ft_record_name(elem->content);
			elem2->parent = NULL;
			if (elem->start)
				elem2->start = 1;
			if (elem->end)
				elem2->end = 1;
			elem2->passe = 0;
			elem2->distance = -1;
		}
		elem = elem->prev;
	}
	ft_nb_info(lst, dup);
	ft_malloc_link(dup);
	ft_check_info(lst, dup);
	return (0);
}
