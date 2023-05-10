/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pre_calculation_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan <avan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:40:48 by avan              #+#    #+#             */
/*   Updated: 2023/05/09 16:47:40 by avan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	ft_get_xmov_ymov(t_struct *s)
{
	int	x;
	int	y;
	int	iso_x;
	int	iso_y;

	if (!s)
		return ;
	x = s->length / 2;
	y = s->lines / 2;
	iso_x = (x - y) * cos(s->angle1) * s->scale;
	iso_y = (x + y) * cos(s->angle2) * s->scale;
	s->x_mov = (1920 / 2) - iso_x;
	s->y_mov = (1080 / 2) - iso_y;
}

static void	ft_a_to_b_pts_drawing(t_struct *s, int *y, int *x)
{
	if (!s || !y || !x)
		return ;
	if (*y > 0)
	{
		*y -= 1;
		s->x2 = s->map[*y][*x].iso_x;
		s->y2 = s->map[*y][*x].iso_y;
		ft_bresenham_line(s, s->map[*y][*x].color);
		*y += 1;
	}
	*x += 1;
	s->x2 = s->map[*y][*x].iso_x;
	s->y2 = s->map[*y][*x].iso_y;
	ft_bresenham_line(s, s->map[*y][*x].color);
	if (*x == s->length - 1 && *y > 0)
	{
		s->x1 = s->x2;
		s->y1 = s->y2;
		*y -= 1;
		s->x2 = s->map[*y][*x].iso_x;
		s->y2 = s->map[*y][*x].iso_y;
		ft_bresenham_line(s, s->map[*y][*x].color);
		*y += 1;
	}
}

static void	ft_iso_map_display(t_struct *s)
{
	int	x;
	int	y;

	if (!s)
		return ;
	x = 0;
	y = s->lines - 1;
	while (y >= 0)
	{
		while (x < s->length - 1)
		{
			s->x1 = s->map[y][x].iso_x;
			s->y1 = s->map[y][x].iso_y;
			ft_a_to_b_pts_drawing(s, &y, &x);
		}
		x = 0;
		y--;
	}
	mlx_put_image_to_window(s->mlx_ptr, s->win_ptr, s->img, 0, 0);
}

void	ft_pre_calculation(t_struct *s)
{
	int	x;
	int	y;

	if (!s)
		return ;
	x = 0;
	y = 0;
	ft_get_xmov_ymov(s);
	while (y < s->lines)
	{
		while (x < s->length)
		{
			s->map[y][x].iso_x = ((x - y) * cos(s->angle1) * s->scale)
				+ s->x_mov;
			s->map[y][x].iso_y = ((-(s->map[y][x].z * s->height) + (y + x)
						* cos(s->angle2)) * s->scale) + s->y_mov;
			ft_get_big_or_lowest(s, s->map[y][x].iso_y, s->map[y][x].iso_x);
			x += 1;
		}
		x = 0;
		y += 1;
	}
	if (ft_check_value(s) > 1)
		return (ft_pre_calculation(s));
	ft_iso_map_display(s);
}
