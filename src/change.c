/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdrinkin <bdrinkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 19:06:24 by bdrinkin          #+#    #+#             */
/*   Updated: 2020/02/11 00:09:31 by bdrinkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			rotate_x(int *y, int *z, double alpha)
{
	int			previous_y;

	previous_y = *y;
	*y = previous_y * cos(alpha) + *z * sin(alpha);
	*z = -previous_y * sin(alpha) + *z * cos(alpha);
}

void			rotate_y(int *x, int *z, double beta)
{
	int			previous_x;

	previous_x = *x;
	*x = previous_x * cos(beta) + *z * sin(beta);
	*z = -previous_x * sin(beta) + *z * cos(beta);
}

void			rotate_z(int *x, int *y, double gamma)
{
	int			previous_x;
	int			previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = previous_x * cos(gamma) - previous_y * sin(gamma);
	*y = previous_x * sin(gamma) + previous_y * cos(gamma);
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
