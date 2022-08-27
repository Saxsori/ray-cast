/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 13:32:46 by aaljaber          #+#    #+#             */
/*   Updated: 2022/08/27 05:48:00 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/***************************** INCLUDES *************************************/
# include	<stdio.h>
# include	<stdlib.h>
# include	<math.h>
# include	"./LIB/key_macos.h"
# include	"./LIB/GNL/get_next_line.h"
# include	"./LIB/LIBFT/libft.h"
# include	"./MLX/mlx.h"
/***************************** ANGLES *************************************/
# define PI 3.14159265359
# define PIH 1.57079632679
# define PIT 4.71238898038

/***************************** FLAGES *************************************/
# define RIGHT 82
# define LEFT 76
# define UP 85
# define DOWN 68
# define UD 50
# define LR 60
# define N 0
# define S 1
# define W 2
# define E 3
# define H 8
# define V 10

/***************************** SIZE *************************************/
# define GRID 64.00
# define WIN_H	512
# define WIN_W	640
# define IMG_SIZE	64


typedef struct wall_coord	t_wall_coord;
typedef struct cub_main		t_cub_main;

typedef struct coord
{
	double	x;
	double	y;
}	t_coord;

typedef struct wall_coord
{
	t_coord			*w_c;
	t_wall_coord	*next;
}	t_wall_coord;

typedef struct vector
{
	double	a;
	double	x;
	double	y;
}	t_vctr;

typedef struct size
{
	int	width;
	int	height;
}	t_size;

typedef struct pos
{
	t_coord	axis;
	t_vctr	vctr;
}	t_pos;

typedef struct mlx
{
	void	*window;
	void	*mlx;
	void	*width;
	void	*height;
}	t_mlx;

typedef struct map
{
	char	**map;
	t_coord	ply_pos;
	t_size	size;
	char	*m_name;
	int		fd;
	int		*map_dimn;
}	t_map;

typedef struct img
{
	t_size	size;
	void	*floor;
	void	*wall;
	void	*player;
}	t_img;

typedef struct initial
{
	double	h_up;
	double	h_down;
	double	v_right;
	double	v_left;
}	t_idis;

typedef struct ray
{
	double		a;
	int			num;
	t_coord		ray;
	t_coord		offset;
	double		_tan;
	t_coord		h_fcord;
	t_coord		v_fcord;
	double		h_fdis;
	double		v_fdis;
	t_cub_main	*main;
	int			check_num;
	t_coord		wc_temp;
	double		f_dis;
	double		h_line;
	double		h_offset;
	int			dir;
	double		draw_end;
	double		draw_start;
}	t_ray;

typedef struct cub_main
{
	t_mlx			x_info;
	t_map			m_info;
	t_wall_coord	*w_coord;
	t_pos			pos;
	int				fov;
	t_ray			*raycast;
	int				h_num;
	int				v_num;
	t_img			img;
	t_idis			i_dis;
	void			*image;
	int				*data;
	unsigned int	**buffer;
	int				re_buf;
	int				bits;
	int				lines;
	int				endian;
	int				n_rays;
	double			angle;
	int				height;
	int				width;
}	t_cub_main;


/*
! FREE LIST
--> map name in main->m_info.m_name
--> map dimn 
--> map
*/

/*
! THiNGS to NoTe
--> handle the new line for map and map_dimn
*/

/******************** INIT & INFO ********************/
void			info_map(t_cub_main *main, char *cub_name);
void			init_map(t_map *main);
void			init_cub(t_cub_main *main);
void			init_buf(t_cub_main *main);
int				endgame(void *param);

/********************     MATH    ********************/
double			deg_rad(double a);
double			pythg(double x1, double x2, double y1, double y2);
double			lmt_angle(double a);
double			rad_deg(int a);

/**********************     MAP      ***********************/
void			get_height(t_map *m_info);
void			get_map(t_map *m_info);
char			*no_newline(char *line);
void			print_map(t_map *m_info);

/*********************** PLAYER MOVE ***********************/
int				move(int key, void *param);
void			move_player(t_cub_main *main);

/*********************** RAYCAST TOOLS **********************/
int				check_big_width(t_cub_main *main);
void			find_h_dis(t_cub_main *main);
void			find_v_dis(t_cub_main *main);
void			find_initial_dis(t_cub_main *main);

/********************** GRIDLINE CHECK *********************/
void			check_gridline(t_ray *raycast);
int				limits(t_ray *raycast);
void			get_fray_dis(t_ray *raycast, int op);
void			check_loop(t_ray *raycast, int op);
void			set_offset(t_ray *ray, int op);
void			vertical_checker(t_ray *raycast);
void			horizontal_checker(t_ray *raycast);
void			get_fray_coord(t_ray *raycast, int op);

/***************** ًGET WALL & CHECK WALL ******************/
t_wall_coord	*create_node(void);
t_wall_coord	*add_wall_coord(t_wall_coord *w_coord, double x, double y);
void			get_wall_coord(t_cub_main *main);
void			print_wcoord(t_wall_coord *w_coord);
void			take_wall_coord(t_wall_coord *w_coord, double x, double y);
int				is_wall(t_ray *raycast, int op);
int				is_doub_coord(t_wall_coord *wc, t_coord coord, int op);
double			find_wc(t_ray *raycast, int op);

/********************** ً  RAYCAST   ************************/
void			start_raycast(t_cub_main *main);

#endif