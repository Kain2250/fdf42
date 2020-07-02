/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdrinkin <bdrinkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 17:58:10 by bdrinkin          #+#    #+#             */
/*   Updated: 2020/02/10 23:21:41 by bdrinkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ptr_init(t_fdf *ptr)
{
	ptr->color_menu = 0x131313;
	ptr->color_back_ground = 0x0A0A0A;
	ptr->change->z_range = 1;
	ptr->data_addr = mlx_get_data_addr(ptr->img, &(ptr->bits_per_pixel),
	&(ptr->size_line), &(ptr->endian));
	ptr->change->zoom = ft_min((WIDTH - WIDTH_MENU) /
	ptr->size_x / 2, HEIGHT / ptr->size_y / 2);
	ptr->dir = 1;
	ptr->pir = 1;
}

void		init_struct(t_fdf *ptr, char *av)
{
	if (!(ptr->change = (t_change *)ft_memalloc(sizeof(t_change))))
		error_exit("\033[0;31;1mError malloc by (change ptr)\033[0m", ptr);
	if (!(ptr->mouse = (t_mouse *)ft_memalloc(sizeof(t_mouse))))
		error_exit("\033[0;31;1mError malloc by (mouse ptr)\033[0m", ptr);
	if (!(ptr->ptr = mlx_init()))
		error_exit("\033[0;31;1mError mlx_init\033[0m", ptr);
	if (!(ptr->win = mlx_new_window(ptr->ptr, WIDTH, HEIGHT, av)))
		error_exit("\033[0;31;1mError win_init\033[0m", ptr);
	if (!(ptr->img = mlx_new_image(ptr->ptr, WIDTH, HEIGHT)))
		error_exit("\033[0;31;1mError img_init\033[0m", ptr);
	ptr_init(ptr);
}
