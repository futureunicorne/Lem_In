/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 16:04:59 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/03/19 22:09:31 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	ft_check_tiret(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_record_name(char *str)
{
	int		i;
	char	*dup;

	i = 0;
	while (str[i] != ' ')
		i++;
	dup = ft_strsub(str, 0, i);
	return (dup);
}

int	ft_control_name(char *name, char *tube)
{
	int i;

	i = 0;
	while (tube[i] != '-')
		i++;
	if (ft_strncmp(name, tube, i) == 0)
		return (1);
	i++;
	if (ft_strcmp(name, tube + i) == 0)
		return (1);
	return (0);
}

char	*ft_listu(char *name, char *tube)
{
	int i;
	int auth;
	char *dup;

	i = 0;
	auth = 0;
	dup = "";
	while (tube[i] != '-')
		i++;
	if (ft_strncmp(name, tube, i) == 0)
		auth++;
	i++;
	if (ft_strcmp(name, tube + i) == 0)
		auth++;
	if (auth)
	{
		i = 0;
		while (tube[i] != '-')
			i++;
		if (ft_strncmp(name, tube, i) != 0)
			dup = ft_strndup(tube, i);
		i++;
		if (ft_strcmp(name, tube + i) != 0)
			dup = ft_strdup(tube + i);
	}
	return (dup);
}

int	ft_nb_info(t_last *lst, t_last *dup)
{
	t_list *elem;
	t_list *elem2;
	t_ref ref;

	elem = lst->fin;
	elem2 = dup->fin;
	ft_memset(&ref, 0, sizeof(t_ref));
	while (elem2 != NULL)
	{
		ref.auth = 0;
		elem = lst->fin;
		while (elem != NULL)
		{
			if (ft_check_tiret(elem->content))
			{
				if (ft_control_name(elem2->name, elem->content) == 1)
					ref.auth++;
			}
			elem = elem->prev;
		}
		elem2->nb_link = ref.auth;
		elem2 = elem2->prev;
	}
	return (0);
}

int		ft_malloc_link(t_last *dup)
{
	t_list	*elem;

	elem = dup->fin;
	while (elem != NULL)
	{
		if(!(elem->link = (char**)malloc((sizeof(char*)) * (elem->nb_link + 1))))
			return (0);
		ft_bzero(elem->link, sizeof(elem->link));
		elem = elem->prev;
	}
	return (0);
}

int	ft_control_dbl(char *new, char **tab)
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

int	ft_check_info(t_last *lst, t_last *dup)
{
	t_list *elem;
	t_list *elem2;
	t_ref ref;

	elem = lst->fin;
	elem2 = dup->fin;
	ft_memset(&ref, 0, sizeof(t_ref));
	while (elem2 != NULL)
	{
		elem = lst->fin;
		ref.i = 0;
		while (elem != NULL)
		{
			if (ft_check_tiret(elem->content))
			{
				if (ft_control_name(elem2->name, elem->content) == 1)
				{
					ref.dup = ft_listu(elem2->name, elem->content);
					if (ft_control_dbl(ref.dup, elem2->link) == 1)
						elem2->link[ref.i++] = ft_listu(elem2->name, elem->content);
					free(ref.dup);
				}
			}
			elem = elem->prev;
		}
		elem2 = elem2->prev;
	}
	return (0);
}

int	ft_starter(t_last *lst)
{
	t_list	*elem;

	elem = lst->fin;
	while (elem != NULL)
	{
		if (ft_strcmp("start", elem->content) == 0)
			elem->prev->start = 1;
		elem = elem->prev;
	}
	elem = lst->fin;
	while (elem != NULL)
	{
		if (ft_strcmp("end", elem->content) == 0)
			elem->prev->end = 1;
		elem = elem->prev;
	}
	return (0);
}

int ft_sort_list(t_last *lst, t_last *dup)
{
	t_list	*elem;
	t_list	*elem2;

	elem = lst->fin;
	while (elem != NULL)
	{
		if (ft_check_space(elem->content))
		{
			ft_add_elm_bis(dup, (char*)elem->content, ft_strlen(elem->content));
			elem2 = dup->debut;
			elem2->name = ft_record_name(elem->content);
			elem2->parent = NULL;
			if (elem->start)
				elem2->start = 1;
			if (elem->end)
				elem2->end = 1;
			elem2->passe = 0;
			elem2->distance = -1;
			if (elem->start != 1)
				elem2->start = 0;
			if (elem->end != 1)
				elem2->end = 0;
		}
		elem = elem->prev;
	}
	ft_nb_info(lst, dup);
	ft_malloc_link(dup);
	ft_check_info(lst, dup);
	ft_starter(lst);
	return (1);
}
