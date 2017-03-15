/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 10:55:01 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/03/15 09:33:08 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		ft_false_link(char *line)
{
	t_ref ref;

	ft_memset(&ref, 0, sizeof(t_ref));
	ref.res = -1;
	while (line[ref.i])
	{
		ref.j = ref.i;
		while (line[ref.i] >= 48 && line[ref.i] <= 57)
			ref.i++;
		if (ft_atoi(line + ref.j) >= 0)
		{
			if (ref.res == ft_atoi(line + ref.j))
				return (0);
			if (ref.res < 0)
				ref.res = ft_atoi(line + ref.j);
		}
		ref.i++;
	}
	return (1);
}

int		ft_after_link(t_last *lst)
{
	t_list *elem;

	elem = lst->fin;
	while (elem != NULL)
	{
		if (ft_check_link(elem->content) == 1)
		{
			if (ft_false_link(elem->content) == 0)
				return (0);
			if (elem->prev != NULL)
			{
				if (ft_check_space(elem->prev->content))
					return (0);
			}
		}
		elem = elem->prev;
	}
	return (1);
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
		while(k < j)
		{
			if (ft_strcmp(tab[i], tab[k]) == 0)
				return (0);
			k++;
		}
		i++;
	}
	return (1);
}

int		ft_check_salle(t_last *lst)
{
	t_list	*elem;
	int		i;
	int		j;
	int		size;
	char	**tab;
	char	*dup;

	i = 0;
	j = 0;
	size = ft_count_dbl(lst);
	if (!(tab = (char**)malloc((sizeof(char*)) * (size + 1))))
		return (0);
	elem = lst->fin;
	while (elem != NULL)
	{
		if (ft_check_space(elem->content))
		{
			i = 0;
			while (elem->content[i] != ' ')
				i++;
			dup = ft_strndup(elem->content, i);
			tab[j] = dup;
			j++;
		}
		elem = elem->prev;
	}
	if (ft_compare_salle(tab, j) == 1)
	{
		ft_free_tab(tab, j);
		free (tab);
		return (1);
	}
	return (0);
}