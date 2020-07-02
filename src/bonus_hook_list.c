/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_hook_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdrinkin <bdrinkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 23:53:27 by bdrinkin          #+#    #+#             */
/*   Updated: 2020/02/11 00:05:49 by bdrinkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		place_mod_on(t_fdf *f)
{
	if (f->dir == 1)
	{
		f->change->z_range += 0.1;
		f->change->gamma += 0.005;
		if (f->change->z_range > 10)
			f->dir = 0;
	}
	else
	{
		f->change->z_range -= 0.1;
		f->change->gamma += 0.005;
		if (f->change->z_range < 1)
			f->dir = 1;
	}
	output_map(f);
	return (0);
}

void	move_gamma(t_fdf *f)
{
	if (f->pir == 1)
	{
		f->change->beta += 0.005;
		if (f->change->beta > 0.02)
			f->pir = 0;
	}
	else
	{
		f->change->beta -= 0.005;
		if (f->change->beta < -0.02)
			f->pir = 1;
	}
}

int		lsd_mod_on(t_fdf *f)
{
	chenge_color(f);
	if (f->dir == 1)
	{
		move_gamma(f);
		f->change->alpha += 0.005;
		if (f->change->alpha > 0.04)
			f->dir = 0;
	}
	else
	{
		move_gamma(f);
		f->change->alpha -= 0.005;
		if (f->change->alpha < -0.04)
			f->dir = 1;
	}
	output_map(f);
	return (0);
}

int		loop_stop(void)
{
	return (0);
}

void	bonus_hook(int key, t_fdf *f)
{
	if (key == 35)
		mlx_loop_hook(f->ptr, place_mod_on, f);
	else if (key == 8)
		chenge_color(f);
	else if (key == 37)
		mlx_loop_hook(f->ptr, lsd_mod_on, f);
	else
		mlx_loop_hook(f->ptr, loop_stop, f);
}
