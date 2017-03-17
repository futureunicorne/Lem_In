/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 15:38:37 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/03/17 07:58:00 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_check_fd(t_last *list, int fd)
{
	t_list	*tmp;

	tmp = NULL;
	if (list->taille == 0)
	{
		ft_init_lst(list);
		ft_add_elm(list, (char*)"", 0, fd);
		tmp = list->fin;
		return (tmp);
	}
	free(tmp);
	tmp = list->fin;
	while (tmp != NULL)
	{
		if (fd == tmp->repere)
			return (tmp);
		tmp = tmp->prev;
	}
	free(tmp);
	ft_add_elm(list, (char*)"", 0, fd);
	tmp = list->fin;
	while (fd != tmp->repere)
		tmp = tmp->prev;
	return (tmp);
}

int		check(char *line)
{
	int i;

	i = 0;
	if (!line)
		return (-1);
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		return (i);
	else
		return (-1);
}

void	create_line(char **line, t_list *elem)
{
	if (check(*line) != -1)
	{
		elem->content = ft_strsub(*line, check(*line) + 1,
		ft_strlen(*line) - check(*line) - 1);
		*line = ft_strsub_b(*line, 0, check(*line));
	}
	else
		elem->content = "";
}

int		get_next_line(int fd, char **line)
{
	static t_last	list;
	t_list			*elem;
	char			buf[BUFF_SIZE + 1];
	int				ret;

	if (fd < 0 || line == NULL || BUFF_SIZE <= 0)
		return (-1);
	elem = ft_check_fd(&list, fd);
	*line = ft_strdup(elem->content);
	if (ft_strlen(elem->content) != 0)
		free (elem->content);
	ret = 1;
	while (ret && check(*line) == -1)
	{
		ret = read(fd, buf, BUFF_SIZE);
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		*line = ft_strjoin_c(*line, buf);
	}
	create_line(line, elem);
	if (!ret && !**line && !elem->content[0])
	{
		free (elem);
		return (0);
	}
	else
		return (1);
	//return ((!ret && !**line && !elem->content[0]) ? 0 : 1);
}
