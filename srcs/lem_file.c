/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 16:34:16 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/03/23 10:17:59 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_list	*switch_start(t_last *lst)
{
	t_list	*elem;
	t_list	*tmp;
	t_list	*tmp1;
	t_last	dup;

	elem = lst->fin;
	tmp1 = NULL;
	tmp = lst->fin;
	ft_init_lst(&dup);
	while (elem != NULL)
	{
		if (elem->start == 1)
		{
			ft_add_elm_bis(&dup, (char*)"", ft_strlen(elem->content));
			tmp1 = dup.fin;
			tmp1->content = elem->content;
			tmp1->name = elem->name;
			tmp1->start = elem->start;
			tmp1->ant = elem->ant;
			tmp1->distance = elem->distance;
			tmp1->nb_link = elem->nb_link;
			tmp1->parent = elem->parent;
			tmp1->fils = elem->fils;
			tmp1->link = elem->link;

			elem->content = tmp->content;
			elem->name = tmp->name;
			elem->start = tmp->start;
			elem->ant = tmp->ant;
			elem->distance = tmp->distance;
			elem->nb_link = tmp->nb_link;
			elem->parent = tmp->parent;
			elem->fils = tmp->fils;
			elem->link = tmp->link;
			break ;
		}
		elem = elem->prev;
	}
	elem = lst->fin;
	tmp1 = dup.fin;
	elem->content = tmp1->content;
	elem->name = tmp1->name;
	elem->start = tmp1->start;
	elem->ant = tmp1->ant;
	elem->distance = tmp1->distance;
	elem->nb_link = tmp1->nb_link;
	elem->parent = tmp1->parent;
	elem->fils = tmp1->fils;
	elem->link = tmp1->link;
	ft_free_switch(&dup);
	return (elem);
}

char	*ft_search_fils(t_last *lst, char *name)
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

int 	ft_move_ant(t_last *lst, t_list *end)
{
	t_list	*elem;
	t_list	*tmp;
	char	*pere;
	char	*start;

	elem = lst->fin;
	start = elem->name;
	elem = end;
	tmp = elem;
	pere = elem->parent;
	while (elem != NULL)
	{
		if (ft_strcmp(pere, elem->name) == 0)
		{
			if (elem->ant)
			{
				if (!tmp->ant || (tmp->ant && tmp->end == 1))
				{
					tmp->ant++;
					tmp->nb_ant = elem->nb_ant;
					elem->nb_ant = 0;
					elem->ant = 0;
				}
			}
			tmp = elem;
			pere = ft_search_parent(lst, elem->name);
			if (pere == start)
			{
				elem = lst->fin;
				if ((elem->ant && (!tmp->ant)) || (elem->ant && (tmp->ant && tmp->end == 1)))
				{
					tmp->ant = 1;
					elem->nb_ant++;
					tmp->nb_ant = elem->nb_ant;
					elem->ant--;
				}
				break ;
			}
			elem = lst->fin;
		}
		elem = elem->prev;
	}

	return (elem->nb_ant);
}

void 	ft_put_result(t_last *lst, t_list *end)
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
		nb_ant = ft_move_ant(lst, end);
		ft_putchar('\n');
		flag = 0;
		while (elem != NULL)
		{
			if (flag == 0)
			{
				flag = 1;
				if (elem->ant)
				{
					ft_putchar('L');
					ft_putnbr(elem->nb_ant);
					ft_putchar('-');
					ft_putstr(elem->name);
					if (nb_ant != elem->nb_ant)
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
