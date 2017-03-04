/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 08:38:28 by hel-hadi          #+#    #+#             */
/*   Updated: 2016/11/18 10:36:01 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*dest1;
	unsigned char	*src1;
	size_t			i;

	dest1 = (unsigned char*)dest;
	src1 = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		dest1[i] = src1[i];
		if (src1[i] == (unsigned char)c)
		{
			return (dest1 + i + 1);
		}
		i++;
	}
	return (NULL);
}
