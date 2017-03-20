/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 10:55:01 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/03/20 16:41:05 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		ft_false_link_bis(t_ref *ref)
{
	if (ft_strcmp(ref->dup, ref->dup2) == 0)
	{
		free(ref->dup);
		free(ref->dup2);
		return (0);
	}
	free(ref->dup);
	free(ref->dup2);
	return (1);
}

int		ft_false_link(char *line)
{
	t_ref ref;

	ft_memset(&ref, 0, sizeof(t_ref));
	while (line[ref.i])
	{
		ref.j = ref.i;
		while ((line[ref.i] >= 48 && line[ref.i] <= 57)
		|| (line[ref.i] >= 65 && line[ref.i] <= 90)
		|| (line[ref.i] >= 97 && line[ref.i] <= 122))
		{
			ref.i++;
		}
		if (!ref.dup)
			ref.dup = ft_strsub(line, ref.j, ref.i);
		else
			ref.dup2 = ft_strsub(line, ref.j, ref.i - 1);
		if (line[ref.i] == '-')
			ref.auth++;
		ref.res = ref.flag;
		if (line[ref.i] != '\0')
			ref.i++;
	}
	if (ft_false_link_bis(&ref) == 0)
		return (0);
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

int		ft_check_salle_bis(t_ref *ref, char **tab)
{
	if (ft_compare_salle(tab, ref->j) == 1)
	{
		ft_free_tab(tab, ref->j);
		free(tab);
		return (1);
	}
	return (0);
}

int		ft_check_salle(t_last *lst)
{
	t_list	*elem;
	char	**tab;
	t_ref	ref;

	ft_memset(&ref, 0, sizeof(t_ref));
	ref.size = ft_count_dbl(lst);
	if (!(tab = (char**)malloc((sizeof(char*)) * (ref.size + 1))))
		return (0);
	elem = lst->fin;
	while (elem != NULL)
	{
		if (ft_check_space(elem->content))
		{
			ref.i = 0;
			while (elem->content[ref.i] != ' ')
				ref.i++;
			ref.dup = ft_strndup(elem->content, ref.i);
			tab[ref.j] = ref.dup;
			ref.j++;
		}
		elem = elem->prev;
	}
	if (ft_check_salle_bis(&ref, tab) == 1)
		return (1);
	return (0);
}
