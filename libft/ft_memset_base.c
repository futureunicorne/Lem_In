/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 08:01:37 by hel-hadi          #+#    #+#             */
/*   Updated: 2016/11/21 16:37:55 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long long	ft_prepare_u8(int c)
{
	unsigned char	buffer[sizeof(unsigned long long)];
	size_t			i;

	i = 0;
	while (i < sizeof(unsigned long long))
		buffer[i++] = (unsigned char)c;
	return (*(unsigned long long *)buffer);
}

void						*ft_memset_base(void *b, int c, size_t len)
{
	size_t					i;
	size_t					i_left;
	unsigned char			*ptr;
	unsigned long long		u8_c;

	i = 0;
	i_left = len;
	ptr = b;
	u8_c = ft_prepare_u8(c);
	while (i < len)
		if (i_left >= sizeof(unsigned long long))
		{
			*((unsigned long long *)((unsigned char *)ptr + i)) = u8_c;
			i += sizeof(unsigned long long);
			i_left -= sizeof(unsigned long long);
		}
		else
		{
			ptr[i] = (unsigned char)c;
			i += sizeof(unsigned char);
			i_left -= sizeof(unsigned char);
		}
	return (b);
}
