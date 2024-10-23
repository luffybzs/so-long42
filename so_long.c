/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:49:24 by ayarab            #+#    #+#             */
/*   Updated: 2024/10/23 19:14:34 by ayarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	fill_data(t_data *data, char **av)
{
	data->av1 = av[1];
	if (ft_strstr(data->av1, ".ber") == 0)
		return (ft_putendl_fd("Error\nInvalid File", 2), EXIT_FAILURE);
	data->maps = ft_the_maps(data);
	if (!data->maps)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	t_data data;
	(void)ac;

	if (fill_data(&data, av) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (ft_check_wall(&data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (ft_check_char(&data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (ft_check_valid(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (0);
}