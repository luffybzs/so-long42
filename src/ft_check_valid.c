/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:14:58 by ayarab            #+#    #+#             */
/*   Updated: 2024/10/24 17:54:38 by ayarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_pos_player(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (data->maps[j])
	{
		i = 0;
		while (data->maps[j][i])
		{
			if (data->maps[j][i] == 'P')
			{
				data->px = i;
				data->py = j;
				return (EXIT_SUCCESS);
			}
			i++;
		}
		j++;
	}
	return (EXIT_FAILURE);
}
void	ft_map_is_game(char **map, int x, int y)
{
	if (map[y][x] == 'P' || map[y][x] == '1')
		return ;
	map[y][x] = 'P';
	ft_map_is_game(map, x + 1, y);
	ft_map_is_game(map, x - 1, y);
	ft_map_is_game(map, x, y + 1);
	ft_map_is_game(map, x, y - 1);
	return ;
}

int	ft_check_the_way(char **mapfill, t_data *data)
{
	int	i;
	int	j;

	j = 0;
	mapfill[data->py][data->px] = '0';
	ft_map_is_game(mapfill, data->px, data->py);
	while (mapfill[j])
	{
		i = 0;
		while (mapfill[j][i])
		{
			if (mapfill[j][i] != '1' && mapfill[j][i] != 'P'
				&& mapfill[j][i] != '0')
				return (ft_free_char(mapfill), EXIT_FAILURE);
			i++;
		}
		j++;
	}
	return (ft_free_char(mapfill), EXIT_SUCCESS);
}

int	ft_check_valid(t_data *data)
{
	char	**mapfill;

	mapfill = ft_strdup_2D(data->maps);
	if (!mapfill)
		return (EXIT_FAILURE);
	if (ft_pos_player(data) == EXIT_FAILURE)
		return (ft_putendl_fd("Error\nPlayer Not Found", 2), EXIT_FAILURE);
	if (ft_check_the_way(mapfill, data) == EXIT_FAILURE)
		return (ft_putendl_fd("Error\nThe Map Is Not Playable", 2),
			EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	ft_display_tab(char **res)
{
	int i;

	i = 0;
	while (res[i])
	{
		printf("%s\n", res[i]);
		i++;
	}
	return ;
}