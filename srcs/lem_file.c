/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 16:34:16 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/03/25 16:04:17 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_list		*ft_move_ant_bis(t_last *lst, t_list *elem, t_list *tmp, t_ref *ref)
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
	if (ref->pere == NULL)
	{
		if (ref->flag == 0)
			tmp->ant++;
		elem->nb_ant++;
		tmp->nb_ant = elem->nb_ant;
		ref->flag = 1;
		return (NULL);
	}
	if (ref->pere == ref->start)
	{
		elem = lst->fin;
		if ((elem->ant &&
		(!tmp->ant)) || (elem->ant && (tmp->ant && tmp->end == 1)))
		{
			tmp->ant = 1;
			elem->nb_ant++;
			tmp->nb_ant = elem->nb_ant;
			elem->ant--;
		}
		return (NULL);
	}
	return (tmp);
}

int			ft_move_ant(t_last *lst, t_list *end)
{
	t_list	*elem;
	t_list	*tmp;
	t_ref	ref;

	ft_memset(&ref, 0, sizeof(t_ref));
	elem = lst->fin;
	ref.start = elem->name;
	elem = end;
	tmp = elem;
	ref.pere = elem->parent;
	elem = lst->fin;
	while (elem != NULL)
	{
		if (ft_strcmp(ref.pere, elem->name) == 0)
		{
			tmp = ft_move_ant_bis(lst, elem, tmp, &ref);
			if (tmp == NULL)
				break ;
			elem = lst->fin;
		}
		elem = elem->prev;
	}
	return (elem->nb_ant);
}

void		ft_put_result_bis(t_ref *ref, t_list *end)
{
	if (ref->flag == 0)
	{
		ref->flag = 1;
		if (end->ant)
		{
			ft_putchar('L');
			ft_putnbr(end->nb_ant);
			ft_putchar('-');
			ft_putstr(end->name);
			if (ref->nb_ant != end->nb_ant)
				ft_putchar(' ');
		}
	}
}

t_list		*ft_put_result_bis2(t_last *lst, t_ref *ref, t_list *elem)
{
	if (ft_strcmp(ref->pere, elem->name) == 0)
	{
		if (elem->ant)
		{
			ft_putchar('L');
			ft_putnbr(elem->nb_ant);
			ft_putchar('-');
			ft_putstr(elem->name);
			if (ref->nb_ant != elem->nb_ant)
				ft_putchar(' ');
		}
		ref->pere = ft_search_parent(lst, elem->name);
		if (ref->pere == NULL)
			return (NULL);
		elem = lst->fin;
		return (elem);
	}
	return (elem);
}

void		ft_put_result(t_last *lst, t_list *end)
{
	t_list	*elem;
	t_ref	ref;

	ft_memset(&ref, 0, sizeof(t_ref));
	elem = lst->fin;
	ref.ant = elem->ant;
	ref.pere = elem->parent;
	while (end->ant != ref.ant)
	{
		elem = end;
		ref.pere = elem->parent;
		ft_putchar('\n');
		ref.nb_ant = ft_move_ant(lst, end);
		ref.flag = 0;
		elem = lst->fin;
		while (elem != NULL)
		{
			ft_put_result_bis(&ref, end);
			elem = ft_put_result_bis2(lst, &ref, elem);
			if (elem == NULL)
				break ;
			elem = elem->prev;
		}
	}
	ft_putchar('\n');
}
