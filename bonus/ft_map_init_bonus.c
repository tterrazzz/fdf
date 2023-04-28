/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_init_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan <avan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:52:19 by avan              #+#    #+#             */
/*   Updated: 2023/04/28 17:52:20 by avan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	ft_map_init(t_struct *s, int nbr_word, char **lines_verif)
{
	int	color;

	if (!s)
		return ;
	color = 0;
	while (++(s->x) < nbr_word)
	{
		s->map[s->y][s->x].z = ft_atoi(lines_verif[s->x]);
		color = ft_color_check(s, lines_verif[s->x]);
		if (color != 0)
			s->map[s->y][s->x].color = color;
		else
			s->map[s->y][s->x].color = 16777215;
		color = 0;
	}
}
