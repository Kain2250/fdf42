/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hot_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdrinkin <bdrinkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 18:33:39 by bdrinkin          #+#    #+#             */
/*   Updated: 2020/02/01 16:50:54 by bdrinkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iso_flat(t_fdf *f, int key)
{
	if (key == 31)
		f->change->iso = FLAT;
	else
		f->change->iso = ISO;
	output_map(f);
}

void	key_up_down_z(t_fdf *f, int key)
{
	if (key == 47)
		f->change->z_range -= 0.1;
	else if (key == 43)
		f->change->z_range += 0.1;
	if (f->change->z_range < 0.1)
		f->change->z_range = 0.1;
	else if (f->change->z_range > 10)
		f->change->z_range = 10;
	output_map(f);
}

void	key_img_move(t_fdf *f, int key)
{
	if (key == 126)
		f->change->y_move -= 10;
	else if (key == 125)
		f->change->y_move += 10;
	else if (key == 123)
		f->change->x_move -= 10;
	else
		f->change->x_move += 10;
	output_map(f);
}

void	key_evklid_move(t_fdf *f, int key)
{
	if (key == 12)
		f->change->gamma -= 100 * 0.002;
	else if (key == 14)
		f->change->gamma += 100 * 0.002;
	else if (key == 0)
		f->change->beta -= 100 * 0.002;
	else if (key == 13)
		f->change->alpha -= 100 * 0.002;
	else if (key == 2)
		f->change->beta += 100 * 0.002;
	else
		f->change->alpha += 100 * 0.002;
	output_map(f);
}

int		cls(void *param)
{
	(void)param;
	exit(0);
}
