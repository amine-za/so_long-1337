/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:14:59 by azaghlou          #+#    #+#             */
/*   Updated: 2023/02/11 10:23:31 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(t_list *p)
{
	ft_putstr("your map is unvalid");
	free_fct(p->ar, p);
	free_fct(p->chck, p);
	exit(1);
}

int	check_path(t_list *p, int X, int Y)
{
	if (p->chck[X][Y] == 'C')
		p->for_check++;
	if (p->chck[X][Y] == 'E')
		p->for_check++;
	p->chck[X][Y] = '1';
	if (p->chck[X - 1][Y] != '1')
		check_path(p, X - 1, Y);
	if (p->chck[X][Y - 1] != '1')
		check_path(p, X, Y - 1);
	if (p->chck[X][Y + 1] != '1')
		check_path(p, X, Y + 1);
	if (p->chck[X + 1][Y] != '1')
		check_path(p, X + 1, Y);
	return (0);
}

void	check_last_line(t_list *p, int x, int y)
{
	if (y - 1 >= 27)
		error(p);
	while (p->ar[y - 1][x])
	{
		if (p->ar[y - 1][x] != '1')
			error(p);
		x++;
	}
}

void	check_map_for_norm(t_list *p, int x, int y, int len_line)
{
	while (p->ar[y])
	{
		while (p->ar[y][x] && p->ar[y][x] != '\n')
		{
			if (p->ar[y][x] != '1' && p->ar[y][x] != '0' && p->ar[y][x] != 'P'
				&& p->ar[y][x] != 'E' && p->ar[y][x] != 'C')
				error(p);
			if (p->ar[y][0] != '1' || p->ar[y][len_line] != '1')
				error(p);
			if (p->ar[y][x] == 'P')
				p->np++;
			if (p->ar[y][x] == 'C')
				p->nc++;
			if (p->ar[y][x] == 'E')
				p->ne++;
			x++;
		}
		if (p->ar[y][x - 1] != '1' || x - 1 != len_line)
			error(p);
		x = 0;
		y++;
	}
	check_last_line(p, x, y);
}

void	check_map(t_list *p)
{
	int	x;
	int	y;
	int	len_line;

	x = 0;
	y = 0;
	while (p->ar[0][x] && p->ar[0][x] != '\n')
	{
		if (p->ar[0][x] != '1')
			error(p);
		x++;
	}
	len_line = x - 1;
	if (len_line >= 50)
		error(p);
	x = 0;
	check_map_for_norm(p, x, y, len_line);
	if (p->np != 1 || p->ne != 1 || p->nc == 0)
		error(p);
	p->for_check = 0;
	check_path(p, p->b, p->a);
	if (p->for_check != p->clc + 1)
		error(p);
	free_fct(p->chck, p);
}
