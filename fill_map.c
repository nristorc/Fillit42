/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 17:10:48 by bvigne            #+#    #+#             */
/*   Updated: 2017/12/01 10:29:43 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		test_pos(char **map, int pos, int size, t_tetri *tetri)
{
	int		i;
	int		j;

	i = pos / size;
	j = pos % size;
	if (i + tetri->block_1.x < size && j + tetri->block_1.y < size &&
		i + tetri->block_2.x < size && j + tetri->block_2.y < size &&
		i + tetri->block_3.x < size && j + tetri->block_3.y < size &&
		i + tetri->block_4.x < size && j + tetri->block_4.y < size &&
		i + tetri->block_1.x < size && j + tetri->block_1.y < size &&
		i + tetri->block_2.x < size && j + tetri->block_2.y < size &&
		i + tetri->block_3.x < size && j + tetri->block_3.y < size &&
		i + tetri->block_4.x < size && j + tetri->block_4.y < size &&
		map[i + tetri->block_1.x][j + tetri->block_1.y] == '.' &&
		map[i + tetri->block_2.x][j + tetri->block_2.y] == '.' &&
		map[i + tetri->block_3.x][j + tetri->block_3.y] == '.' &&
		map[i + tetri->block_4.x][j + tetri->block_4.y] == '.')
		return (1);
	return (0);
}

char	**reset_pos(char **map, int pos, int size, t_tetri *tetri)
{
	int		i;
	int		j;

	i = pos / size;
	j = pos % size;
	map[i + tetri->block_1.x][j + tetri->block_1.y] = '.';
	map[i + tetri->block_2.x][j + tetri->block_2.y] = '.';
	map[i + tetri->block_3.x][j + tetri->block_3.y] = '.';
	map[i + tetri->block_4.x][j + tetri->block_4.y] = '.';
	return (map);
}

char	**fill_pos(char **map, int pos, int size, t_tetri *tetri)
{
	int		i;
	int		j;

	i = pos / size;
	j = pos % size;
	map[i + tetri->block_1.x][j + tetri->block_1.y] = tetri->name;
	map[i + tetri->block_2.x][j + tetri->block_2.y] = tetri->name;
	map[i + tetri->block_3.x][j + tetri->block_3.y] = tetri->name;
	map[i + tetri->block_4.x][j + tetri->block_4.y] = tetri->name;
	return (map);
}

int		ft_bactracking(char **map, t_tetri *tetri, int size, int pos)
{
	if (map_full(map, tetri))
		return (1);
	if (map[pos / size][pos % size] != '.')
		return (ft_bactracking(map, tetri, size, pos + 1));
	while (pos <= (size * size) - 1)
	{
		if (test_pos(map, pos, size, tetri))
		{
			map = fill_pos(map, pos, size, tetri);
			if (map_full(map, tetri))
				return (1);
			if (tetri->next && ft_bactracking(map, tetri->next, size, 0))
				return (1);
			else
				map = reset_pos(map, pos, size, tetri);
		}
		pos++;
	}
	return (0);
}

char	**fill_map(t_tetri *chaine)
{
	char	**map;
	int		size;
	int		pos;
	int		rez;

	map = NULL;
	pos = 0;
	rez = 0;
	size = (ft_sqrt_higher(ft_lstcount(chaine)));
	while (!rez)
	{
		map = new_map(size);
		rez = ft_bactracking(map, chaine, size, pos);
		if (!rez)
		{
			free_map(map, size);
			size++;
		}
	}
	return (map);
}
