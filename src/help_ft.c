/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdrinkin <bdrinkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 19:26:04 by bdrinkin          #+#    #+#             */
/*   Updated: 2020/02/11 17:48:47 by bdrinkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		menu_2(t_fdf *f, int y)
{
	mlx_string_put(f->ptr, f->win, 20, y += 35, T_COLL,
	"Key \"A\" | Rotate Left");
	mlx_string_put(f->ptr, f->win, 20, y += 35, T_COLL,
	"Key \"D\" | Rotate Right");
	mlx_string_put(f->ptr, f->win, 20, y += 35, T_COLL,
	"Key \"L\" | LSD mod =)");
	mlx_string_put(f->ptr, f->win, 20, y += 35, T_COLL,
	"Key \"C\" | Change color");
	mlx_string_put(f->ptr, f->win, 20, y += 35, T_COLL,
	"Key \"K\" | Stop all mod");
	mlx_string_put(f->ptr, f->win, 20, y += 35, T_COLL,
	"Key \"P\" | Plase mod");
	mlx_string_put(f->ptr, f->win, 20, y += 35, T_COLL,
	"(to see all edge of shape)");
}

void		menu(t_fdf *f)
{
	int		y;

	y = 0;
	mlx_string_put(f->ptr, f->win, 20, y += 35, T_COLL,
	"\"Scroll up/down\" | Zoom +/-");
	mlx_string_put(f->ptr, f->win, 20, y += 35, T_COLL,
	"\"Arrow\" | Move Image");
	mlx_string_put(f->ptr, f->win, 20, y += 35, T_COLL,
	"\"Mouse move\" | Rotate Image");
	mlx_string_put(f->ptr, f->win, 20, y += 35, T_COLL, "Key \"I\" | ISO");
	mlx_string_put(f->ptr, f->win, 20, y += 35, T_COLL, "Key \"O\" | FLAT");
	mlx_string_put(f->ptr, f->win, 20, y += 35, T_COLL,
	"Key \"U\" | Refresh Image");
	mlx_string_put(f->ptr, f->win, 20, y += 35, T_COLL,
	"Key \"<\" | Dawn Z");
	mlx_string_put(f->ptr, f->win, 20, y += 35, T_COLL,
	"Key \">\" | Up Z");
	mlx_string_put(f->ptr, f->win, 20, y += 35, T_COLL,
	"Key \"W\" | Rotate Up");
	mlx_string_put(f->ptr, f->win, 20, y += 35, T_COLL,
	"Key \"S\" | Rotate Dawn");
	menu_2(f, y);
}

double		percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	if (distance == 0)
		return (1.0);
	return (placement / distance);
}

void		error_exit(char *s, t_fdf *f)
{
	ft_putendl(s);
	free(f->point);
	free(f->change);
	free(f->mouse);
	exit(0);
}
