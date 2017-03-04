/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 16:07:41 by hel-hadi          #+#    #+#             */
/*   Updated: 2016/11/18 11:20:11 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_words(char const *s, char c)
{
	int count;
	int auth;

	count = 0;
	auth = 0;
	while (*s)
	{
		if (auth == 1 && *s == c)
			auth = 0;
		if (auth == 0 && *s != c)
		{
			auth = 1;
			count++;
		}
		s++;
	}
	return (count);
}
