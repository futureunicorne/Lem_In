/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 18:25:42 by hel-hadi          #+#    #+#             */
/*   Updated: 2016/11/16 12:13:15 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*s3;
	const char	*s4;
	size_t		i;

	if (n == 0)
		return (0);
	s3 = s1;
	s4 = s2;
	i = 0;
	while (i < n)
	{
		if (s3[i] != s4[i])
			return (((unsigned char)s3[i] - (unsigned char)s4[i]));
		i++;
	}
	return (0);
}
