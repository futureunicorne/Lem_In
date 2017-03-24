/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_solve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 14:15:21 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/03/24 12:05:45 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		ft_check_distance(t_last *lst, t_list *elem, int dist)
{
	int	i;
	int flag;

	i = 0;
	flag = 0;
	while (elem->link[i])
	{
		if (ft_attribute_bfs(lst, elem->link[i], dist + 1, elem->name))
			flag = 1;
		i++;
	}
	if (flag == 1)
		return (1);
	return (1);
}

int		ft_control_dbl(char *new, char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		if (ft_strcmp(new, tab[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int		ft_check_nb_ant(char *str)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	while (str[i])
	{
		if (!(str[i] >= 48 && str[i] <= 57))
			flag = 1;
		i++;
	}
	if (flag == 1)
		return (-1);
	else
		return (ft_atoi(str));
	return (0);
}

int		ft_check_link(char *line)
{
	t_ref ref;

	ft_memset(&ref, 0, sizeof(t_ref));
	while (line[ref.i])
	{
		ref.j = ref.i;
		while ((line[ref.i] >= 33 && line[ref.i] <= 44)
		|| (line[ref.i] >= 46 && line[ref.i] <= 126))
		{
			if (ref.flag == ref.res)
				ref.flag++;
			if (line[ref.i] != '\0')
				ref.i++;
		}
		if (line[ref.i] == '-')
			ref.auth++;
		ref.res = ref.flag;
		if (line[ref.i] != '\0')
			ref.i++;
	}
	if (ref.auth == 1 && ref.flag == 2)
		return (1);
	return (0);
}

int		ft_compare_salle(char **tab, int j)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (i < j)
	{
		k = i + 1;
		while (k < j)
		{
			if (ft_strcmp(tab[i], tab[k]) == 0)
				return (0);
			k++;
		}
		i++;
	}
	return (1);
}
