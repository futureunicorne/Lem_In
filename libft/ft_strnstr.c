/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 08:59:30 by hel-hadi          #+#    #+#             */
/*   Updated: 2016/11/17 20:02:30 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (ft_strlen(s2) == 0)
		return ((char*)s1);
	if (ft_strlen(s1) == 0)
		return (NULL);
	if (len == 0)
		return (NULL);
	len = len - 1;
	while (s1[i] && (i <= len))
	{
		j = 0;
		while (s1[i + j] == s2[j])
		{
			if ((i + j == len + 1) && (j + 1 != '\0'))
				return (NULL);
			j++;
			if (s2[j] == '\0')
				return ((char*)s1 + i);
		}
		i++;
	}
	return (NULL);
}
