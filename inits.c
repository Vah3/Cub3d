/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagevorg <vagevorg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:56:45 by vagevorg          #+#    #+#             */
/*   Updated: 2023/01/18 16:34:23 by vagevorg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alg_header.h"

extern char	**g_map;

int	init_images34(t_player_set *player)
{
	player->img.img3.image = mlx_xpm_file_to_image(player->d_mlx.mlx,
			player->img.img3.path_to_image, &player->img.img3.img_height,
			&player->img.img3.img_len);
	if (player->img.img3.image == NULL)
		return (1);
	player->img.img3.addr = mlx_get_data_addr(player->img.img3.image,
			&player->img.img3.bpp, &player->img.img3.size_line,
			&player->img.img3.endian);
	player->img.img4.image = mlx_xpm_file_to_image(player->d_mlx.mlx,
			player->img.img4.path_to_image, &player->img.img4.img_height,
			&player->img.img4.img_len);
	if (player->img.img4.image == NULL)
		return (1);
	player->img.img4.addr = mlx_get_data_addr(player->img.img4.image,
			&player->img.img4.bpp, &player->img.img4.size_line,
			&player->img.img4.endian);
	return (0);
}

int	init_images(t_player_set *player)
{
	player->img.img1.image = mlx_xpm_file_to_image(player->d_mlx.mlx,
			player->img.img1.path_to_image,
			&player->img.img1.img_height, &player->img.img1.img_len);
	if (player->img.img1.image == NULL)
		return (1);
	player->img.img1.addr = mlx_get_data_addr(player->img.img1.image,
			&player->img.img1.bpp, &player->img.img1.size_line,
			&player->img.img1.endian);
	player->img.img2.image = mlx_xpm_file_to_image(player->d_mlx.mlx,
			player->img.img2.path_to_image, &player->img.img2.img_height,
			&player->img.img2.img_len);
	if (player->img.img2.image == NULL)
		return (1);
	player->img.img2.addr = mlx_get_data_addr(player->img.img2.image,
			&player->img.img2.bpp, &player->img.img2.size_line,
			&player->img.img2.endian);
	if (init_images34(player))
		return (1);
	return (0);
}

int	init_mlx(t_player_set *player)
{
	player->d_mlx.mlx = mlx_init();
	if (player->d_mlx.mlx == NULL)
		return (1);
	player->d_mlx.win = mlx_new_window(player->d_mlx.mlx, WIDTH, HEIGHT, "cub");
	if (player->d_mlx.win == NULL)
		return (1);
	player->gen_img.image = mlx_new_image(player->d_mlx.mlx, WIDTH, HEIGHT);
	if (player->gen_img.image == NULL)
		return (1);
	player->gen_img.addr = mlx_get_data_addr(player->gen_img.image,
			&player->gen_img.bpp, &player->gen_img.size_line,
			&player->gen_img.endian);
	if (player->gen_img.addr == NULL)
		return (1);
	return (0);
}

int	inits(t_player_set *player)
{
	player->pos_x = player->game.player.y;
	player->pos_y = player->game.player.x;
	player->face_to = player->game.player.face_to;
	player->img.img1.path_to_image = player->game.directions.east.path_to_xpm;
	player->img.img2.path_to_image = player->game.directions.west.path_to_xpm;
	player->img.img3.path_to_image = player->game.directions.north.path_to_xpm;
	player->img.img4.path_to_image = player->game.directions.south.path_to_xpm;
	g_map = player->game.map;
	if (init_mlx(player))
	{
		ft_putstr_fd_color("mlx_error\n", 2, RED);
		clear_struct(&player->game);
		return (1);
	}
	init_player(player);
	if (init_images(player))
	{
		clear_struct(&player->game);
		ft_putstr_fd_color("There is invalid file\n", 2, RED);
		return (1);
	}
	return (0);
}
