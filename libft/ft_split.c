/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:21:01 by ayarab            #+#    #+#             */
/*   Updated: 2024/10/24 11:39:10 by ayarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	count_words(char const *s, char c)
{
	size_t	i;
	int		n;

	i = 0;
	n = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			n++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (n);
}

int	lenght_word(char const *s, char c, int i)
{
	int	n;

	n = 0;
	while (s[i + n] != c && s[i + n])
		n++;
	return (n);
}

void	*ft_free(char **str, int count)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (i < count)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

char	**sous_split(char const *s, char c, char **str)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		k = 0;
		str[j] = malloc((lenght_word(s, c, i) + 1) * sizeof(char));
		if (str[j] == NULL)
			return (ft_free(str, j));
		while (s[i] && s[i] != c)
			str[j][k++] = s[i++];
		str[j][k] = 0;
		while (s[i] == c && s[i])
			i++;
		j++;
	}
	str[j] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;

	if (!s)
		return (NULL);
	str = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (str == NULL)
		return (str);
	return (sous_split(s, c, str));
}
