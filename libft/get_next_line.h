/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 15:45:05 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/03/26 11:15:50 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 18

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft.h"

char			*check_ret(char *str, int ret);
char			*cut_text(char *str);
int				get_next_line(const int fd, char **line);

#endif
