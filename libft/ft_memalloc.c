/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 11:43:23 by hel-hadi          #+#    #+#             */
/*   Updated: 2016/11/17 19:57:09 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	i;
	char	*tab;

	i = 0;
	if ((tab = (void*)malloc(sizeof(void*) * (size))) == NULL)
		return (NULL);
	ft_bzero(tab, size);
	return (tab);
}
