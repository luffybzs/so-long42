/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:14:29 by ayarab            #+#    #+#             */
/*   Updated: 2024/10/23 18:38:14 by ayarab           ###   ########.fr       */
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
		exit(EXIT_FAILURE);
	res = ft_strdup("");
	if (!res)
		return (NULL);
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] == '\n')
			return (NULL);
		res = ft_strjoin_free(res, line);
		if (!res)
			return (NULL);
		line = get_next_line(fd);
	}
	return (res);
}

char	**ft_the_maps(t_data *data)
{
	char *map;
	char **maps;

	map = ft_start_the_map(data->av1);
	if (!map)
		return (NULL);
	maps = ft_split(map, '\n');
	if (!maps)
		return (NULL);
	return (maps);
}
