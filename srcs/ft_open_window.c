/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan <avan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:47:07 by avan              #+#    #+#             */
/*   Updated: 2023/04/28 14:24:09 by avan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	s->img = mlx_new_image(s->mlx_ptr, 1920, 1080);
	s->img_addr = mlx_get_data_addr(s->img, &(s->img_bits_per_pixel),
			&(s->img_line_length), &(s->img_endian));
	ft_pre_calculation(s);
	mlx_hook(s->win_ptr, 2, 0, ft_key_hook, s);
	mlx_hook(s->win_ptr, 17, 0, ft_close_program, s);
	mlx_loop(s->mlx_ptr);
}
