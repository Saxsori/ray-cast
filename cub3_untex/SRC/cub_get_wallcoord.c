/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_get_wallcoord.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 05:57:00 by aaljaber          #+#    #+#             */
/*   Updated: 2022/08/27 05:23:51 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_wall_coord	*create_node(void)
{
	t_wall_coord	*w_coord;

	w_coord = (t_wall_coord *)malloc(sizeof(t_wall_coord));
	w_coord->w_c = (t_coord *)malloc(sizeof(t_coord) * 4);
	w_coord->next = NULL;
	return (w_coord);
}

void	take_wall_coord(t_wall_coord *w_coord, double x, double y)
{
	w_coord->w_c[0].x = (x) * GRID;
	w_coord->w_c[0].y = (y) * GRID;
	w_coord->w_c[1].x = (x + 1) * GRID;
	w_coord->w_c[1].y = (y) * GRID;
	w_coord->w_c[2].x = (x) * GRID;
	w_coord->w_c[2].y = (y + 1) * GRID;
	w_coord->w_c[3].x = (x + 1) * GRID;
	w_coord->w_c[3].y = (y + 1) * GRID;
}

t_wall_coord	*add_wall_coord(t_wall_coord *w_coord, double x, double y)
{
	t_wall_coord	*traversal;
	t_wall_coord	*temp;

	if (!w_coord->next)
		take_wall_coord(w_coord, 0, 0);
	temp = (t_wall_coord *)malloc(sizeof(t_wall_coord));
	temp->next = NULL;
	temp->w_c = (t_coord *)malloc(sizeof(t_coord) * 4);
	take_wall_coord(temp, x, y);
	traversal = w_coord;
	while (traversal->next)
		traversal = traversal->next;
	traversal->next = temp;
	return (w_coord);
}

void	get_wall_coord(t_cub_main *main)
{
	int	x;
	int	y;

	main->w_coord = create_node();
	y = -1;
	while (main->m_info.map[++y])
	{
		x = -1;
		while (main->m_info.map[y][++x])
		{
			if (main->m_info.map[y][x] == '1')
			{
				if (y != 0 || x != 0)
					main->w_coord = add_wall_coord(main->w_coord, (double)x, (double)y);
			}
		}
	}
}

void	print_wcoord(t_wall_coord *w_coord)
{
	t_wall_coord	*temp;
	int				i;
	int				j;

	temp = w_coord;
	j = 1;
	while (temp->next)
	{
		i = -1;
		while (++i < 4)
			printf("%d x %f, y %f\n", i + 1, temp->w_c[i].x, temp->w_c[i].y);
		printf("\n");
		temp = temp->next;
		j++;
	}
}
