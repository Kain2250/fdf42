/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdrinkin <bdrinkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 17:42:05 by bdrinkin          #+#    #+#             */
/*   Updated: 2020/02/10 05:41:06 by bdrinkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			main(int ac, char **av)
{
	t_fdf	*f;

	if (ac == 2)
	{
		if (!(f = (t_fdf *)ft_memalloc(sizeof(t_fdf))))
			error_exit("\033[0;31;1mError malloc by (fdf ptr)\033[0m", f);
		if (!(f->point = (t_point *)malloc(sizeof(t_point))))
			error_exit("\033[0;31;1mError malloc by (point ptr)\033[0m", f);
		read_file(av[1], f);
		init_struct(f, av[1]);
		output_map(f);
		hook_list(f);
		free(f);
	}
	else
	{
		ft_putstr("\033[0;32;1mFdf is not joke!\n\033[0m");
		ft_putstr("\033[0;32;1mUse: ./fdf [fdf_map_file.fdf]\n\033[0m");
	}
	return (0);
}
