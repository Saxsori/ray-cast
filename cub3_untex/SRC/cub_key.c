/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 22:25:31 by aaljaber          #+#    #+#             */
/*   Updated: 2022/11/20 04:09:44 by aaljaber         ###   ########.fr       */
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

void	move_forward_backward(t_cub_main *main, t_coord *next_pos, int op)
{
	if (op == 'f')
	{
		next_pos->x += (cos(deg_rad(main->pos.vctr.a)) * STEP_SIZE);
		next_pos->y += (sin(deg_rad(main->pos.vctr.a)) * STEP_SIZE);
	}
	else if (op == 'b')
	{
		next_pos->x -= (cos(deg_rad(main->pos.vctr.a)) * STEP_SIZE);
		next_pos->y -= (sin(deg_rad(main->pos.vctr.a)) * STEP_SIZE);
	}
}

void	rotate_dir(t_cub_main *main, int op)
{
	if (op == 'r')
	{
		main->pos.vctr.a += ROTATION_ANGLE;
		main->pos.vctr.a = lmt_angle(main->pos.vctr.a);
	}
	else if (op == 'l')
	{
		main->pos.vctr.a -= ROTATION_ANGLE;
		main->pos.vctr.a = lmt_angle(main->pos.vctr.a);
	}
}

/*
* first two quadrants 
! 1st quad: cos+ sin+
! 2nd quad: cos- sin+
*/
void	move_left_firstquadrants(t_cub_main *main, t_coord *next_pos)
{
	if (main->pos.vctr.a >= 0.00 && main->pos.vctr.a <= 90.00)
	{
		if (cos(deg_rad(main->pos.vctr.a)) * STEP_SIZE > \
		sin(deg_rad(main->pos.vctr.a)) * STEP_SIZE)
			next_pos->y -= (cos(deg_rad(main->pos.vctr.a)) * STEP_SIZE);
		else
			next_pos->x += (sin(deg_rad(main->pos.vctr.a)) * STEP_SIZE);
	}
	if (main->pos.vctr.a >= 90.00 && main->pos.vctr.a <= 180.00)
	{
		if (sin(deg_rad(main->pos.vctr.a)) * STEP_SIZE > (STEP_SIZE / 2.00) \
		|| sin(deg_rad(main->pos.vctr.a)) * STEP_SIZE < -(STEP_SIZE / 2.00))
			next_pos->x += (sin(deg_rad(main->pos.vctr.a)) * STEP_SIZE);
		else
			next_pos->y -= (cos(deg_rad(main->pos.vctr.a)) * STEP_SIZE);
	}
}

/*
* second two quadrants 
! 3rd quad: cos- sin-
! 4th quad: cos+ sin-
*/
void	move_left_secondquadrants(t_cub_main *main, t_coord *next_pos)
{
	if (main->pos.vctr.a >= 180.00 && main->pos.vctr.a <= 270.00)
	{
		if (cos(deg_rad(main->pos.vctr.a)) * STEP_SIZE < \
		sin(deg_rad(main->pos.vctr.a)) * STEP_SIZE)
			next_pos->y -= (cos(deg_rad(main->pos.vctr.a)) * STEP_SIZE);
		else
			next_pos->x += (sin(deg_rad(main->pos.vctr.a)) * STEP_SIZE);
	}
	if (main->pos.vctr.a >= 270 && main->pos.vctr.a <= 360.00)
	{
		if (sin(deg_rad(main->pos.vctr.a)) * STEP_SIZE > (STEP_SIZE / 2.00) \
		|| sin(deg_rad(main->pos.vctr.a)) * STEP_SIZE < -(STEP_SIZE / 2.00))
			next_pos->x += (sin(deg_rad(main->pos.vctr.a)) * STEP_SIZE);
		else
			next_pos->y -= (cos(deg_rad(main->pos.vctr.a)) * STEP_SIZE);
	}
}

