/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 19:47:41 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/03/17 13:44:21 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int main(int argc, char **argv)
{
	t_pos pos;
	t_last	lst;
	t_last	dup;

	ft_init_lst(&lst);
	ft_init_lst(&dup);
	ft_memset(&pos, 0, sizeof(t_pos));
	if (argc == 2)
	{
		pos.fd = open(argv[1], O_RDONLY);
		if (ft_recup_info(&pos, &lst) == 0)
			return (0);
		if (ft_parse_info(&lst))
			return (0);
		ft_sort_list(&lst, &dup);
		ft_print(&lst);
		ft_print(&dup);
		ft_free_lst(&lst);
		ft_free_dup(&dup);
		ft_solve_ant(&dup);
	}
	return (0);
}
/*
int main(void)
{
	t_pos	pos;
	t_last	lst;
	t_last	dup;

	ft_init_lst(&lst);
	ft_init_lst(&dup);
	ft_memset(&pos, 0, sizeof(t_pos));
	pos.fd = 0;
	if (ft_recup_info(&pos, &lst) == 0)
		return (0);
	if (ft_parse_info(&lst))
		return (0);
	ft_sort_list(&lst, &dup);
	ft_print(&dup);
	ft_free_lst(&lst);
	ft_solve_ant(&dup);
	return (0);
}
*/