/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 14:08:08 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/03/21 15:59:35 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		ft_malloc_link(t_last *dup)
{
	t_list	*elem;
	int		i;

	elem = dup->fin;
	while (elem != NULL)
	{
		i = 0;
		if (!(elem->link = (char**)malloc((sizeof(char*)) *
		(elem->nb_link + 1))))
			return (0);
		while (i < elem->nb_link)
		{
			elem->link[i] = NULL;
			i++;
		}
		elem = elem->prev;
	}
	return (0);
}

int		ft_check_tiret(char *str)
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

int		ft_control_name(char *name, char *tube)
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
	t_ref	ref;
	char	*dup;

	ft_memset(&ref, 0, sizeof(t_ref));
	dup = "";
	while (tube[ref.i] != '-')
		ref.i++;
	if (ft_strncmp(name, tube, ref.i) == 0)
		ref.auth++;
	ref.i++;
	if (ft_strcmp(name, tube + ref.i) == 0)
		ref.auth++;
	if (ref.auth)
	{
		ref.i = 0;
		while (tube[ref.i] != '-')
			ref.i++;
		if (ft_strncmp(name, tube, ref.i) != 0)
			dup = ft_strndup(tube, ref.i);
		ref.i++;
		if (ft_strcmp(name, tube + ref.i) != 0)
			dup = ft_strdup(tube + ref.i);
	}
	return (dup);
}
