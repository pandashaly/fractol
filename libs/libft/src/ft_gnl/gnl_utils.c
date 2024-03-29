/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:21:07 by ssottori          #+#    #+#             */
/*   Updated: 2024/02/05 19:42:23 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/*isnewline - Returns 1 if a NL is found and 0 if a NL is not found.
 * Used in the loop condition of ft_read to know when 
 * to stop reading from the file descriptor 
 * (when a newline is encountered)*/
int	ft_isnewline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

/*strjoin - Used in ft_readfd to combine the content read from the fd (s2)
 * with the existing content(s1). 
 * It dynamically allocates memory for the result.*/
char	*ft_strjoin_g(char *s1, char *s2)
{
	char	*new_str;
	size_t	i;
	size_t	j;
	size_t	len1;
	size_t	len2;

	i = -1;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new_str = (char *)malloc(len1 + len2 + 1);
	if (!new_str)
		return (NULL);
	while (++i < len1)
		new_str[i] = s1[i];
	j = -1;
	while (++j < len2)
		new_str[i + j] = s2[j];
	new_str[i + j] = '\0';
	free(s1);
	return (new_str);
}

/* line - extracts a line from the given string until a '\n' is encountered.
 * Allocates mem to store the concat string & frees mem of original string.
 * Used in GNL to extract a line and add a '\n' char.*/
char	*ft_line(char *buff)
{
	size_t	i;
	char	*line;

	i = 0;
	if (!buff[i])
		return (NULL);
	while (buff[i] && buff[i] != '\n')
		i++;
	line = malloc(sizeof(char) * i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (buff[i] && buff[i] != '\n')
	{
		line[i] = buff[i];
		i++;
	}
	if (buff[i] && buff[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

/* readfd - important for reading from a fd in chunks of BUFF_SIZE,
 * allocates mem for buff and uses strjoin to concat newly read data from 
 * buff. Crucial for building cmplete lines from multiple */
char	*ft_readfd(int fd, char *save)
{
	int		bytes_read;
	char	*buff;

	bytes_read = 1;
	buff = (char *)malloc(sizeof(char) * (1 + BUFFER_SIZE));
	if (!buff)
		return (NULL);
	while (!ft_isnewline(save) && bytes_read != 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[bytes_read] = '\0';
		save = ft_strjoin_g(save, buff);
	}
	free (buff);
	return (save);
}

char	*ft_afternl(char *str)
{
	int		i;
	int		j;
	char	*save;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	save = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!save)
		return (NULL);
	i++;
	while (str[i])
		save[j++] = str[i++];
	save[j] = '\0';
	free(str);
	return (save);
}
