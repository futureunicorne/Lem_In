/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 15:26:09 by hel-hadi          #+#    #+#             */
/*   Updated: 2016/11/18 11:09:55 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*s1;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if ((s1 = (char*)malloc(sizeof(char) * ft_strlen(s) + 1)) == NULL)
		return (NULL);
	if (s && f)
	{
		while (s[i])
		{
			s1[i] = f(s[i]);
			i++;
		}
		s1[i] = '\0';
	}
	return (s1);
}
