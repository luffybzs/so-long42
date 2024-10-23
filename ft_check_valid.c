/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:14:58 by ayarab            #+#    #+#             */
/*   Updated: 2024/10/23 20:03:44 by ayarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_pos_player(t_data *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (data->maps[j])
	{
		while (data->maps[j][i])
		{
			if (data->maps[j][i] == 'P')
			{
				data->playerx = i;
				data->playery = j;
				return (EXIT_SUCCESS);
			}
			i++;
		}
		j++;
	}
	return (EXIT_FAILURE); 
}



int ft_check_valid(t_data *data)
{
	char **mapfill;
	
	mapfill = ft_strdup_2D(data->maps);
	if (!mapfill)
		return (EXIT_FAILURE);
	if (ft_pos_player(data) == EXIT_FAILURE)
		return (ft_putendl_fd("Error\nPlayer Not Found", 2), EXIT_FAILURE);
	if (ft_map_is_game(mapfill,data) == EXIT_FAILURE)
		return (ft_putendl_fd("Error\nThe Map Is Not Playable", 2), EXIT_FAILURE);
}

void ft_display_tab(char **res)
{
	int i;

	i = 0;
	while (res[i])
	{
		printf("%s", res[i]);
		i++;
	}
	return ;
}