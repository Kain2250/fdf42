/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdrinkin <bdrinkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 14:57:59 by bdrinkin          #+#    #+#             */
/*   Updated: 2020/02/11 00:10:46 by bdrinkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			put_pixel(int x, int y, t_fdf *f, int color)
{
	int			i;

	if (x >= WIDTH_MENU && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		i = (x * f->bits_per_pixel / 8) + (y * f->size_line);
		f->data_addr[i] = color;
		f->data_addr[++i] = color >> 8;
		f->data_addr[++i] = color >> 16;
		f->data_addr[++i] = 0;
	}
}

static void		drow_line(t_fdf *f, t_coord cur, t_coord next)
{
	int			error[2];
	t_coord		delta;
	t_coord		sign;
	t_coord		tek;

	delta.x = abs(next.x - cur.x);
	delta.y = abs(next.y - cur.y);
	sign.x = cur.x < next.x ? 1 : -1;
	sign.y = cur.y < next.y ? 1 : -1;
	error[0] = delta.x - delta.y;
	tek = cur;
	while (tek.x != next.x || tek.y != next.y)
	{
		put_pixel(tek.x, tek.y, f, get_color(tek, cur, next, delta));
		if ((error[1] = error[0] * 2) > -delta.y)
		{
			error[0] -= delta.y;
			tek.x += sign.x;
		}
		if (error[1] < delta.x)
		{
			error[0] += delta.x;
			tek.y += sign.y;
		}
	}
}

void			output_background(t_fdf *f)
{
	int			*image;
	int			i;

	ft_bzero(f->data_addr, WIDTH * HEIGHT * (f->bits_per_pixel / 8));
	image = (int *)(f->data_addr);
	i = 0;
	while (i < HEIGHT * WIDTH)
	{
		image[i] = (i % WIDTH < WIDTH_MENU) ? f->color_menu :
		f->color_back_ground;
		i++;
	}
}

void			output_map(t_fdf *f)
{
	t_point		*p;

	p = f->point->first;
	output_background(f);
	while (p != NULL)
	{
		if (p->x < f->size_x - 1)
		{
			drow_line(f, changer(f, p_to_crd(p->x, p->y,
			p->z, p->color)),
			changer(f, p_to_crd(p->x + 1, p->y, p->next->z,
			p->next->color)));
		}
		if (p->y < f->size_y - 1)
		{
			drow_line(f, changer(f, p_to_crd(p->x, p->y, p->z,
			p->color)),
			changer(f, p_to_crd(p->x, p->y + 1, z_cur(p, f),
			find_color(p, f))));
		}
		p = p->next;
	}
	mlx_put_image_to_window(f->ptr, f->win, f->img, 0, 0);
	menu(f);
}
