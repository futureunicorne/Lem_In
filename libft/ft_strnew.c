/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 15:20:54 by hel-hadi          #+#    #+#             */
/*   Updated: 2016/11/17 19:38:02 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*tab;

	i = 0;
	if ((tab = (char*)malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	while (size--)
	{
		tab[i] = '\0';
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
