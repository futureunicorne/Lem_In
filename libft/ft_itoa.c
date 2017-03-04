/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 13:56:31 by hel-hadi          #+#    #+#             */
/*   Updated: 2016/11/15 11:49:37 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int			i;
	char		*s1;
	int long	nb;

	nb = n;
	i = ft_count_num(nb);
	if ((s1 = (char*)malloc(sizeof(char) * ft_count_num(nb) + 1)) == NULL)
		return (NULL);
	if (nb < 0)
	{
		nb = nb * (-1);
		s1[0] = '-';
	}
	s1[i] = '\0';
	i--;
	if ((nb >= 0) && (nb <= 9))
		s1[i] = nb + 48;
	while (nb > 0)
	{
		s1[i] = (nb % 10) + 48;
		nb = nb / 10;
		i--;
	}
	return (s1);
}
