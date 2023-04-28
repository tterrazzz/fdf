/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_window_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan <avan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:52:22 by avan              #+#    #+#             */
/*   Updated: 2023/04/28 17:52:22 by avan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	ft_key_move(int key, t_struct *s)
{
	if (!s)
		return ;
	if (key == 4)
		s->height += 0.1;
	else if (key == 37)
		s->height -= 0.1;
	else if (key == 123)
		s->x_mov -= 20;
	else if (key == 124)
		s->x_mov += 20;
	else if (key == 125)
		s->y_mov += 20;
	else if (key == 126)
		s->y_mov -= 20;
	else if (key == 32)
		s->angle1 += 0.0349066;
	else if (key == 34)
		s->angle1 -= 0.0349066;
	else if (key == 38)
		s->angle2 += 0.0349066;
	else if (key == 40)
		s->angle2 -= 0.0349066;
}

static int	ft_key_hook(int key, t_struct *s)
{
	if (!s)
		return (-1);
	if (key == 53)
	{
		mlx_destroy_window(s->mlx_ptr, s->win_ptr);
		ft_free_struct(s);
		exit(0);
	}
	else if (key == 6)
		s->scale += 1;
	else if (key == 2)
		s->scale -= 1;
	else if (key == 4 || key == 37 || (key >= 123 && key <= 126) || key == 32
		|| key == 34 || key == 38 || key == 40)
		ft_key_move(key, s);
	mlx_clear_window(s->mlx_ptr, s->win_ptr);
	ft_calculation(s);
	return (0);
}

static int	ft_close_program(int key, t_struct *s)
{
	if (!s)
		return (1);
	(void) key;
	exit(0);
}

void	ft_open_window(t_struct *s)
{
	if (!s)
		return ;
	s->mlx_ptr = mlx_init();
	s->win_ptr = mlx_new_window(s->mlx_ptr, SIZE_X, SIZE_Y, "Fdf");
	ft_calculation(s);
	mlx_key_hook(s->win_ptr, ft_key_hook, s);
	mlx_hook(s->win_ptr, 17, 0, ft_close_program, s);
	mlx_loop(s->mlx_ptr);
}
