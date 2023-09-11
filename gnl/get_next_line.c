/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 10:52:21 by azaghlou          #+#    #+#             */
/*   Updated: 2023/01/20 13:09:50 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*therest(char *str)
{
	char	*ptr;
	int		j;
	int		i;

	j = 0;
	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (0);
	}
	i++;
	ptr = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!ptr)
		return (0);
	while (str[i])
		ptr[j++] = str[i++];
	ptr[j] = '\0';
	free(str);
	return (ptr);
}

char	*srchnl(char *str)
{
	int		i;
	char	*aa;

	i = 0;
	if (ft_strlen(str) == 0)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	aa = malloc(sizeof(char) * (i + 2));
	if (!aa)
		return (NULL);
	i = 0;
	while (str[i])
	{
		aa[i] = str[i];
		i++;
		if (str[i - 1] == '\n')
			break ;
	}
	aa[i] = '\0';
	return (aa);
}

char	*reader(int fd, char *str)
{
	char	buffer[BUFFER_SIZE + 1];
	int		i;

	i = 1;
	while (!ft_strchr(str, '\n') && i != 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(str);
			return (0);
		}
		buffer[i] = '\0';
		str = ft_strjoin(str, buffer);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*sttc;

	if ((fd < 0) || (BUFFER_SIZE <= 0) || fd == 1 || fd == 2)
		return (0);
	sttc = reader(fd, sttc);
	if (!sttc)
		return (NULL);
	line = srchnl(sttc);
	sttc = therest(sttc);
	return (line);
}
