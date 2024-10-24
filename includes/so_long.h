/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:01:33 by ayarab            #+#    #+#             */
/*   Updated: 2024/10/24 21:01:28 by ayarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

# define SIZE 64


typedef struct s_data
{
	char	*av1;
	char	**maps;
	int		coin;
	int		exit;
	int		player;
	int		px;
	int		py;
	int		lx;
	int		ly;
	void	*mlx;
	void	*mlx_win;
	void	*mlx_luffy;
	void	*mlx_back;
	void 	*mlx_coin;
}			t_data;

//........................parsing........................//

char		*ft_start_the_map(char *av1);
char		**ft_the_maps(t_data *data);
int			fill_data(t_data *data, char **av);
int			ft_all_parsing(int ac, char **av, t_data *data);

//........................check...........................//

int			ft_check_verif_vertical(t_data *data);
int			ft_check_last_vertical(t_data *data);
int			ft_check_tab(t_data *data);
int			ft_check_verif_line(t_data *data, int pos);
int			ft_check_wall(t_data *data);

//........................check-char......................//

int			ft_check_all_maps(t_data *data);
int			ft_check_nb_char(t_data *data, char c);
int			ft_check_value(t_data *data);
void		init_check_data(t_data *data);
int			ft_check_char(t_data *data);

//........................fonction........................//

int			ft_strlen_2d(char **maps);
void		ft_free_char(char **res);
char		*ft_strjoin_free(char *s1, char *s2);
char		**ft_strdup_2D(char **src);
int			ft_check_av1(t_data *data);

//........................valid...........................//

int			ft_check_valid(t_data *data);
int			ft_check_the_way(char **mapfill, t_data *data);
int			ft_pos_player(t_data *data);
void		ft_map_is_game(char **map, int x, int y);

//.......................open-win.........................//

int			ft_open_window(t_data *data);
int			ft_start_mlx(t_data *data);

#endif