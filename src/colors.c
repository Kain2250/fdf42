/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdrinkin <bdrinkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 18:07:40 by bdrinkin          #+#    #+#             */
/*   Updated: 2020/02/11 00:07:03 by bdrinkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			get_light(int start, int end, double percentage)
{
	int		ret;

	ret = (1 - percentage) * start + (percentage * end);
	return (ret);
}

int			get_color(t_coord current, t_coord start, t_coord end,
t_coord delta)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (current.color == end.color)
		return (current.color);
	if (delta.x > delta.y)
		percentage = percent(start.x, end.x, current.x);
	else
		percentage = percent(start.y, end.y, current.y);
	red = get_light((start.color >> 16) & 0xFF,
	(end.color >> 16) & 0xFF, percentage);
	green = get_light((start.color >> 8) & 0xFF,
	(end.color >> 8) & 0xFF, percentage);
	blue = get_light(start.color & 0xFF, end.color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}

int			pars_color(char *line, t_fdf *f)
{
	char	*str;
	int		color;

	color = 0;
	if (ft_strchr(line, 'x') != NULL && (str = ft_strchr(line, ',')) != NULL)
		color = ft_atoi_base(++str, 16);
	else
		error_exit("Not valid map (color is incorect)", f);
	return (color);
}

int			get_current_color(t_fdf *f, int z)
{
	double	proc;
	int		color;

	proc = percent(f->z_min, f->z_max, z);
	if ((color = ft_change_color1(proc)) != 0)
		return (color);
	else
		color = ft_change_color2(proc);
	return (color);
}

void		chenge_color(t_fdf *f)
{
	t_point	*temp;

	temp = f->point;
	while (temp)
	{
		if (f->pir == 1)
			temp->color += 10000;
		else
			temp->color -= 10000;
		temp = temp->next;
	}
}
