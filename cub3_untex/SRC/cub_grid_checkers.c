/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_grid_checkers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 14:51:55 by aaljaber          #+#    #+#             */
/*   Updated: 2022/08/27 05:49:45 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_offset(t_ray *ray, int op)
{
	if (op == UP)
	{
		ray->offset.y = -GRID;
		ray->offset.x = -(ray->offset.y) * ray->_tan;
		ray->dir = UP;
	}
	else if (op == DOWN)
	{
		ray->offset.y = GRID;
		ray->offset.x = -(ray->offset.y) * ray->_tan;
		ray->dir = DOWN;
	}
	else if (op == LEFT)
	{
		ray->offset.x = -GRID;
		ray->offset.y = -(ray->offset.x) * ray->_tan;
		ray->dir = LEFT;
	}
	else if (op == RIGHT)
	{
		ray->offset.x = GRID;
		ray->offset.y = -(ray->offset.x) * ray->_tan;
		ray->dir = RIGHT;
	}
}

void	vertical_checker(t_ray *raycast)
{
	raycast->_tan = -tan(raycast->a);
	if (raycast->a > PIH && raycast->a < PIT)
	{
		raycast->ray.x = ((raycast->main->pos.axis.x / GRID) * GRID) - (raycast->main->i_dis.v_left);
		raycast->ray.y = ((raycast->main->pos.axis.x - raycast->ray.x) * raycast->_tan) + raycast->main->pos.axis.y;
		raycast->check_num = raycast->main->v_num;
		set_offset(raycast, LEFT);
	}
	else if (raycast->a < PIH || raycast->a > PIT)
	{
		raycast->ray.x = ((raycast->main->pos.axis.x / GRID) * GRID) + (raycast->main->i_dis.v_right);
		raycast->ray.y = (raycast->main->pos.axis.x - raycast->ray.x) * raycast->_tan + raycast->main->pos.axis.y;
		raycast->check_num = raycast->main->v_num;
		set_offset(raycast, RIGHT);
	}
	else if (raycast->a == PI || raycast->a == 0)
	{
		raycast->ray.x = raycast->main->pos.axis.x;
		raycast->ray.y = raycast->main->pos.axis.y;
		raycast->check_num = -2;
		raycast->dir = UD;
	}
	check_loop(raycast, 'v');
}

void	horizontal_checker(t_ray *raycast)
{
	raycast->_tan = -1 / tan(raycast->a);
	if (raycast->a > PI)
	{
		raycast->ray.y = ((raycast->main->pos.axis.y / GRID) * GRID) - (raycast->main->i_dis.h_up);
		raycast->ray.x = (raycast->main->pos.axis.y - raycast->ray.y) * raycast->_tan + raycast->main->pos.axis.x;
		raycast->check_num = raycast->main->h_num;
		set_offset(raycast, UP);
	}
	else if (raycast->a < PI)
	{
		raycast->ray.y = ((raycast->main->pos.axis.y / GRID) * GRID) + (raycast->main->i_dis.h_down);
		raycast->ray.x = (raycast->main->pos.axis.y - raycast->ray.y) * raycast->_tan + raycast->main->pos.axis.x;
		raycast->check_num = raycast->main->h_num;
		set_offset(raycast, DOWN);
	}
	else if (raycast->a == PI || raycast->a == 0)
	{
		raycast->ray.x = raycast->main->pos.axis.x;
		raycast->ray.y = raycast->main->pos.axis.y;
		raycast->check_num = -2;
		raycast->dir = LR;
	}
	check_loop(raycast, 'h');
}


void	get_fray_coord(t_ray *raycast, int op)
{
	if (op == 'v')
	{
		if (raycast->v_fcord.x > 0.00 && raycast->v_fcord.y > 0.00)
		{
			raycast->ray.x = raycast->v_fcord.x;
			raycast->ray.y = raycast->v_fcord.y;
		}
		else
		{
			raycast->ray.x = raycast->h_fcord.x;
			raycast->ray.y = raycast->h_fcord.y;
		}
	}
	else if (op == 'h')
	{
		if (raycast->h_fcord.x > 0.00 && raycast->h_fcord.y > 0.00)
		{
			raycast->ray.x = raycast->h_fcord.x;
			raycast->ray.y = raycast->h_fcord.y;
		}
		else
		{
			raycast->ray.x = raycast->v_fcord.x;
			raycast->ray.y = raycast->v_fcord.y;
		}
	}
}

