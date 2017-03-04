/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 16:24:35 by hel-hadi          #+#    #+#             */
/*   Updated: 2016/11/18 10:18:05 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list *list;
	t_list *tmp;

	list = (*alst);
	while (list != NULL)
	{
		tmp = list->next;
		del((list)->content, (list)->content_size);
		free(list);
		list = tmp;
	}
	*alst = NULL;
}
