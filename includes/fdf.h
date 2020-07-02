/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdrinkin <bdrinkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 17:42:41 by bdrinkin          #+#    #+#             */
/*   Updated: 2020/02/11 17:44:39 by bdrinkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include <mlx.h>
# include <math.h>

# define WIDTH 1950
# define HEIGHT 1350
# define WIDTH_MENU 320
# define T_COLL 0xFFFFFF
# define A_PIX 0x0000CD
# define B_PIX 0x2100CD
# define C_PIX 0x4500CD
# define D_PIX 0x6600CD
# define E_PIX 0x8A00CD
# define F_PIX 0xAD00CD
# define G_PIX 0xCD00CC
# define H_PIX 0xCD00A8
# define I_PIX 0xCD0087
# define J_PIX 0xCD0066
# define K_PIX 0xCD0042
# define L_PIX 0xCD0021
# define M_PIX 0xCD0200

typedef enum
{
	ISO,
	FLAT
}	t_iso;

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
	int				color;
	int				prs_clr;
	struct s_point	*first;
	struct s_point	*next;
}					t_point;

typedef struct		s_coord
{
	int				x;
	int				y;
	int				z;
	int				color;
}					t_coord;

typedef struct		s_change
{
	int				zoom;
	int				y_move;
	int				x_move;
	double			alpha;
	double			beta;
	double			gamma;
	float			z_range;
	t_iso			iso;
}					t_change;

typedef struct		s_mouse
{
	char			is_pressed;
	int				x;
	int				y;
	int				previous_x;
	int				previous_y;
}					t_mouse;

typedef struct		s_fdf
{
	void			*ptr;
	void			*win;
	void			*img;
	char			*data_addr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	int				size_y;
	int				size_x;
	int				color_menu;
	int				color_back_ground;
	int				z_min;
	int				z_max;
	int				z_range;
	int				dir;
	int				pir;
	int				x_check;
	t_point			*point;
	t_change		*change;
	t_mouse			*mouse;
}					t_fdf;

void				init_struct(t_fdf *f, char *av);
void				read_file(char *av, t_fdf *f);

void				error_exit(char *s, t_fdf *f);
t_point				*new_point(int x, int y, char *z, t_fdf *f);
int					pars_color(char *line, t_fdf *f);
double				percent(int start, int end, int current);
int					get_light(int start, int end, double percentage);
int					get_color(t_coord current, t_coord start, t_coord end,
					t_coord delta);

void				put_pixel(int x, int y, t_fdf *f, int color);
void				output_background(t_fdf *f);
void				menu(t_fdf *f);
void				rotate_x(int *y, int *z, double alpha);
void				rotate_y(int *x, int *z, double beta);
void				rotate_z(int *x, int *y, double gamma);

int					cls(void *param);
void				iso_flat(t_fdf *f, int key);
void				key_up_down_z(t_fdf *f, int key);
void				key_img_move(t_fdf *f, int key);
void				key_evklid_move(t_fdf *f, int key);

t_coord				p_to_crd(int x, int y, int z, int color);
int					z_cur(t_point *p, t_fdf *f);
int					z_range(t_fdf *f, char *split);
int					find_color(t_point *p, t_fdf *f);
int					get_current_color(t_fdf *f, int z);
void				go_list(t_fdf *f, char *split, int x, int y);

int					main(int ac, char **av);
void				output_map(t_fdf *f);
void				hook_list(t_fdf *f);

int					check_line(char *buff);
t_coord				changer(t_fdf *f, t_coord cur);
void				chenge_color(t_fdf *f);
int					ft_change_color1(double proc);
int					ft_change_color2(double proc);
void				bonus_hook(int key, t_fdf *f);

#endif
