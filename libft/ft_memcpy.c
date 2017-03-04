/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:03:57 by hel-hadi          #+#    #+#             */
/*   Updated: 2016/11/15 11:56:46 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*dest2;
	char	*src2;
	size_t	i;

	i = 0;
	if (n == 0)
		return (dest);
	dest2 = (char*)dest;
	src2 = (char*)src;
	while (i < n)
	{
		dest2[i] = src2[i];
		i++;
	}
	dest = dest2;
	return (dest);
}
