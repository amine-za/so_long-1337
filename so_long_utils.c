/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:54:56 by azaghlou          #+#    #+#             */
/*   Updated: 2023/02/25 15:08:54 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_lines(t_list *p)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(p->map, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		free(line);
		if (!line)
		{
			close(fd);
			return (i);
		}
		i++;
	}
	return (0);
}

void	fill_the_check_arry(t_list *p)
{
	int	x;
	int	j;

	j = 0;
	p->fd = open(p->map, O_RDONLY);
	x = count_lines(p);
	p->fd = open(p->map, O_RDONLY);
	p->chck = malloc(sizeof(char *) * (x + 1));
	if (!p->chck)
	{
		free_fct(p->ar, p);
		exit(1);
	}
	while (1)
	{
		p->chck[j] = get_next_line(p->fd);
		if (!(p->chck[j]))
			break ;
		j++;
	}
	close(p->fd);
}

void	fill_the_arry(t_list *p)
{
	int	x;
	int	j;

	j = 0;
	p->fd = open(p->map, O_RDONLY);
	if (p->fd == -1)
	{
		ft_putstr("your map file dont exist.");
		exit(1);
	}
	x = count_lines(p);
	p->fd = open(p->map, O_RDONLY);
	p->ar = malloc(sizeof(char *) * (x + 1));
	if (!p->ar)
		exit(1);
	while (1)
	{
		p->ar[j] = get_next_line(p->fd);
		if (!(p->ar[j]))
			break ;
		j++;
	}
	close(p->fd);
	fill_the_check_arry(p);
}

int	close_windw(t_list *p)
{
	free_fct(p->ar, p);
	end_fct(p);
	exit(0);
	return (0);
}

int	my_strcmp(char *s1)
{
	char	*ber;
	int		i;
	int		len;

	ber = ".ber";
	len = ft_strlen(s1) - 4;
	i = 0;
	while (len + i <= ft_strlen(s1))
	{
		if (s1[len + i] != ber[i])
			return (0);
		i++;
	}
	return (1);
}
