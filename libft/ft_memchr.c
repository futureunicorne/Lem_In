/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 08:50:38 by hel-hadi          #+#    #+#             */
/*   Updated: 2016/11/16 12:04:11 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s1;
	unsigned char	d;
	size_t			i;

	s1 = (unsigned char*)s;
	d = (char)c;
	i = 0;
	while (i < n)
	{
		if (s1[i] == d)
			return (s1 + i);
		i++;
	}
	return (NULL);
}
