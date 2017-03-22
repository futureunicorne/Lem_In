/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 16:34:16 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/03/22 13:21:23 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

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

void 	ft_put_result(t_last *lst, t_list *end)
{
	t_list	*elem;
	char	*fils;
	char	*fils1;
	int		ant;

	while (tmp->ant != ant)
	{
		elem = lst->fin;
		fils = elem->fils;
		fils1 = elem->name;
		while (elem != NULL)
		{
			if ((ft_strcmp(elem->name, fils1) == 0))
			{
				ft_putchar('L');
				ft_putstr(elem->name);
				ft_putstr("->");
			}
			if ((ft_strcmp(fils, elem->name) == 0))
			{
				ft_putstr(elem->name);
				if (elem->end == 1)
					break ;
				ft_putstr("->");
				fils = ft_search_fils(lst, elem->fils);
				elem = lst->fin;
		}
		elem = elem->prev;
		}
	}
}
