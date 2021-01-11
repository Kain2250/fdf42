/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdrinkin <bdrinkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 19:06:24 by bdrinkin          #+#    #+#             */
/*   Updated: 2021/01/11 13:58:23 by bdrinkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			rotate_x(int *y, int *z, double alpha)
{
	int			previous_y;
	float		cs;
	float		sn;

	cs = cos(alpha);
	sn = sin(alpha);
	previous_y = *y;
	*y = previous_y * cs + *z * sn;
	*z = -previous_y * sn + *z * cs;
}

void			rotate_y(int *x, int *z, double beta)
{
	int			previous_x;
	float		cs;
	float		sn;

	cs = cos(beta);
	sn = sin(beta);
	previous_x = *x;
	*x = previous_x * cs + *z * sn;
	*z = -previous_x * sn + *z * cs;
}

void			rotate_z(int *x, int *y, double gamma)
{
	int			previous_x;
	int			previous_y;
	float		cs;
	float		sn;

	cs = cos(gamma);
	sn = sin(gamma);
	previous_x = *x;
	previous_y = *y;
	*x = previous_x * cs - previous_y * sn;
	*y = previous_x * sn + previous_y * cs;
}

static void		isometria(int *x, int *y, int z)
{
	float		previous_x;
	float		previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = (previous_x + previous_y) * sin(0.523599) - z;
}

t_coord			changer(t_fdf *f, t_coord cur)
{
	cur.x *= f->change->zoom;
	cur.y *= f->change->zoom;
	cur.z *= f->change->zoom / f->change->z_range;
	cur.x -= ((f->size_x - 1) * f->change->zoom) / 2;
	cur.y -= ((f->size_y - 1) * f->change->zoom) / 2;
	rotate_z(&cur.x, &cur.y, f->change->gamma);
	rotate_x(&cur.y, &cur.z, f->change->alpha);
	rotate_y(&cur.x, &cur.z, f->change->beta);
	if (f->change->iso == ISO)
		isometria(&cur.x, &cur.y, cur.z);
	cur.x += (WIDTH + WIDTH_MENU) / 2 + f->change->x_move;
	cur.y += (HEIGHT + f->size_y / f->change->zoom) / 2 + f->change->y_move;
	return (cur);
}
