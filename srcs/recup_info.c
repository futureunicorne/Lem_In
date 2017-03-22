/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 07:36:23 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/03/22 19:59:59 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		ft_check_rule_bis(char *line, t_ref *ref)
{
	ref->j = ref->i;
	while ((line[ref->i] >= 48 && line[ref->i] <= 57)
	|| (line[ref->i] >= 65 && line[ref->i] <= 90)
	|| (line[ref->i] >= 97 && line[ref->i] <= 122))
	{
		if (ref->flag)
		{
			if (!(line[ref->i] >= 48 && line[ref->i] <= 57))
				return (0);
		}
		ref->i++;
	}
	return (1);
}

int		ft_check_rule(char *line)
{
	t_ref ref;

	ft_memset(&ref, 0, sizeof(t_ref));
	while (line[ref.i])
	{
		if (ft_check_rule_bis(line, &ref) == 0)
			return (0);
		if (ft_atoi(line + ref.j) >= 0)
			ref.flag++;
		if (line[ref.i] != ' ')
			break ;
		ref.auth++;
		ref.flag = 1;
		ref.i++;
	}
	if (ref.auth != 2)
	{
		if (ft_check_link(line) == 0)
			return (0);
		else
			return (1);
	}
	if (ref.auth == 2 && ref.flag == 2)
		return (1);
	return (0);
}

int		ft_record_general(char *line)
{
	if (line[0] == '#' && line[1] == '#')
	{
		if (ft_strcmp(line, "##start") == 0)
			return (1);
		if (ft_strcmp(line, "##commentaire") == 0)
			return (1);
		if ((ft_strcmp(line, "##end") == 0))
			return (1);
		if (ft_strcmp(line, "##autre commentaire") == 0)
			return (1);
		return (0);
	}
	if (line[0] == 'L' || line[0] == '#')
		return (0);
	else
	{
		if (ft_check_rule(line) == 1)
			return (1);
	}
	return (0);
}

void	ft_recup_info_bis(t_pas *pas, t_last *lst)
{
	if (ft_record_general(pas->line) == 0)
		free(pas->line);
	else
	{
		ft_add_elm_bis(lst, (char*)pas->line, ft_strlen(pas->line));
		free(pas->line);
	}
}

int		ft_recup_info(t_pas *pas, t_last *lst)
{
	t_list *elem;

	get_next_line(pas->fd, &pas->line);
	if (ft_check_nb_ant(pas->line) < 0 || ft_check_nb_ant(pas->line) == 0
	|| ft_check_nb_ant(pas->line) > 2147483647)
	{
		ft_putstr_fd("ERROR\n", 1);
		free(pas->line);
		return (0);
	}
	else
	{
		ft_add_elm_bis(lst, (char*)pas->line, ft_strlen(pas->line));
		elem = lst->fin;
		elem->ant = ft_atoi(elem->content);
	}
	free(pas->line);
	while (pas->line)
	{
		get_next_line(pas->fd, &pas->line);
		if (pas->line[0] == '\0')
		{
			free(pas->line);
			break ;
		}
		ft_recup_info_bis(pas, lst);
	}
	return (1);
}
