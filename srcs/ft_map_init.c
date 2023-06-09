/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan <avan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 18:32:56 by avan              #+#    #+#             */
/*   Updated: 2023/05/05 13:04:35 by avan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
