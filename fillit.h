/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 16:21:11 by bvigne            #+#    #+#             */
/*   Updated: 2017/12/04 11:48:44 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUF_SIZE 1

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "Libft/libft.h"

typedef	struct		s_coord
{
	int				x;
	int				y;
}					t_coord;

typedef	struct		s_tetri
{
	char			name;
	t_coord			block_1;
	t_coord			block_2;
	t_coord			block_3;
	t_coord			block_4;
	struct s_tetri	*next;
}					t_tetri;

t_tetri				*convert_tetri(char **tab, int nb);
char				**fill_map(t_tetri *chaine);
t_tetri				*fill_tetri_1(char **tetri, int i, int j, int k);
void				free_map(char **map, int size);
int					ft_bactracking(char **map, t_tetri *chaine, int size, \
					int pos);
int					ft_lstcount(t_tetri *list);
t_tetri				*ft_lstlast(t_tetri *list);
int					ft_sqrt_higher(int n);
int					main(int argc, char **argv);
int					map_full(char **map, t_tetri *tetri);
char				**new_map(int size);
char				*open_source_file(char *source);
void				print_map(char **map);
t_tetri				*replace_all_blocks(t_tetri *fresh);
char				**split_tetri(char *capture);
int					tab_count(char **tab);
int					test_tab(char **tab);
int					test_symb(char *str);

#endif
