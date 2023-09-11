/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:01:00 by azaghlou          #+#    #+#             */
/*   Updated: 2023/02/24 11:07:41 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	w_event(t_list *p)
{
	if (p->ar[p->b][p->a] == '2' && p->ar[p->b - 1][p->a] != '1')
		door_condition_out(p, 'w');
	else if (p->ar[p->b - 1][p->a] == 'E' && p->clc != 0)
		door_condition_in(p, 'w');
	else if (p->ar[p->b - 1][p->a] != '1' && p->ar[p->b - 1][p->a] != 'E')
	{
		p->count++;
		moves_writer(p);
		p->ar[p->b][p->a] = '0';
		p->b--;
		if (p->ar[p->b][p->a] == 'C')
			p->clc--;
		p->ar[p->b][p->a] = 'P';
	}
	else if (p->ar[p->b - 1][p->a] == 'E' && p->clc == 0)
	{
		p->count++;
		moves_writer(p);
		free_fct(p->ar, p);
		end_fct(p);
		exit(0);
	}
}

void	a_event(t_list *p)
{
	if (p->ar[p->b][p->a] == '2' && p->ar[p->b][p->a - 1] != '1')
		door_condition_out(p, 'a');
	else if (p->ar[p->b][p->a - 1] == 'E' && p->clc != 0)
		door_condition_in(p, 'a');
	else if (p->ar[p->b][p->a - 1] != '1' && p->ar[p->b][p->a - 1] != 'E')
	{
		p->count++;
		moves_writer(p);
		p->ar[p->b][p->a] = '0';
		p->a--;
		if (p->ar[p->b][p->a] == 'C')
			p->clc--;
		p->ar[p->b][p->a] = 'P';
	}
	else if (p->ar[p->b][p->a - 1] == 'E' && p->clc == 0)
	{
		p->count++;
		moves_writer(p);
		free_fct(p->ar, p);
		end_fct(p);
		exit(0);
	}
}

void	s_event(t_list *p)
{
	if (p->ar[p->b][p->a] == '2' && p->ar[p->b + 1][p->a] != '1')
		door_condition_out(p, 's');
	else if (p->ar[p->b + 1][p->a] == 'E' && p->clc != 0)
		door_condition_in(p, 's');
	else if (p->ar[p->b + 1][p->a] != '1' && p->ar[p->b + 1][p->a] != 'E')
	{
		p->count++;
		moves_writer(p);
		p->ar[p->b][p->a] = '0';
		p->b++;
		if (p->ar[p->b][p->a] == 'C')
			p->clc--;
		p->ar[p->b][p->a] = 'P';
	}
	else if (p->ar[p->b + 1][p->a] == 'E' && p->clc == 0)
	{
		p->count++;
		moves_writer(p);
		free_fct(p->ar, p);
		end_fct(p);
		exit(0);
	}
}

void	d_event(t_list *p)
{
	if (p->ar[p->b][p->a] == '2' && p->ar[p->b][p->a + 1] != '1')
		door_condition_out(p, 'd');
	else if (p->ar[p->b][p->a + 1] == 'E' && p->clc != 0)
		door_condition_in(p, 'd');
	else if (p->ar[p->b][p->a + 1] != '1' && p->ar[p->b][p->a + 1] != 'E')
	{
		p->count++;
		moves_writer(p);
		p->ar[p->b][p->a] = '0';
		p->a++;
		if (p->ar[p->b][p->a] == 'C')
			p->clc--;
		p->ar[p->b][p->a] = 'P';
	}
	else if (p->ar[p->b][p->a + 1] == 'E' && p->clc == 0)
	{
		p->count++;
		moves_writer(p);
		free_fct(p->ar, p);
		end_fct(p);
		exit(0);
	}
}

int	key_event(int keycode, t_list *p)
{
	if (keycode == 53)
	{
		free_fct(p->ar, p);
		end_fct(p);
		exit(0);
	}
	if (keycode == 126)
		w_event(p);
	if (keycode == 123)
		a_event(p);
	if (keycode == 125)
		s_event(p);
	if (keycode == 124)
		d_event(p);
	p->clc = 0;
	arranging(p);
	return (0);
}
