/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 16:35:40 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/03/17 17:46:10 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		ft_starter(t_last *lst)
{
	t_list	*elem;
	int		i;
	int		auth++;

	elem = lst->fin;
	i = 0;
	while (elem->start != 1)
		elem = elem->prev;
	elem->passe = 1;
	while (elem->link[i])
	{
		if (ft_bfs(lst, elem->link[i], elem->indice) == 0)
			auth++;
		i++;
	}
}

int		ft_bfs(t_last *lst, char *name, int idc)
{
	t_list *elem;

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
	elem->parent = idc;
	return (1);
}

int		ft_solve_ant(t_last *lst)
{
	if (lst == NULL)
		lst = NULL;
	return (0);
}
