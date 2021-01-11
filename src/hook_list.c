/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdrinkin <bdrinkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 15:31:50 by bdrinkin          #+#    #+#             */
/*   Updated: 2021/01/11 13:27:21 by bdrinkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	key_press(int key, void *param)
{
	t_fdf	*f;

	f = (t_fdf *)param;
	if (key == KEY_ESC)
		exit(0);
	if (key == 35 || key == 8 || key == 37 || key == 40)
		bonus_hook(key, f);
	if (key == 126 || key == 125 || key == 123 || key == 124)
		key_img_move(f, key);
	if (key == 47 || key == 43)
		key_up_down_z(f, key);
	if (key == 31 || key == 34)
		iso_flat(f, key);
	if (key == 32)
	{
		f->change->alpha = 0;
		f->change->beta = 0;
		f->change->gamma = 0;
		output_map(f);
	}
	if (key == 0 || key == 13 || key == 2 || key == 1 ||
	key == 12 || key == 14)
		key_evklid_move(f, key);
	return (0);
}

static int	mouse_key(int button, int x, int y, void *param)
{
	t_fdf	*f;

	(void)y;
	(void)x;
	f = (t_fdf *)param;
	if (button == 5)
	{
		f->change->zoom++;
		output_map(f);
	}
	if (button == 4)
	{
		f->change->zoom--;
		if (f->change->zoom < 1)
			f->change->zoom = 1;
		output_map(f);
	}
	if (button == 1 && y > 0)
		f->mouse->is_pressed = 1;
	return (0);
}

static int	mouse_pep(int button, int x, int y, void *param)
{
	t_fdf	*f;

	(void)x;
	(void)y;
	(void)button;
	f = (t_fdf *)param;
	f->mouse->is_pressed = 0;
	return (0);
}

int			mouse_move(int x, int y, void *param)
{
	t_fdf	*f;

	f = (t_fdf *)param;
	f->mouse->previous_x = f->mouse->x;
	f->mouse->previous_y = f->mouse->y;
	f->mouse->x = x;
	f->mouse->y = y;
	if (f->mouse->is_pressed == 1)
	{
		f->change->beta += (x - f->mouse->previous_x) * 0.002;
		f->change->alpha += (y - f->mouse->previous_y) * 0.002;
		output_map(f);
	}
	return (0);
}

void		hook_list(t_fdf *f)
{
	mlx_hook(f->win, 2, (1L << 1), key_press, f);
	mlx_hook(f->win, 17, 1, cls, f);
	mlx_hook(f->win, 4, (1L << 2), mouse_key, f);
	mlx_hook(f->win, 5, (1L << 3), mouse_pep, f);
	mlx_hook(f->win, 6, (1L << 13), mouse_move, f);
	mlx_loop(f->ptr);
}
