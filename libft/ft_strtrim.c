/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 12:13:52 by hel-hadi          #+#    #+#             */
/*   Updated: 2016/11/16 10:16:30 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*s1;
	int		i;
	size_t	len;
	size_t	j;

	s1 = ft_strnew(1);
	i = 0;
	if (!s)
		return (NULL);
	j = ft_strlen(s) - 1;
	if (s[i])
	{
		while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		{
			if (s[i + 1] == '\0')
				return (s1);
			i++;
		}
		while (s[j] == ' ' || s[j] == '\t' || s[j] == '\n')
			j--;
	}
	len = j - i;
	return (ft_strsub(s, i, len + 1));
}
