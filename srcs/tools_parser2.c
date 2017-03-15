/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_parser2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 09:28:48 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/03/15 09:41:12 by hel-hadi         ###   ########.fr       */
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
	elem = lst->fin;
	while (elem != NULL)
	{
		if (ft_check_space(elem->content))
			i++;
		elem = elem->prev;
	}
	return (i);
}

int		ft_record_coor(t_list *elem, int *tab, int k)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (elem->content[i] != ' ')
		i++;
	i++;
	while (j < 1)
	{
		tab[k] = ft_atoi(elem->content + i);
		k++;
		while (elem->content[i] >= 48 && elem->content[i] <= 57)
			i++;
		tab[k] = ft_atoi(elem->content + i);
		k++;
		j++;
	}
	return (k);
}

int		ft_check_coor(int *tab, int k)
{
	int i;
	int j;
	int l;

	i = 0;
	while (i < k)
	{
		j = i;
		l = i + 2;
		while (j < k && l < k)
		{
			if (tab[j] == tab[l] && tab[j + 1] == tab[l + 1])
				return (0);
			l = l + 2;
		}
		i = i + 2;
	}
	return (1);
}