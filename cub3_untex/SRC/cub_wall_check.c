/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_wall_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 20:44:23 by aaljaber          #+#    #+#             */
/*   Updated: 2022/08/07 01:52:16 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*

	// printf("v %d, h %d\n", raycast->main->v_num, raycast->main->h_num);
*/
double	find_wc(t_ray *raycast, int op)
{
	double	i;
	double	e;

	i = -1.00;
	if (op == 'v')
		e = (double)raycast->main->h_num;
	if (op == 'h')
		e = (double)raycast->main->v_num;
	while (++i <= e)
	{
		if (op == 'v')
		{
			if ((i * GRID) < raycast->ray.y && ((i + 1) * GRID) > raycast->ray.y)
				return (i * GRID);
		}
		else if (op == 'h')
		{
			if ((i * GRID) < raycast->ray.x && ((i + 1) * GRID) > raycast->ray.x)
				return (i * GRID);
		}
	}
	return (i * GRID);
}


int	is_doub_coord(t_wall_coord *wc, t_coord coord, int op)
{
	t_wall_coord	*temp;
	int				i;
	int				yes;

	temp = wc;
	while (temp->next)
	{
		i = -1;
		yes = 0;
		while (++i < 4)
		{
			if (op == 'h' && temp->w_c[i].x == coord.x + GRID && temp->w_c[i].y == coord.y)
				yes++;
			else if (op == 'v' && temp->w_c[i].x == coord.x && temp->w_c[i].y == coord.y + GRID)
				yes++;
			if (temp->w_c[i].x == coord.x && temp->w_c[i].y == coord.y)
				yes++;
			if (yes == 2)
				return (1);
		}
		temp = temp->next;
	}
	return (0);
}

/*
		if (is_doub_coord(main->w_coord, main->wc_temp.x, main->wc_temp.y, main->wc_temp.x, main->wc_temp.y + 64.00))
		// printf("x %f, y1 %f, y2 %f\n", raycast->wc_temp.x, raycast->wc_temp.y,raycast->wc_temp.y + 64.00);
		// printf("x1 %f, x2 %f, y %f\n", raycast->wc_temp.x, raycast->wc_temp.x + 64.00, raycast->wc_temp.y);
*/
int	is_wall(t_ray *raycast, int op)
{
	if (op == 'v')
	{
		raycast->wc_temp.x = raycast->ray.x;
		raycast->wc_temp.y = find_wc(raycast, op);
		if (is_doub_coord(raycast->main->w_coord, raycast->wc_temp, op))
			return (1);
		else
			return (0);
	}
	else if (op == 'h')
	{
		raycast->wc_temp.y = raycast->ray.y;
		raycast->wc_temp.x = find_wc(raycast, op);
		if (is_doub_coord(raycast->main->w_coord, raycast->wc_temp, op))
			return (1);
		else
			return (0);
	}
	return (0);
}