/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdrinkin <bdrinkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 23:35:07 by bdrinkin          #+#    #+#             */
/*   Updated: 2020/02/10 23:37:03 by bdrinkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point		*new_point(int x, int y, char *z, t_fdf *f)
{
	t_point	*new;

	new = (t_point *)ft_memalloc(sizeof(t_point));
	new->x = x;
	new->y = y;
	if (ft_strchr(z, ',') != NULL)
	{
		new->color = pars_color(z, f);
		new->prs_clr = 1;
	}
	else
		new->prs_clr = 0;
	new->z = z_range(f, z);
	new->first = f->point->first;
	new->next = NULL;
	return (new);
}

void		first_point(t_fdf *f, int x, int y, char *z)
{
	f->point->x = x;
	f->point->y = y;
	if (ft_strchr(z, ',') != NULL)
	{
		f->point->color = pars_color(z, f);
		f->point->prs_clr = 1;
	}
	else
		f->point->prs_clr = 0;
	f->point->z = z_range(f, z);
	f->point->first = f->point;
	f->point->next = NULL;
}

void		go_list(t_fdf *f, char *split, int x, int y)
{
	t_point	*r;

	if (x == 0 && y == 0)
		first_point(f, x, y, split);
	else
	{
		r = new_point(x, y, split, f);
		f->point->next = r;
		f->point = f->point->next;
	}
}
