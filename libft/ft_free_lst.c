/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 16:15:49 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/03/23 10:11:25 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_lst(t_last *list)
{
	t_list *elem;
	t_list *tmp;

	elem = list->debut;
	while (elem != NULL)
	{
		tmp = elem->next;
		free(elem->content);
		free(elem);
		elem = tmp;
	}
}

void	ft_free_dup(t_last *list)
{
	t_list	*elem;
	t_list	*tmp;
	int		i;

	elem = list->debut;
	while (elem != NULL)
	{
		i = 0;
		tmp = elem->next;
		while (elem->link[i])
		{
			free(elem->link[i]);
			i++;
		}
		free(elem->link);
		free(elem->name);
		free(elem->content);
		free(elem);
		elem = tmp;
	}
}

void	ft_free_switch(t_last *lst)
{
	t_list *elem;

	elem = lst->fin;
	free (elem);
}
