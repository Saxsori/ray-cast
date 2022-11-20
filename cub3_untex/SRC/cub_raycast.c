/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_raycast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 12:36:23 by aaljaber          #+#    #+#             */
/*   Updated: 2022/11/20 04:07:35 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_gridline(t_ray *raycast)
{
	horizontal_checker(raycast);
	vertical_checker(raycast);
	if (raycast->v_fdis < raycast->h_fdis)
		get_fray_coord(raycast, 'v');
	else if (raycast->v_fdis > raycast->h_fdis)
		get_fray_coord(raycast, 'h');
	raycast->f_dis = pythg(raycast->main->pos.axis.x, raycast->ray.x, raycast->main->pos.axis.y, raycast->ray.y);
}

/*
// 	// draw_line(raycast->main, &raycast->line);
// 	// r = (r > deg_rad(359.00)) ? r -= deg_rad(360.00) : deg_rad(360.00);
// 	// r = (r < deg_rad(0.00)) ? r += deg_rad(360.00) : deg_rad(0.00);
// 		// raycast->main->buffer[(int)(y + raycast->h_offset + (raycast->main->h_num * GRID))][(int)(i * (raycast->main->v_num + 1))] = 0x8545e6;
// 	//***********************************************************************
// 	raycast->h_offset = (WIN_H / 2.00) - (raycast->h_line / 2.00);
// 	// raycast->line.begin.x = i /* (raycast->main->v_num + 1)) + (raycast->main->v_num * 64.00);
// 	// raycast->line.begin.y = raycast->h_offset + (raycast->main->h_num * GRID);
// 	// raycast->line.end.x = i /* (raycast->main->v_num + 1)) /*+ (raycast->main->v_num * 64.00);
// 	// raycast->line.end.y = raycast->h_offset + ((raycast->main->h_num * GRID)) + raycast->h_line;
// 	// if ((int)raycast->line.end.x > raycast->main->width)
// 		// raycast->line.end.x = (double)raycast->main->width;
// 	// if ((int)raycast->line.end.y > raycast->main->height)
// 		// raycast->line.end.y = (double)raycast->main->height;
// 	// y = -1;
*/
void	do_raycast(t_ray *raycast, int x)
{
	double	r;
	int		y;
	int		end;
	int		begin;
	char	*dst;

	r = deg_rad(raycast->main->pos.vctr.a) - raycast->a;
	if (r > deg_rad(359.00))
		r -= deg_rad(360.00);
	else if (r < deg_rad(0.00))
		r += deg_rad(360.00);
	raycast->f_dis = raycast->f_dis * cos(r);
	raycast->h_line = (int)(GRID * (1.00 * WIN_H)) / raycast->f_dis;
	begin = (WIN_H / 2) - (int)(raycast->h_line / 2.00);
	if (begin < 0)
		begin = 0;
	end = (WIN_H / 2) + (int)(raycast->h_line / 2.00);
	if (end >= WIN_H)
		end = WIN_H - 1;
	y = (begin - 1);
	while (++y < end)
	{
		if ((y > -1 && y < WIN_H) && (x > -1 && x < WIN_W))
			raycast->main->buffer[y][x] = 0x8545e6;
		raycast->main->re_buf = 1;
	}
}

void	start_raycast(t_cub_main *main)
{
	int	i;
	int	k;

	i = -1;
	if (main->re_buf)
		init_buf(main);
	while (++i < main->n_rays)
	{
		check_gridline(&main->raycast[i]);
		do_raycast(&main->raycast[i], i);
	}
	i = -1;
	while (++i < WIN_H)
	{
		k = -1;
		while (++k < WIN_W)
			main->data[i * WIN_W + k] = main->buffer[i][k];
	}
	mlx_put_image_to_window(main->x_info.mlx, main->x_info.window, main->image, 0, 0);
}
