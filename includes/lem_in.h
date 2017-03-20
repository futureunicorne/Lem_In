/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 19:48:31 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/03/19 22:05:21 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct	s_pos
{
	int			nb_ant;
	int			nb_room;
	int			nb_tub;
	int			i;
	int			fd;
	char		*line;
}				t_pos;

typedef struct	s_ref
{
	int			auth;
	int			flag;
	int			i;
	int			j;
	int			res;
	char		*dup;
	char		*dup2;
}				t_ref;

int				ft_recup_info(t_pos *pos, t_last *lst);
int				ft_parse_info(t_last *lst);
void 			ft_print(t_last *list);
int				ft_check_link(char *line);
int				ft_false_link(char *line);
int				ft_after_link(t_last *lst);
int				ft_compare_salle(char **tab, int j);
int				ft_check_salle(t_last *lst);
int				ft_check_space(char *str);
int				ft_start_bef(t_last *lst);
int				ft_count_dbl(t_last *lst);
int				ft_record_coor(t_list *elem, int *tab, int k);
int				ft_check_coor(int *tab, int k);
int				ft_check_dbl(t_last *lst);
int				ft_check_dbl_enter(t_last *lst);
int				ft_check_order(t_last *lst);
int				ft_parse_info(t_last *lst);
int				ft_check_nb_ant(char *str);
int				ft_check_rule(char *line);
int				ft_record_general(char *line);
int				ft_sort_list(t_last *lst, t_last *dup);
int				ft_bfs(t_last *lst);
int				ft_starter(t_last *lst);




#endif
