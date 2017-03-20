/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 16:35:40 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/03/20 09:01:02 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_list	*ft_search(t_last *lst, char *name)
{
	t_list *elem;

	elem = lst->fin;
	while (elem != NULL)
	{
		if (ft_strcmp(name, elem->name) == 0)
			break;
		elem = elem->prev;
	}
	return (elem);
}

void	ft_print_parent(t_last *lst, t_list *end)
{
	t_list	*elem;
	t_list	*elem2;
	char	*pere;

	elem = end;
	pere = elem->parent;
	printf("%s\n", elem->name);
	while (elem->start != 1)
	{
		if (ft_strcmp(pere, elem->parent) == 0)
		{
			elem2 = ft_search(lst, elem->parent);
			pere = elem2->name;
			elem = lst->fin;
			printf("%s\n",elem->name);
		}
		elem = elem->prev;
	}
	if (elem->start == 1)
		printf("%s\n", elem->name);
}


int		ft_attribute_bfs(t_last *lst, char *name, int dist)
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
	return (1);
}

int		ft_check_distance(t_last *lst, t_list *elem, int dist)
{
	int	i;

	i = 0;
	while (elem->link[i])
	{
		ft_attribute_bfs(lst, elem->link[i], dist);
		i++;
	}
	return (0);
}

int		ft_bfs(t_last *lst)
{
	t_list	*elem;
	int		flag_d;

	elem = lst->fin;
	while (elem != NULL && elem->start != 1)
		elem = elem->prev;
	elem->distance = 0;
	elem->parent = NULL;
	elem->passe = 0;
	while (elem != NULL)
	{
		if (elem->distance == flag_d)
		{
			ft_check_distance(lst, elem, flag_d);
			if (elem->end == 1)
			{
				printf("marche\n");
				break ;
			}
		}
		if (elem->prev == NULL)
		{
			//elem = lst->fin;
			flag_d++;
		}
		elem = elem->prev;
	}
	return (0);
}
