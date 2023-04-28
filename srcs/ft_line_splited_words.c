/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_splited_words.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan <avan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:16:17 by avan              #+#    #+#             */
/*   Updated: 2023/04/28 17:38:25 by avan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_bad_map_exit(t_struct *s, char **line_verif, int nbr_word)
{
	if (!s || !line_verif)
		return ;
	ft_bad_map_free_struct(s, line_verif, nbr_word);
	exit(1);
}

char	**ft_line_splited_words(int *nbr_word, int fd, t_struct *s)
{
	char	**lines_verif;
	char	*stock;

	if (!nbr_word || !s)
		return (NULL);
	stock = get_next_line(fd);
	lines_verif = ft_split(stock, nbr_word);
	free(stock);
	s->lines_malloc += 1;
	return (lines_verif);
}
