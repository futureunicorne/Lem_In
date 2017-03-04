/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 14:37:36 by hel-hadi          #+#    #+#             */
/*   Updated: 2016/11/16 10:15:22 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		word;
	char	**s1;

	i = 0;
	if (!s)
		return (NULL);
	word = ft_count_words(s, c);
	i = 0;
	if ((s1 = (char**)malloc(sizeof(char*) * ft_count_words(s, c) + 1)) == NULL)
		return (NULL);
	while (word--)
	{
		while (*s != '\0' && *s == c)
			s++;
		j = ft_count_len(s, c);
		s1[i] = ft_strsub(s, 0, j);
		if (s1[i] == '\0')
			return (NULL);
		s = s + ft_count_len(s, c);
		i++;
	}
	s1[i] = NULL;
	return (s1);
}
