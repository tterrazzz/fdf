/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan <avan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:36:08 by avan              #+#    #+#             */
/*   Updated: 2023/05/09 15:36:19 by avan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "mlx.h"
# define BUFFER_SIZE 1000
# define SIZE_X 1920
# define SIZE_Y 1080

typedef struct s_map_check
{
	int	up_y;
	int	right_x;
	int	down_y;
	int	left_x;
}		t_map_check;

typedef struct s_map_elem
{
	int	z;
	int	color;
	int	iso_x;
	int	iso_y;
}		t_map_elem;

typedef struct s_struct
{
	t_map_elem	**map;
	t_map_check	*map_check;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img;
	char		*img_addr;
	float		scale;
	float		height;
	float		angle1;
	float		angle2;
	int			x_mov;
	int			y_mov;
	int			lines;
	int			length;
	int			x;
	int			y;
	int			x1;
	int			y1;
	int			x2;
	int			y2;
	int			dx;
	int			dy;
	int			p;
	int			x_temp;
	int			y_temp;
	int			verif_x;
	int			lines_malloc;
	int			img_bits_per_pixel;
	int			img_line_length;
	int			img_endian;
}				t_struct;

int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);
void	ft_mlx_pixel_put(t_struct *s, int x, int y, int color);
char	**ft_split(char const *s, int *nb);
char	*ft_strdup(const char *s1);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *str);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_toupper(int c);
char	*get_next_line(int fd);

void	ft_bad_map_exit(t_struct *s, char **line_verif, int nbr_word);
void	ft_bad_map_free_struct(t_struct *s, char **line_verif, int nbr_word);
void	ft_bresenham_line(t_struct *s, int color);
void	ft_calculation(t_struct *s);
void	ft_pre_calculation(t_struct *s);
int		ft_check_value(t_struct *s);
int		ft_color_check(t_struct *s, char *str);
void	ft_free_parsing(char **tab, int nbr_word);
void	ft_free_ptr(void **ptr);
void	ft_free_struct(t_struct *s);
void	ft_get_big_or_lowest(t_struct *s, int y, int x);
char	**ft_line_splited_words(int *nbr_word, int fd, t_struct *s);
void	ft_map_init(t_struct *s, int nbr_word, char **lines_verif);
void	ft_map_check_init(t_struct *s);
void	ft_open_window(t_struct *s);
void	ft_struct_init(t_struct *s);

#endif
