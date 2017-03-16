/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 16:04:59 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/03/16 08:01:21 by hel-hadi         ###   ########.fr       */
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
	if (ft_strncmp(name, tube, (size_t)i) == 0)
		return (1);
	i++;
	if (ft_strcmp(name, tube + i) == 0)
		return (1);
	return (0);
}

int	ft_check_info(t_last *lst, t_last *dup)
{
	t_list *elem;
	t_list *elem2;

	elem = lst->fin;
	elem2 = dup->fin;
	while (elem2 != NULL)
	{
		while (elem != NULL)
		{
			if (ft_check_tiret(elem->content))
			{
				ft_control_name(elem2->name, elem->content);
			}
			elem = elem->prev;
		}
		elem2 = elem2->prev;
	}
	return (0);
}

int ft_sort_list(t_last *lst, t_last *dup)
{
	t_list	*elem;

	elem = lst->fin;
	while (elem != NULL)
	{
		if (ft_check_space(elem->content))
			ft_add_elm_bis(dup, (char*)elem->content, ft_strlen(elem->content));
		elem->name = ft_record_name(elem->content);
		elem = elem->prev;
	}
	ft_check_info(lst, dup);
	return (1);
}
