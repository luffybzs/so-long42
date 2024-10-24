/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:49:24 by ayarab            #+#    #+#             */
/*   Updated: 2024/10/24 19:39:41 by ayarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



int	main(int ac, char **av)
{
	t_data	data;

	if (ft_all_parsing(ac,av,&data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (ft_open_window(&data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
