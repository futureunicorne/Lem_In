/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 10:52:44 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/03/12 15:48:22 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		ft_check_space(char *str)
{
	int i;
	int	auth;

	i = 0;
	auth = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			auth++;
		i++;
	}
	if (auth == 2)
		return (1);
	return (0);
}

int		ft_start_bef(t_last *lst)
{
	t_list	*elem;
	int		auth;

	elem = lst->fin;
	while (elem != NULL)
	{
		if (ft_strcmp(elem->content, "##start") == 0)
			auth = 1;
		if (ft_strcmp(elem->content, "##end") == 0)
			break ;
		elem = elem->prev;
	}
	if (auth == 1)
		return (1);
	return (0);
}

int		ft_count_dbl(t_last *lst)
{
	t_list	*elem;
	int		i;

	i = 0;
	elem = list->fin;
	while (elem != NULL)
	{
		if (ft_check_space(elem->content))
			i++;
		elem = elem->next;
	}
	return (i * 2);
}

int		ft_check_dbl(t_last *lst)
{
	t_list	*elem;
	int		*tab;
	int		size;

	i = 0;
	size =
	if (!(tab = (int *)malloc)
	elem = list->fin;
	while (elem != NULL)
	{
		if (ft_check_space(elem->content))

	}
}

int		ft_check_order(t_last *lst)
{
	t_list	*elem;
	int		auth;
	int		auth_f;

	elem = lst->fin;
	auth = 0;
	auth_f = 0;
	while (elem != NULL)
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
	if (ft_check_order(lst) == 0 || ft_check_dbl(lst) == 0)
	{
		ft_putstr_fd("ERROR PARSE", 1);
		return (0);
	}
	return (0);
}
