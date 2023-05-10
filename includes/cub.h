/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:06:34 by graux             #+#    #+#             */
/*   Updated: 2023/05/10 18:48:43 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# define WIN_W 1280
# define WIN_H 720

# define FOV 1.0472
# define NB_RAYS 60

typedef struct s_frame
{
	void	*img;
	char	*address;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_frame;

enum e_map_dir
{
	NO,
	SO,
	WE,
	EA
};

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}			t_color;

typedef struct s_vec2f
{
	double	x;
	double	y;
}			t_vec2f;

typedef struct s_vec2i
{
	int	x;
	int	y;
}			t_vec2i;

typedef struct s_mat2x2
{
	double	elem1_1;
	double	elem1_2;
	double	elem2_1;
	double	elem2_2;
}			t_mat2x2;

typedef struct s_player
{
	t_vec2f		pos;	 // (5 * 32, 7 * 32)
	t_vec2i		pos_map; // (5, 7)
	t_vec2f		dir;
	t_mat2x2	m_rotations[NB_RAYS];
	t_vec2f		rays[NB_RAYS]; //TODO change to something smaller?
}			t_player;

typedef struct s_map
{
	t_color		f_color;
	t_color		c_color;
	t_frame		textures[4];
	t_player	player;
	t_vec2i		map_size;
}			t_map;

typedef struct s_gui
{
	void	*mlx;
	void	*mlx_win;
	t_frame	*screen;
}			t_gui;

int	map_load(t_map *map, char *map_path);

#endif
