/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 10:52:44 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/03/15 09:41:26 by hel-hadi         ###   ########.fr       */
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
		if (ft_check_space(elem->content))
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

int		ft_check_order(t_last *lst)
{
	t_list	*elem;
	int		auth;
	int		auth_f;

	elem = lst->fin;
	auth = 0;
	auth_f = 0;
	while(elem != NULL)
	{
		if (ft_strcmp(elem->content, "##start") == 0 && elem->prev)
		{
			if (ft_check_space(elem->prev->content))
				auth = 1;
		}
		if (ft_strcmp(elem->content, "##end") == 0 && elem->prev)
		{
			if (ft_check_space(elem->prev->content))
				auth_f = 1;
		}
		elem = elem->prev;
	}
	if (auth == 1 && auth_f == 1 && ft_start_bef(lst))
		return (1);
	return (0);
}

int		ft_parse_info(t_last *lst)
{
	if (ft_check_order(lst) == 0 || ft_check_dbl(lst) == 0
	|| ft_check_dbl_enter(lst) == 0)
	{
		ft_putstr_fd("ERROR PARSE", 1);
		return (0);
	}
	if (ft_check_salle(lst) == 0 || ft_after_link(lst) == 0)
	{
		ft_putstr_fd("ERROR PARSE 2", 1);
		return (0);
	}
	return (0);
}
