/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 19:47:41 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/03/08 08:04:00 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int main(void)
{
	t_pos pos;

	ft_memset(&pos, 0, sizeof(t_pos));

	ft_recup_info(&pos);
	//ft_parse_info(&pos);
	//ft_solve_lem(&pos);
	return (0);
}
