/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan <avan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:40:39 by avan              #+#    #+#             */
/*   Updated: 2023/04/28 17:51:12 by avan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_ptr(void **ptr)
{
	if (ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

void	ft_free_parsing(char **tab, int nbr_word)
{
	int	i;

	if (!tab || !(*tab))
		return ;
	i = 0;
	while (i < nbr_word)
	{
		ft_free_ptr((void **) &(tab[i]));
		i++;
	}
	ft_free_ptr((void **) &tab);
}

void	ft_bad_map_free_struct(t_struct *s, char **line_verif, int nbr_word)
{
	int	i;

	if (!s || !line_verif)
		return ;
	i = 0;
	while (i < s->lines_malloc - 1)
	{
		ft_free_ptr((void **) &(s->map[i]));
		i++;
	}
	ft_free_parsing(line_verif, nbr_word);
	ft_free_ptr((void **) &(s->map));
	ft_free_ptr((void **) &s);
}

void	ft_free_struct(t_struct *s)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (i < s->lines)
	{
		ft_free_ptr((void **) &(s->map[i]));
		i++;
	}
	ft_free_ptr((void **) &(s->map));
	ft_free_ptr((void **) &s);
}
