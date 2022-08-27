/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 05:45:57 by aaljaber          #+#    #+#             */
/*   Updated: 2022/08/27 06:03:44 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
the height of the map
->> the number of the lines
->>>> the number of the horizontal lines

the width of the map
->> the number of the char in the line
->>>> the number of the vertical lines
*/
void	init_ray(t_cub_main *main, t_ray *raycast, double r_angle)
{
	raycast->main = main;
	raycast->a = deg_rad(lmt_angle(r_angle));
	raycast->ray.x = -1.00;
	raycast->ray.y = -1.00;
	raycast->offset.x = -1.00;
	raycast->offset.y = -1.00;
	raycast->num = 0;
	raycast->_tan = 0.00;
	raycast->v_fcord.x = 0.00;
	raycast->v_fcord.y = 0.00;
	raycast->v_fdis = 0.00;
	raycast->h_fcord.y = 0.00;
	raycast->h_fcord.x = 0.00;
	raycast->h_fdis = 0.00;
	raycast->check_num = -2;
	raycast->wc_temp.x = 0.00;
	raycast->wc_temp.y = 0.00;
	raycast->f_dis = 0.00;
	raycast->h_line = 0.00;
	raycast->h_offset = 0.00;
	raycast->dir = 0;
}

/*
		// printf("%f\n", (main->pos.vctr.a - ((double)main->fov / 2.00)) + (double)i);
	// init_ray(main, &main->raycast[0], main->pos.vctr.a);
	// main->raycast = (t_ray *)malloc(sizeof(t_ray) * main->fov);
		// init_ray(main, &main->raycast[i], (main->pos.vctr.a - ((double)main->fov / 2.00)) + (double)i);
		// printf("angle %f\n", (main->pos.vctr.a - ((double)main->fov / 2.00)) + (double)i);
		printf("angle %f\n", main->angle);
*/
void	info_ray(t_cub_main *main)
{
	int	i;

	main->fov = 60;
	main->n_rays = WIN_W;
	main->angle = main->pos.vctr.a - ((double)main->fov / 2.00);
	main->raycast = (t_ray *)malloc(sizeof(t_ray) * main->n_rays);
	i = -1;
	while (++i < main->n_rays)
	{
		init_ray(main, &main->raycast[i], main->angle);
		main->angle += (main->fov / (double)main->n_rays);
	}
}

void	init_buf(t_cub_main *main)
{
	int	i;
	int	k;

	i = -1;
	while (++i < WIN_H)
	{
		k = -1;
		while (++k < WIN_W)
			main->buffer[i][k] = 0;
	}
	main->re_buf = 0;
}

/*
fov is the feild of vision 
*/
void	init_cub(t_cub_main *main)
{
	int	i;

	main->h_num = main->m_info.size.height;
	main->v_num = check_big_width(main);
	main->x_info.mlx = mlx_init();
	main->x_info.window = mlx_new_window(main->x_info.mlx, WIN_W, WIN_H, "Ray-Cast");
	main->buffer = (unsigned int **)malloc(WIN_H * sizeof(unsigned int *));
	i = -1;
	while (++i < WIN_H)
		main->buffer[i] = (unsigned int *)malloc(WIN_W * sizeof(unsigned int));
	init_buf(main);
	main->image = mlx_new_image(main->x_info.mlx, WIN_W, WIN_H);
	main->data = (int *)mlx_get_data_addr(main->image, &main->bits, &main->lines, &main->endian);
	main->x_info.height = 0;
	main->x_info.width = 0;
	main->pos.axis.x = 100.00;
	main->pos.axis.y = 220.00;
	main->pos.vctr.a = 280.00;
	main->pos.vctr.x = cos(deg_rad(280.00));
	main->pos.vctr.y = -sin(deg_rad(280.00));
	main->i_dis.h_down = 0.00;
	main->i_dis.h_up = 0.00;
	main->i_dis.v_left = 0.00;
	main->i_dis.v_right = 0.00;
	find_initial_dis(main);
	info_ray(main);
}

/*
! this could be used for the map parser but for
! now this is the initial set-up including the plyr-pos
*/
void	init_map(t_map *main)
{
	main->map = NULL;
	main->ply_pos.x = -1;
	main->ply_pos.y = -1;
	main->size.height = 0;
	main->size.width = 0;
	main->fd = open(main->m_name, O_RDONLY);
}

void	info_map(t_cub_main *main, char *cub_name)
{
	main->m_info.m_name = ft_strdup(cub_name);
	init_map(&main->m_info);
	get_map(&main->m_info);
}
