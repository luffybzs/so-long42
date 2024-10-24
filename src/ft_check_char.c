/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:58:10 by ayarab            #+#    #+#             */
/*   Updated: 2024/10/24 17:32:39 by ayarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_check_data(t_data *data)
{
	data->coin = 0;
	data->exit = 0;
	data->player = 0;
	data->px = 0;
	data->py = 0;
}
int	ft_check_value(t_data *data)
{
	if (data->coin <= 0)
		return (ft_putendl_fd("Error\nNo Collectible", 2), EXIT_FAILURE);
	if (data->exit != 1)
		return (ft_putendl_fd("Error\nNo Exit Or Too Many Exit", 2),
			EXIT_FAILURE);
	if (data->player != 1)
		return (ft_putendl_fd("Error\nNo Player Or Too Many Player", 2),
			EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	ft_check_nb_char(t_data *data, char c)
{
	if (c == 'P')
		data->player++;
	if (c == 'C')
		data->coin++;
	if (c == 'E')
		data->exit++;
	if (c != 'P' && c != 'E' && c != 'C' && c != '1' && c != '0')
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
int	ft_check_all_maps(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->maps[j])
	{
		while (data->maps[j][i])
		{
			if (ft_check_nb_char(data, data->maps[j][i]) == EXIT_FAILURE)
				return (EXIT_FAILURE);
			i++;
		}
		i = 0;
		j++;
	}
	return (EXIT_SUCCESS);
}

int	ft_check_char(t_data *data)
{
	init_check_data(data);
	if (ft_check_all_maps(data) == EXIT_FAILURE)
		return (ft_putendl_fd("Error\nIvalid Char", 2), EXIT_FAILURE);
	if (ft_check_value(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}