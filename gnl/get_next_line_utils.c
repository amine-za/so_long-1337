/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 10:58:57 by azaghlou          #+#    #+#             */
/*   Updated: 2022/11/17 15:56:54 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ss;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (0);
	ss = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ss)
		return (0);
	while (s1 && s1[i])
	{
		ss[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		ss[i] = s2[j];
		j++;
		i++;
	}
	ss[i] = '\0';
	free(s1);
	return (ss);
}

int	ft_strchr(char *ss, char c)
{
	int	i;

	i = 0;
	if (!ss)
		return (0);
	while (ss[i])
	{
		if (ss[i] == c)
			return (1);
		i++;
	}
	return (0);
}
