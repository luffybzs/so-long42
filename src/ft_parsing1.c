/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:14:29 by ayarab            #+#    #+#             */
/*   Updated: 2024/10/24 19:51:53 by ayarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_start_the_map(char *av1)
{
	int		fd;
	char	*line;
	char	*res;

	fd = open(av1, O_RDONLY);
	if (fd == -1)
		return (ft_putendl_fd("Error\nFail Open", 2), NULL);
	res = ft_strdup("");
	if (!res)
		return (NULL);
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] == '\n')
			return (free(line), free(res), NULL);
		res = ft_strjoin_free(res, line);
		if (!res)
			return (free(line), NULL);
		free(line);
		line = get_next_line(fd);
	}
	return (res);
}

char	**ft_the_maps(t_data *data)
{
	char	*map;
	char	**maps;

	map = ft_start_the_map(data->av1);
	if (!map)
		return (NULL);
	maps = ft_split(map, '\n');
	if (!maps)
		return (free(map), NULL);
	free(map);
	return (maps);
}

int	ft_all_parsing(int ac, char **av, t_data *data)
{
	if (ac != 2)
		return (ft_putendl_fd("Error\nArgument", 2), EXIT_FAILURE);
	if (fill_data(data, av) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (ft_check_wall(data) == EXIT_FAILURE)
		return (ft_free_char(data->maps), EXIT_FAILURE);
	if (ft_check_char(data) == EXIT_FAILURE)
		return (ft_free_char(data->maps), EXIT_FAILURE);
	if (ft_check_valid(data) == EXIT_FAILURE)
		return (ft_free_char(data->maps), EXIT_FAILURE);
	// ft_free_char(data->maps);
	return (EXIT_SUCCESS);
}

int	fill_data(t_data *data, char **av)
{
	data->av1 = av[1];
	if (ft_check_av1(data) == EXIT_FAILURE)
		return (ft_putendl_fd("Error\nInvalid File", 2), EXIT_FAILURE);
	data->maps = ft_the_maps(data);
	if (!data->maps)
		return (ft_putendl_fd("Error\nMap Not Good", 2), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
