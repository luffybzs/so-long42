/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:53:55 by ayarab            #+#    #+#             */
/*   Updated: 2024/10/23 18:59:42 by ayarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_tab(t_data *data)
{
	int	line1;
	int	line2;
	int	j;

	j = 0;
	line1 = ft_strlen(data->maps[j]);
	while (data->maps[j])
	{
		line2 = ft_strlen(data->maps[j]);
		if (line1 != line2)
			return (EXIT_FAILURE);
		j++;
	}
	return (EXIT_SUCCESS);
}
int	ft_check_verif_line(t_data *data, int pos)
{
	int	i;

	i = 0;
	while (data->maps[pos][i])
	{
		if (data->maps[pos][i] != '1')
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}
int	ft_check_verif_vertical(t_data *data)
{
	int	i;

	i = 0;
	while (data->maps[i])
	{
		if (data->maps[i][0] != '1')
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}
int	ft_check_last_vertical(t_data *data)
{
	int	i;
	int	len;

	i = 0;
	while (data->maps[i])
	{
		len = ft_strlen(data->maps[i]);
		len -= 1;
		if (data->maps[i][len] != '1')
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	ft_check_wall(t_data *data)
{
	int	pos;

	pos = 0;
	if (ft_check_tab(data) == EXIT_FAILURE)
		return (ft_putendl_fd("Error\nMap Not Rectangle", 2), EXIT_FAILURE);
	if (ft_check_verif_line(data, pos) == EXIT_FAILURE)
		return (ft_putendl_fd("Error\nWall Not Close", 2), EXIT_FAILURE);
	pos = ft_strlen_2d(data->maps);
	pos -= 1;
	if (ft_check_verif_line(data, pos) == EXIT_FAILURE)
		return (ft_putendl_fd("Error\nWall Not Close", 2), EXIT_FAILURE);
	if (ft_check_verif_vertical(data) == EXIT_FAILURE)
		return (ft_putendl_fd("Error\nWall Not Close", 2), EXIT_FAILURE);
	if (ft_check_last_vertical(data) == EXIT_FAILURE)
		return (ft_putendl_fd("Error\nWall Not Close", 2), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
