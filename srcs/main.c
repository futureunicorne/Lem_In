/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 19:47:41 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/03/26 12:43:22 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	main(void)
{
	t_pas	pas;
	t_last	lst;
	t_last	dup;
	t_list	*tmp;

	ft_init_lst(&lst);
	ft_init_lst(&dup);
	ft_memset(&pas, 0, sizeof(t_pas));
	pas.fd = 0;
	if (ft_recup_info(&pas, &lst) == 0)
		return (0);
	if (ft_parse_info(&lst) == 0)
	{
		ft_free_lst(&lst);
		return (0);
	}
	ft_sort_list(&lst, &dup);
	ft_starter(&lst);
	if (check_link_ob(&dup) == 0)
	{
		ft_free_lst(&lst);
		ft_putendl("ERROR");
		return (0);
	}
	switch_start(&dup);
	tmp = ft_bfs(&dup);
	if (tmp == NULL)
	{
		ft_free_lst(&lst);
		return (0);
	}
	ft_print_begin(&lst);
	ft_put_result(&dup, tmp);
	ft_free_lst(&lst);
	ft_free_dup(&dup);
	return (0);
}
