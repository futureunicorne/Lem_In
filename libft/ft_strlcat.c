/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:27:17 by hel-hadi          #+#    #+#             */
/*   Updated: 2016/11/18 11:01:59 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (dst[j] && j < size)
		j++;
	while (src[i] && (j + i + 1) < size)
	{
		dst[j + i] = src[i];
		i++;
	}
	if (j < size)
		dst[j + i] = '\0';
	return (j + ft_strlen(src));
}
