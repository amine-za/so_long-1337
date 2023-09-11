/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:57:31 by azaghlou          #+#    #+#             */
/*   Updated: 2023/04/02 22:41:17 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

void	search_for_c_and_p(t_list *p)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (p->ar[j])
	{
		while (p->ar[j][i])
		{
			if (p->ar[j][i] == 'P')
			{
				p->b = j;
				p->a = i;
			}
			if (p->ar[j][i] == 'C')
				p->clc++;
			i++;
		}
		j++;
		i = 0;
	}
}

void	arranging_for_norm(t_list *p, int i, int j)
{
	while (i < ft_strlen(p->ar[0]))
	{
		mlx_put_image_to_window(p->mlx, p->windw, p->background, i * 50, j
			* 50);
		if (p->ar[j][i] == '1')
			mlx_put_image_to_window(p->mlx, p->windw, p->wall, i * 50, j * 50);
		if (p->ar[j][i] == 'C')
		{
			mlx_put_image_to_window(p->mlx, p->windw, p->collectible, i * 50, j
				* 50);
			p->clc++;
		}
		if (p->ar[j][i] == 'E')
			mlx_put_image_to_window(p->mlx, p->windw, p->exit, i * 50, j * 50);
		if (p->ar[j][i] == 'P')
		{
			mlx_put_image_to_window(p->mlx, p->windw, p->player, i * 50, j
				* 50);
			p->a = i;
			p->b = j;
		}
		put_2(p, i, j);
		i++;
	}
}

void	arranging(t_list *p)
{
	int	i;
	int	j;

	j = 0;
	while (j < count_lines(p))
	{
		i = 0;
		arranging_for_norm(p, i, j);
		j++;
	}
}

void	scan_map_and_put(char **ar, t_list *p)
{
	p->mlx = mlx_init();
	p->wall = mlx_xpm_file_to_image(p->mlx, "./textures/wall.xpm", &p->height,
			&p->width);
	p->player = mlx_xpm_file_to_image(p->mlx, "./textures/player.xpm",
			&p->height, &p->width);
	p->collectible = mlx_xpm_file_to_image(p->mlx, "./textures/collectible.xpm",
			&p->height, &p->width);
	p->exit = mlx_xpm_file_to_image(p->mlx, "./textures/exit.xpm", &p->height,
			&p->width);
	p->background = mlx_xpm_file_to_image(p->mlx, "./textures/background.xpm",
			&p->height, &p->width);
	p->windw = mlx_new_window(p->mlx, (ft_strlen(p->ar[0]) - 1) * 50,
			count_lines(p) * 50, "so_long");
	if (!p->wall || !p->player || !p->collectible || !p->exit
		|| !p->background)
	{
		ft_putstr("A problem appears, please check your code.");
		end_fct(p);
		exit(1);
	}
	p->count = 0;
	arranging(p);
	mlx_hook(p->windw, 2, 0, key_event, p);
	mlx_hook(p->windw, 17, 0, close_windw, p);
	mlx_loop(p->mlx);
}

int	main(int argc, char **argv)
{
	t_list	p;

	if (argc != 2)
	{
		ft_putstr("you entered more or less than one argument.");
		exit(1);
	}
	if (my_strcmp(argv[1]) == 0)
	{
		ft_putstr("your map file name is unvalid.");
		exit(1);
	}
	p.map = argv[1];
	fill_the_arry(&p);
	search_for_c_and_p(&p);
	p.np = 0;
	p.nc = 0;
	p.ne = 0;
	check_map(&p);
	scan_map_and_put(p.ar, &p);
}
