/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:19:02 by ayarab            #+#    #+#             */
/*   Updated: 2024/10/24 17:32:24 by ayarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen_2d(char **maps)
{
	int	i;

	i = 0;
	while (maps[i])
		i++;
	return (i);
}
void	ft_free_char(char **res)
{
	int	i;

	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
	return ;
}
char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * (sizeof(char)));
	if (!str)
		return (free(s1), NULL);
	while (s1[i])
	{
		str[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i])
	{
		str[j] = s2[i];
		i++;
		j++;
	}
	str[j] = '\0';
	free(s1);
	return (str);
}

char	**ft_strdup_2D(char **src)
{
	size_t	j;
	char	**res;

	j = 0;
	res = malloc((ft_strlen_2d(src) + 1) * sizeof(char *));
	if (res == NULL)
		return (NULL);
	while (src[j])
	{
		res[j] = ft_strdup(src[j]);
		if (!res)
			return (ft_free_char(res), NULL);
		j++;
	}
	res[j] = NULL;
	return (res);
}
int	ft_check_av1(t_data *data)
{
	int i;
	int point;

	i = 0;
	point = ft_strlen(data->av1) - 4;
	if (ft_strlen(data->av1) < 4)
		return (EXIT_FAILURE);
	if (ft_strcmp(&data->av1[point], ".ber") != 0)
		return (EXIT_FAILURE);
	if (data->av1[point - 1] == '/')
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}