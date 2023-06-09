/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan <avan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 18:01:45 by avan              #+#    #+#             */
/*   Updated: 2023/04/28 18:01:46 by avan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_minisplit(char **tocutre, int i, int len)
{
	int		j;
	char	*temp;
	char	*mem;
	char	*s;

	s = *tocutre;
	temp = (char *) malloc(sizeof(char) * (i + 1));
	if (temp == NULL)
		return (NULL);
	j = -1;
	while (s[++j] && j < i)
		temp[j] = s[j];
	temp[j] = '\0';
	while (s[len] != '\0')
		len++;
	mem = (char *) malloc(sizeof(char) * (len - i + 1));
	if (!mem)
		return (free(temp), NULL);
	j = -1;
	while (s[++j] && j < (len - i))
		mem[j] = s[j + i];
	mem[j] = '\0';
	free(*tocutre);
	*tocutre = temp;
	return (mem);
}

static char	*ft_growbuffer(int fd, char **buffer, int checkread, char *result)
{
	char	*temp;
	int		checkn;

	if (*buffer)
		result = *buffer;
	*buffer = NULL;
	while (checkread > 0)
	{
		temp = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!temp)
			return (NULL);
		checkread = read(fd, temp, BUFFER_SIZE);
		if (checkread == -1)
			return (free(temp), NULL);
		temp[checkread] = '\0';
		result = ft_strjoin(&result, &temp);
		checkn = ft_strchr_int(result, '\n');
		if (checkn > 0)
		{
			*buffer = ft_minisplit(&result, checkn, 0);
			break ;
		}
	}
	return (result);
}

char	*get_next_line(int fd)
{
	char		*result;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (buffer)
			free(buffer);
		buffer = NULL;
		return (NULL);
	}
	result = ft_growbuffer(fd, &buffer, 1, NULL);
	if (result[0] == '\0')
		return (free(result), NULL);
	return (result);
}
