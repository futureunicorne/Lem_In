/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 10:52:44 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/03/13 20:58:36 by hel-hadi         ###   ########.fr       */
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

int		ft_free_tab(char **tab, int j)
{
	int i;

	i = 0;
	while (i < j)
	{
		free (tab[i]);
		i++;
	}
	return (0);
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
	i = 0;
	while (i < j)
	{
		printf("%s\n", tab[i]);
		i++;
	}
	ft_free_tab(tab, j);
	free (tab);
	return (1);
}

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
	if (ft_check_order(lst) == 0 || ft_check_dbl(lst) == 0)
	{
		ft_putstr_fd("ERROR PARSE", 1);
		return (0);
	}
	if (ft_check_salle(lst) == 0 )//|| ft_check_link(lst) == 0)
	{
		ft_putstr_fd("ERROR PARSE 2", 1);
		return (0);
	}
	return (0);
}
