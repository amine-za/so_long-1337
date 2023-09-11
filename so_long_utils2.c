/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:03:09 by azaghlou          #+#    #+#             */
/*   Updated: 2023/03/07 20:09:52 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_fct(char **ar, t_list *p)
{
	int	j;

	j = 0;
	while (j < count_lines(p))
	{
		free(ar[j]);
		j++;
	}
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

void	ft_putnbr(int i)
{
	char	s;

	if (i >= 10)
	{
		ft_putnbr(i / 10);
		ft_putnbr(i % 10);
	}
	else
	{
		s = i + '0';
		write(1, &s, 1);
	}
}

void	moves_writer(t_list *p)
{
	ft_putstr("you have moved ");
	ft_putnbr(p->count);
	ft_putstr(" moves\n");
}

void	end_fct(t_list *p)
{
	if (p->wall)
		mlx_destroy_image(p->mlx, p->wall);
	if (p->collectible)
		mlx_destroy_image(p->mlx, p->collectible);
	if (p->player)
		mlx_destroy_image(p->mlx, p->player);
	if (p->exit)
		mlx_destroy_image(p->mlx, p->exit);
	if (p->background)
		mlx_destroy_image(p->mlx, p->background);
	mlx_destroy_window(p->mlx, p->windw);
}
