/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 05:40:38 by aaljaber          #+#    #+#             */
/*   Updated: 2022/11/20 04:40:29 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	main(int argc, char **argv)
{
	t_cub_main	main;

	if (argc == 2)
	{
		info_map(&main, argv[1]);
		get_wall_coord(&main);
		init_cub(&main);
		start_raycast(&main);
		mlx_hook(main.x_info.window, 2, 0, &move, &main.x_info);
		mlx_hook(main.x_info.window, 17, 1L << 17, &endgame, &main);
		mlx_loop(main.x_info.mlx);
	}
}
