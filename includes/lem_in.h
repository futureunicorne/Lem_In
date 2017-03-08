/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 19:48:31 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/03/08 08:02:29 by hel-hadi         ###   ########.fr       */
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

int				ft_recup_info(t_pos *pos);

#endif
