/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 22:25:31 by aaljaber          #+#    #+#             */
/*   Updated: 2022/08/27 06:08:01 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*

	// while (++i < main->n_rays/*main->fov)
		// main->raycast[i].a = deg_rad(lmt_angle((main->pos.vctr.a - ((double)main->fov / 2.00)) + (double)i));
*/
void	move_player(t_cub_main *main)
{
	int	i;

	i = -1;
	main->angle = main->pos.vctr.a - ((double)main->fov / 2.00);
	while (++i < main->n_rays)
	{
		main->raycast[i].a = deg_rad(lmt_angle(main->angle));
		main->angle += (main->fov / (double)main->n_rays);
	}
	mlx_clear_window(main->x_info.mlx, main->x_info.window);
	start_raycast(main);
}

int	move(int key, void *param)
{
	t_cub_main	*main;

	main = (t_cub_main *) param;
	if (key == K_W)
	{
		main->pos.axis.y += (main->pos.vctr.y * 5);
		main->pos.axis.x += (main->pos.vctr.x * 5);
	}
	else if (key == K_S)
	{
		main->pos.axis.y -= (main->pos.vctr.y * 5);
		main->pos.axis.x -= (main->pos.vctr.x * 5);
	}
	else if (key == K_AR_R)
	{
		main->pos.vctr.a -= 1;
		main->pos.vctr.a = lmt_angle(main->pos.vctr.a);
		main->pos.vctr.x = cos(deg_rad(main->pos.vctr.a));
		main->pos.vctr.y = -sin(deg_rad(main->pos.vctr.a));
	}
	else if (key == K_AR_L)
	{
		main->pos.vctr.a += 1;
		main->pos.vctr.a = lmt_angle(main->pos.vctr.a);
		main->pos.vctr.x = cos(deg_rad(main->pos.vctr.a));
		main->pos.vctr.y = -sin(deg_rad(main->pos.vctr.a));
	}
	else if (key == K_A)
	{
		main->pos.axis.y += (main->pos.vctr.y * 5);
		main->pos.axis.x += (main->pos.vctr.x * 5) - 5;
	}
	else if (key == K_D)
	{
		main->pos.axis.y += (main->pos.vctr.y * 5);
		main->pos.axis.x += (main->pos.vctr.x * 5) + 5;
	}
	if (key == K_ESC)
		endgame(main);
	find_initial_dis(main);
	move_player(main);
	return (0);
}
