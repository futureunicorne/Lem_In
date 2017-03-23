/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 16:34:16 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/03/23 18:52:31 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_list		*ft_move_ant_bis(t_last *lst, t_list *elem, t_list *tmp, t_ref *ref)
{
	if (elem->ant)
		if (!tmp->ant || (tmp->ant && tmp->end == 1))
		{
			tmp->ant++;
			tmp->nb_ant = elem->nb_ant;
			elem->nb_ant = 0;
			elem->ant = 0;
		}
	tmp = elem;
	ref->pere = ft_search_parent(lst, elem->name);
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

void		ft_put_result(t_last *lst, t_list *end)
{
	t_list	*elem;
	char	*pere;
	int		ant;
	int		nb_ant;
	int		flag;

	elem = lst->fin;
	ant = elem->ant;
	pere = elem->parent;
	while (end->ant != ant)
	{
		elem = end;
		pere = elem->parent;
		ft_putchar('\n');
		nb_ant = ft_move_ant(lst, end);
		flag = 0;
		elem = lst->fin;
		while (elem != NULL)
		{
			if (flag == 0)
			{
				flag = 1;
				if (end->ant)
				{
					ft_putchar('L');
					ft_putnbr(end->nb_ant);
					ft_putchar('-');
					ft_putstr(end->name);
					if (nb_ant != end->nb_ant)
						ft_putchar(' ');
				}
			}
			if (ft_strcmp(pere, elem->name) == 0)
			{
				if (elem->ant)
				{
					ft_putchar('L');
					ft_putnbr(elem->nb_ant);
					ft_putchar('-');
					ft_putstr(elem->name);
					if (nb_ant != elem->nb_ant)
						ft_putchar(' ');
				}
				pere = ft_search_parent(lst, elem->name);
				if (pere == NULL)
					break ;
				elem = lst->fin;
			}
			elem = elem->prev;
		}
	}
	ft_putchar('\n');
}
