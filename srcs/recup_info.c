/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 07:36:23 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/03/08 17:38:45 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

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

int		ft_check_rule(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		while ((line[i] >= 48 && line[i] <= 57)
		|| (line[i] >= 65 && line[i] <= 90) || (line[i] >= 97 && line[i] <= 122))
			i++;
		if (line[i] != ' ' || line[i] == '\0')
			return (0);
		i++;
	}

	return (1);
}

int		ft_record_general(char *line)
{
	int i;
	int auth;

	i = 0;
	auth = 0;
	if (line[0] == '#' && line[1] == '#')
	{
		if (ft_strcmp(line, "##start") == 0)
			return (2);
		if (ft_strcmp(line, "##commentaire") == 0)
			return (1);
		if ((ft_strcmp(line, "##end") == 0))
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

int		ft_recup_info(t_pos *pos)
{
	get_next_line(pos->fd, &pos->line);
	if (ft_check_nb_ant(pos->line) == -1 || ft_check_nb_ant(pos->line) == 0)
	{
		ft_putstr_fd("ERROR\n", 1);
		return (0);
	}
	else
		pos->nb_ant = ft_check_nb_ant(pos->line);
	free(pos->line);
	while (pos->line)
	{
		get_next_line(pos->fd, &pos->line);
		if (pos->line[0] == '\0')
			break;
		if (ft_record_general(pos->line) == 0)
		{
			ft_putstr_fd("ERROR\n", 1);
			return (0);
		}
		free(pos->line);
	}
	return (0);
}
