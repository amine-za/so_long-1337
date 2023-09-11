/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 09:14:02 by azaghlou          #+#    #+#             */
/*   Updated: 2023/02/13 18:30:19 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "gnl/get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct list
{
	char	**ar;
	char	**chck;
	char	*map;
	void	*windw;
	void	*mlx;
	int		height;
	int		width;
	void	*wall;
	void	*player;
	void	*collectible;
	void	*exit;
	void	*background;
	int		fd;
	int		a;
	int		b;
	int		clc;
	int		count;
	int		for_check;
	int		np;
	int		nc;
	int		ne;
}			t_list;

int			count_lines(t_list *p);
int			key_event(int keycode, t_list *p);
void		arranging(t_list *p);
void		fill_the_arry(t_list *p);
void		fill_the_check_arry(t_list *p);
void		check_map(t_list *p);
void		search_for_c_and_p(t_list *p);
int			close_windw(t_list *p);
int			my_strcmp(char *s1);
void		free_fct(char **ar, t_list *p);
void		moves_writer(t_list *p);
void		ft_putstr(char *s);
void		door_condition_out(t_list *p, char c);
void		door_condition_in(t_list *p, char c);
void		put_2(t_list *p, int i, int j);
void		end_fct(t_list *p);

#endif