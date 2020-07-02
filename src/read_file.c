/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdrinkin <bdrinkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 19:22:23 by bdrinkin          #+#    #+#             */
/*   Updated: 2020/02/10 22:42:15 by bdrinkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	get_z(char *line, t_fdf *f)
{
	int		x;
	int		y;
	char	**split;
	char	**sline;

	sline = ft_strsplit(line, '\n');
	y = 0;
	while (y != f->size_y)
	{
		x = 0;
		split = ft_strsplit(sline[y], ' ');
		while (x != f->size_x && split[x] != NULL)
		{
			go_list(f, split[x], x, y);
			x++;
		}
		y++;
		ft_free_split(split);
	}
	f->point = f->point->first;
	ft_free_split(sline);
}

static int	get_x(char *line, t_fdf *f)
{
	int		i;
	int		x;

	i = 0;
	x = 1;
	while (line[i] == ' ')
		i++;
	while (line[i] != '\0')
	{
		if (line[i] == ',')
			i += 8;
		if (line[i] == ' ' && line[i + 1] != ' ' && line[i + 1] != '\0')
			x++;
		i++;
	}
	if (f->x_check == 0)
		f->x_check = x;
	else if (f->x_check != x)
		return (0);
	return (x);
}

static char	*read_line(int fd)
{
	char	*line;
	int		i;
	char	*buff;
	char	*buff2;

	line = malloc(10001 * sizeof(char));
	buff = malloc(1 * sizeof(char));
	buff[0] = '\0';
	while ((i = read(fd, line, 10000)) > 0)
	{
		line[10000] = '\0';
		buff2 = ft_strjoin_free(buff, line);
		line = malloc(10001 * sizeof(char));
		buff = buff2;
	}
	free(line);
	return (buff2);
}

static void	color_write(t_fdf *f)
{
	t_point *p;

	p = f->point->first;
	while (p != NULL)
	{
		if (p->prs_clr == 1)
			p = p->next;
		else if (p->next == NULL)
		{
			p->color = get_current_color(f, p->z);
			break ;
		}
		else
		{
			p->color = get_current_color(f, p->z);
			p = p->next;
		}
	}
}

void		read_file(char *av, t_fdf *f)
{
	int		fd;
	char	*buff;

	if ((fd = open(av, O_RDONLY)) < 0)
		error_exit("\033[0;31;1mError open\033[0m", f);
	while (get_next_line2(fd, &buff))
	{
		if (check_line(buff) && (f->size_x = get_x(buff, f)) != 0)
			f->size_y++;
		else
		{
			free(buff);
			error_exit("\033[0;31;1mInvalid file\033[0m", f);
		}
		ft_strdel(&buff);
	}
	if (!f->size_x && !f->size_y)
		error_exit("\033[0;31;1mInvalid file\033[0m", f);
	close(fd);
	fd = open(av, O_RDONLY);
	buff = read_line(fd);
	close(fd);
	get_z(buff, f);
	color_write(f);
	free(buff);
}
