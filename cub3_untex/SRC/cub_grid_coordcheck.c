/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_grid_coordcheck.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 17:15:30 by aaljaber          #+#    #+#             */
/*   Updated: 2022/08/27 05:24:36 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	limits(t_ray *raycast)
{
	if ((raycast->ray.x > 0.00 && raycast->ray.y > 0.00))
	{
		if (raycast->ray.x < ((double)raycast->main->v_num) * GRID)
		{
			if (raycast->ray.y < ((double)raycast->main->h_num) * GRID)
				return (1);
		}
	}
	return (0);
}

void	get_fray_dis(t_ray *raycast, int op)
{
	if (op == 'v')
	{
		raycast->v_fcord.x = raycast->ray.x;
		raycast->v_fcord.y = raycast->ray.y;
		raycast->v_fdis = pythg(raycast->main->pos.axis.x, raycast->v_fcord.x, raycast->main->pos.axis.y, raycast->v_fcord.y);
	}
	else if (op == 'h')
	{
		raycast->h_fcord.x = raycast->ray.x;
		raycast->h_fcord.y = raycast->ray.y;
		raycast->h_fdis = pythg(raycast->main->pos.axis.x, raycast->h_fcord.x, raycast->main->pos.axis.y, raycast->h_fcord.y);
	}
}

void	check_loop(t_ray *raycast, int op)
{
	int	i;

	i = -1;
	while (++i < raycast->check_num && limits(raycast))
	{
		if (is_wall(raycast, op))
		{
			get_fray_dis(raycast, op);
			break ;
		}
		else
		{
			raycast->ray.x += raycast->offset.x;
			raycast->ray.y += raycast->offset.y;
		}
	}
	if (!limits(raycast))
		get_fray_dis(raycast, op);
}
