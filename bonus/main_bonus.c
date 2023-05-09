/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan <avan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:41:29 by avan              #+#    #+#             */
/*   Updated: 2023/05/09 15:41:31 by avan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static int	ft_map_verif(t_struct *s, char *filename)
{
	char	**line_verif;
	int		fd;
	int		nbr_word;

	if (!s || !filename)
		return (-1);
	fd = open(filename, O_RDONLY);
	nbr_word = 0;
	while (++(s->y) < s->lines)
	{
		line_verif = ft_line_splited_words(&nbr_word, fd, s);
		if ((s->y != 0 && s->verif_x != nbr_word) || nbr_word == 0)
			ft_bad_map_exit(s, line_verif, nbr_word);
		s->map[s->y] = (t_map_elem *)malloc(sizeof(t_map_elem) * nbr_word);
		if (!s->map[s->y])
			return (ft_free_struct(s), -1);
		if (s->y == 0)
			s->length = nbr_word;
		ft_map_init(s, nbr_word, line_verif);
		ft_free_parsing(line_verif, nbr_word);
		s->x = -1;
		s->verif_x = nbr_word;
		nbr_word = 0;
	}
	return (close(fd));
}

static int	ft_nb_lines(int fd, int *lines)
{
	int		index;
	int		checkread;
	char	stock[1024];

	ft_bzero(stock, 1024);
	checkread = read(fd, stock, 1024);
	if (!checkread)
		return (0);
	index = 0;
	while (stock[index] && index < 1024)
	{
		if (stock[index] == '\n')
			*lines += 1;
		index++;
	}
	return (checkread);
}

static int	ft_parsing(char *filename, t_struct *s)
{
	int	fd;
	int	checkread;

	if (!filename)
		return (-1);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	checkread = 1;
	s->lines = 0;
	while (checkread > 0)
		checkread = ft_nb_lines(fd, &(s->lines));
	close(fd);
	s->map = (t_map_elem **)malloc(sizeof(t_map_elem *) * s->lines);
	if (!s->map || !s->lines)
		return (-1);
	ft_map_verif(s, filename);
	return (0);
}

int	main(int argc, char **argv)
{
	t_struct	*s;

	if (argc != 2 || !ft_strnstr(argv[1], ".fdf", ft_strlen(argv[1])))
		return (2);
	s = (t_struct *)malloc(sizeof(t_struct));
	if (!s)
		return (2);
	ft_struct_init(s);
	if (ft_parsing(argv[1], s) == -1)
	{
		ft_free_ptr((void **) &(s->map));
		ft_free_ptr((void **) &s);
		return (write(2, "error", 5), 2);
	}
	ft_open_window(s);
	ft_free_struct(s);
	return (0);
}
