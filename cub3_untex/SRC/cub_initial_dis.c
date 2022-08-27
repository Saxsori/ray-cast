/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_initial_dis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 12:45:36 by aaljaber          #+#    #+#             */
/*   Updated: 2022/08/27 05:26:12 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
loop to find the pos
*/
void	find_h_dis(t_cub_main *main)
{
	double	y;

	y = -1.00;
	while (++y <= (double)main->h_num)
	{
		if (main->pos.axis.y < ((y + 1) * GRID) && main->pos.axis.y > (y * GRID))
		{
			main->i_dis.h_up = main->pos.axis.y - (y * GRID);
			main->i_dis.h_down = ((y + 1) * GRID) - main->pos.axis.y;
		}
	}
}

void	find_v_dis(t_cub_main *main)
{
	double	x;

	x = -1.00;
	while (++x <= (double)main->v_num)
	{
		if ((x * GRID) < main->pos.axis.x && ((x + 1) * GRID) > main->pos.axis.x)
		{
			main->i_dis.v_left = main->pos.axis.x - (x * GRID);
			main->i_dis.v_right = ((x + 1) * GRID) - main->pos.axis.x;
		}
	}
}

/*

https://www.desmos.com/calculator/8imkdqdavd

the pos of the player could be any pos 
it could be btwn the gridlines
or on one of the gridline
---> this is just to check if the player pos was btwn
gridlines so we can add the right distance  for the first initial 
gridline hitting 

* >>>> horizontal <<<< *
find where is the pos of the player btwn the horizontal 
lines or on the one of the gridlines
?       (y - 1) < posY && (y + 1) > posY

----- UP
if player was looking up then
? h_initial = posY - (y - 1);
rayY - h_initial;

----- DOWN
if player was looking down then
? h_initial = (y + 1) - posY;
rayY + h_initial;

* >>>> vertical <<<< *
find where is the pos of the player btwn the vertical 
lines or on the one of the gridlines
?       (x - 1) < posX && (x + 1) > posX

----- RIGHT
if player is looking right then 
? v_initial = (x + 1) - posX;
rayX + v_initial;

----- LEFT
if player is looking left then
? v_initial = posX - (x - 1);
rayX - v_initial;

*/
void	find_initial_dis(t_cub_main *main)
{
	find_h_dis(main);
	find_v_dis(main);
}
