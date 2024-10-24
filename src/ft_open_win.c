/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_win.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:01:54 by ayarab            #+#    #+#             */
/*   Updated: 2024/10/24 21:03:42 by ayarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_data_len(t_data *data)
{
	data->lx = ft_strlen(data->maps[0]);
	data->ly = ft_strlen_2d(data->maps);
}
int ft_init_img(t_data *data)
{
	data->mlx_luffy = mlx_xpm_file_to_image()
	
}
int ft_display_img(t_data *data)
{
	return (EXIT_SUCCESS);
}

int	ft_open_window(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (EXIT_FAILURE);
	data->mlx_win = mlx_new_window(data->mlx, data->lx * SIZE, data->ly * SIZE,
			"so_long");
	mlx_loop(data->mlx);
	mlx_put_image_to_window(data->mlx, data->mlx_win,  ,data->lx * SIZE, data->ly * SIZE);
	
	return (EXIT_SUCCESS);
}

int ft_start_mlx(t_data *data)
{
	fill_data_len(data);
	if (ft_open_window(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}