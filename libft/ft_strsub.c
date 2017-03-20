/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 17:03:09 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/03/20 17:48:31 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s1;
	size_t	i;
	int		j;

	i = (size_t)start;
	j = 0;
	if ((s1 = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	if (s)
	{
		len = len + i;
		while (i < len)
		{
			s1[j] = s[i];
			i++;
			j++;
		}
		s1[j] = '\0';
	}
	if (ft_strlen(s1) == 0)
	{
		free(s1);
		return ("\0");
	}
	return (s1);
}
