/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 10:00:51 by hel-hadi          #+#    #+#             */
/*   Updated: 2016/11/16 10:19:05 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int i;
	int sign;
	int number;

	i = 0;
	sign = 1;
	number = 0;
	while ((nptr[i] == '\n') || (nptr[i] == '\t') || (nptr[i] == '\v') ||
	(nptr[i] == ' ') || (nptr[i] == '\f') || (nptr[i] == '\r'))
		i++;
	if (nptr[i] == '-')
		sign = -1;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while ((nptr[i] >= '0' && nptr[i] <= '9') && (nptr[i] != '\0'))
	{
		number = nptr[i] - '0' + number * 10;
		i++;
	}
	return (number * sign);
}
