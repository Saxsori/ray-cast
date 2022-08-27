/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 21:38:59 by aaljaber          #+#    #+#             */
/*   Updated: 2022/08/27 05:52:20 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
! check if it won't return -1
*/
int	check_big_width(t_cub_main *main)
{
	int	i;
	int	re;

	i = -1;
	re = -1;
	while (++i < main->m_info.size.height)
	{
		if (re < main->m_info.map_dimn[i])
			re = main->m_info.map_dimn[i];
	}
	return (re);
}

void	squaredint_free(int **array, int len)
{
	int		i;

	i = -1;
	while (++i < len)
		free(array[i]);
	free(array);
}

void	free_wall_coord(t_cub_main *main)
{
	t_wall_coord	*traversal;
	t_wall_coord	*node;

	node = main->w_coord;
	while (node)
	{
		traversal = node->next;
		free(node);
		node = traversal;
	}
}

int	endgame(void *param)
{
	t_cub_main *main;

	main = (t_cub_main *)param;
	mlx_destroy_window(main->x_info.mlx, main->x_info.window);
	free(main->data);
	free(main->image);
	squaredint_free((int **)main->buffer, WIN_H);
	free(main->raycast);
	free_wall_coord(main);
	exit(0);
}