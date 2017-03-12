/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 19:48:31 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/03/11 19:30:14 by hel-hadi         ###   ########.fr       */
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
}				t_ref;

int				ft_recup_info(t_pos *pos);

#endif
