/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_condition.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:31:59 by azaghlou          #+#    #+#             */
/*   Updated: 2023/01/20 13:06:44 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	door_condition_out(t_list *p, char c)
{
	p->count++;
	moves_writer(p);
	p->ar[p->b][p->a] = 'E';
	if (c == 'w')
		p->b--;
	if (c == 'a')
		p->a--;
	if (c == 's')
		p->b++;
	if (c == 'd')
		p->a++;
	if (p->ar[p->b][p->a] == 'C')
		p->clc--;
	p->ar[p->b][p->a] = 'P';
}

void	door_condition_in(t_list *p, char c)
{
	p->count++;
	moves_writer(p);
	p->ar[p->b][p->a] = '0';
	if (c == 'w')
		p->b--;
	if (c == 'a')
		p->a--;
	if (c == 's')
		p->b++;
	if (c == 'd')
		p->a++;
	p->ar[p->b][p->a] = '2';
}

void	put_2(t_list *p, int i, int j)
{
	if (p->ar[j][i] == '2')
	{
		mlx_put_image_to_window(p->mlx, p->windw, p->exit, i * 50, j * 50);
		mlx_put_image_to_window(p->mlx, p->windw, p->player, i * 50,
			j * 50);
		p->a = i;
		p->b = j;
	}
}
