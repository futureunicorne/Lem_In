/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 11:19:28 by hel-hadi          #+#    #+#             */
/*   Updated: 2016/11/15 17:25:40 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char *tmp;

	tmp = ft_strnew(n);
	if (tmp)
	{
		src = ft_memcpy(tmp, src, n);
		dest = ft_memcpy(dest, tmp, n);
	}
	return (dest);
}
