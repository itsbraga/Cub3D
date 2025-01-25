/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:31:53 by pmateo            #+#    #+#             */
/*   Updated: 2025/01/25 18:19:11 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

/******************************************************************************\
 * CUB3D
\******************************************************************************/

typedef struct s_point
{
	float	x;
	float	y;
}				t_point;

typedef struct s_map
{
	char		**map2d;
	size_t		M_HEIGHT; // MAP
	size_t		M_WIDTH; 
	size_t		T_HEIGHT; // TILES
	size_t		T_WIDTH;
}				t_map;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*img_buff;
	int			bpp;
	int			line_len;
	int			endian;
}				t_mlx;

typedef struct s_ray
{
	t_point			ray_inter;
	t_point			offset;
	unsigned int	fov;
}				t_ray;

typedef struct s_data
{
	char			*map_path;
	t_map			*map;
	t_ray			*ray;
	char			texture[4];
	unsigned int	f_rgb[3];
	unsigned int	c_rgb[3];
	t_point			player;
	int				player_dir;
	t_mlx			*mlx;
}				t_data;

/******************************************************************************\
 * YAMA: Garbage collector
\******************************************************************************/

typedef struct s_gc_lst
{
	void			*ptr;
	bool			is_tab;
	struct s_gc_lst	*next;
}				t_gc_lst;

#endif