/*
* first two quadrants 
! 1st quad: cos+ sin+
! 2nd quad: cos- sin+
*/
void	move_right_firstquadrants(t_cub_main *main, t_coord *next_pos)
{
	if (main->pos.vctr.a >= 0.00 && main->pos.vctr.a <= 90.00)
	{
		if (cos(deg_rad(main->pos.vctr.a)) * STEP_SIZE > \
		sin(deg_rad(main->pos.vctr.a)) * STEP_SIZE)
			next_pos->y += (cos(deg_rad(main->pos.vctr.a)) * STEP_SIZE);
		else
			next_pos->x -= (sin(deg_rad(main->pos.vctr.a)) * STEP_SIZE);
	}
	if (main->pos.vctr.a >= 90.00 && main->pos.vctr.a <= 180.00)
	{
		if (sin(deg_rad(main->pos.vctr.a)) * STEP_SIZE > (STEP_SIZE / 2.00) \
		|| sin(deg_rad(main->pos.vctr.a)) * STEP_SIZE < -(STEP_SIZE / 2.00))
			next_pos->x -= (sin(deg_rad(main->pos.vctr.a)) * STEP_SIZE);
		else
			next_pos->y += (cos(deg_rad(main->pos.vctr.a)) * STEP_SIZE);
	}	
}

/*
* second two quadrants 
! 3rd quad: cos- sin-
! 4th quad: cos+ sin-
*/
void	move_right_secondquadrants(t_cub_main *main, t_coord *next_pos)
{
	if (main->pos.vctr.a >= 180.00 && main->pos.vctr.a <= 270.00)
	{
		if (cos(deg_rad(main->pos.vctr.a)) * STEP_SIZE < \
		sin(deg_rad(main->pos.vctr.a)) * STEP_SIZE)
			next_pos->y += (cos(deg_rad(main->pos.vctr.a)) * STEP_SIZE);
		else
			next_pos->x -= (sin(deg_rad(main->pos.vctr.a)) * STEP_SIZE);
	}
	if (main->pos.vctr.a >= 270.00 && main->pos.vctr.a <= 360.00)
	{
		if (sin(deg_rad(main->pos.vctr.a)) * STEP_SIZE > (STEP_SIZE / 2.00) \
		|| sin(deg_rad(main->pos.vctr.a)) * STEP_SIZE < -(STEP_SIZE / 2.00))
			next_pos->x -= (sin(deg_rad(main->pos.vctr.a)) * STEP_SIZE);
		else
			next_pos->y += (cos(deg_rad(main->pos.vctr.a)) * STEP_SIZE);
	}
}

void	move_left_right(t_cub_main *main, t_coord *next_pos, int op)
{
	if (op == 'l')
	{
		move_left_firstquadrants(main, next_pos);
		move_left_secondquadrants(main, next_pos);
	}
	else if (op == 'r')
	{
		move_right_firstquadrants(main, next_pos);
		move_right_secondquadrants(main, next_pos);
	}
}

void	check_if_wall(t_cub_main *main, t_coord *next_pos)
{
	if (main->m_info.map[(int)(next_pos->y / 64.00)] \
	[(int)(next_pos->x / 64.00)] != '1')
	{
		main->pos.axis.x = next_pos->x;
		main->pos.axis.y = next_pos->y;
	}
}

int	move(int key, void *param)
{
	t_cub_main	*main;
	t_coord		next_pos;

	main = (t_cub_main *) param;
	next_pos.x = main->pos.axis.x;
	next_pos.y = main->pos.axis.y;
	if (key == K_W)
		move_forward_backward(main, &next_pos, 'f');
	else if (key == K_S)
		move_forward_backward(main, &next_pos, 'b');
	else if (key == K_AR_R)
		rotate_dir(main, 'r');
	else if (key == K_AR_L)
		rotate_dir(main, 'l');
	else if (key == K_A)
		move_left_right(main, &next_pos, 'l');
	else if (key == K_D)
		move_left_right(main, &next_pos, 'r');
	if (key == K_ESC)
		endgame(main);
	check_if_wall(main, &next_pos);
	find_initial_dis(main);
	move_player(main);
	return (0);
}
