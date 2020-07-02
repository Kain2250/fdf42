/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crutch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdrinkin <bdrinkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 18:59:36 by bdrinkin          #+#    #+#             */
/*   Updated: 2020/02/10 23:53:57 by bdrinkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coord		p_to_crd(int x, int y, int z, int color)
{
	t_coord	p;

	p.x = x;
	p.y = y;
	p.z = z;
	p.color = color;
	return (p);
}

int			z_cur(t_point *p, t_fdf *f)
{
	t_point	*r;
	int		i;

	r = p;
	i = 0;
	while (i != f->size_x)
	{
		r = r->next;
		i++;
	}
	return (r->z);
}

int			find_color(t_point *p, t_fdf *f)
{
	t_point	*r;
	int		i;

	r = p;
	i = 0;
	while (i != f->size_x)
	{
		r = r->next;
		i++;
	}
	return (r->color);
}

int			z_range(t_fdf *f, char *split)
{
	int		z;

	z = ft_atoi(split);
	if (z > 500)
		z = 500;
	else if (z < -500)
		z = -500;
	if (z > f->z_max)
		f->z_max = z;
	if (z < f->z_min)
		f->z_min = z;
	return (z);
}
