/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 10:52:44 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/03/26 12:18:04 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		ft_check_dbl(t_last *lst)
{
	t_list	*elem;
	int		*tab;
	int		size;
	int		k;

	k = 0;
	size = ft_count_dbl(lst) * 2;
	if (!(tab = (int *)malloc((sizeof(int)) * (size + 1))))
		return (0);
	elem = lst->fin;
	while (elem != NULL)
	{
		if (ft_check_space(elem->content) && elem->content[0] != '#')
			k = ft_record_coor(elem, tab, k);
		elem = elem->prev;
	}
	if (ft_check_coor(tab, k) == 1)
	{
		free(tab);
		return (1);
	}
	free(tab);
	return (0);
}

int		ft_check_dbl_enter(t_last *lst)
{
	t_list	*elem;
	int		flag;
	int		auth;

	elem = lst->fin;
	flag = 0;
	auth = 0;
	while (elem != NULL)
	{
		if (ft_strcmp(elem->content, "##start") == 0)
			flag++;
		if (ft_strcmp(elem->content, "##end") == 0)
			auth++;
		elem = elem->prev;
	}
	if (flag == 1 && auth == 1)
		return (1);
	return (0);
}

void	ft_check_order_bis(t_list *elem, t_pas *pas)
{
	if (ft_strcmp(elem->content, "##start") == 0 && elem->prev)
	{
		if (ft_check_space(elem->prev->content))
		{
			elem->prev->start = 1;
			pas->auth = 1;
		}
	}
	if (ft_strcmp(elem->content, "##end") == 0 && elem->prev)
	{
		if (ft_check_space(elem->prev->content))
		{
			elem->prev->end = 1;
			pas->auth_f = 1;
		}
	}
}

int		ft_check_order(t_last *lst)
{
	t_list	*elem;
	t_pas	pas;

	elem = lst->fin;
	ft_memset(&pas, 0, sizeof(t_pas));
	while (elem != NULL)
	{
		ft_check_order_bis(elem, &pas);
		elem = elem->prev;
	}
	if (pas.auth == 1 && pas.auth_f == 1)
		return (1);
	return (0);
}

int		ft_parse_info(t_last *lst)
{
	if (ft_check_order(lst) == 0 || ft_check_dbl(lst) == 0
	|| ft_check_dbl_enter(lst) == 0)
	{
		ft_putendl("ERROR");
		return (0);
	}
	if (ft_check_salle(lst) == 0 || ft_after_link(lst) == 0)
	{
		printf("salle %d\n", ft_check_salle(lst));
		printf("link %d\n", ft_after_link(lst));
		ft_putendl("ERROR");
		return (0);
	}
	return (1);
}
