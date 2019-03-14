/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_tetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 12:33:09 by bvigne            #+#    #+#             */
/*   Updated: 2017/11/30 16:08:12 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri		*ft_lstlast(t_tetri *list)
{
	int		i;

	i = 0;
	while (list->next)
	{
		list = list->next;
		i++;
	}
	return (list);
}

int			map_full(char **map, t_tetri *tetri)
{
	int		i;
	int		j;
	int		cpt;
	char	name;

	cpt = 0;
	i = 0;
	name = ft_lstlast(tetri)->name;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == name)
				cpt++;
			j++;
		}
		i++;
	}
	if (cpt == 4)
		return (1);
	return (0);
}

t_tetri		*replace_all_blocks(t_tetri *fresh)
{
	int		i;
	int		j;

	i = fresh->block_1.x;
	j = fresh->block_1.y;
	fresh->block_1.x = fresh->block_1.x - i;
	fresh->block_1.y = fresh->block_1.y - j;
	fresh->block_2.x = fresh->block_2.x - i;
	fresh->block_2.y = fresh->block_2.y - j;
	fresh->block_3.x = fresh->block_3.x - i;
	fresh->block_3.y = fresh->block_3.y - j;
	fresh->block_4.x = fresh->block_4.x - i;
	fresh->block_4.y = fresh->block_4.y - j;
	return (fresh);
}

t_tetri		*convert_tetri(char **tab, int nb)
{
	int		i;
	int		j;
	int		k;
	t_tetri	*fresh;
	t_tetri	*init;

	i = 0;
	j = 0;
	k = 0;
	fresh = NULL;
	if (!(fresh = (t_tetri *)malloc(sizeof(t_tetri) * (nb + 1))))
		return (NULL);
	fresh = fill_tetri_1(ft_strsplit(tab[k], '\n'), i, j, k);
	k++;
	init = fresh;
	while (nb - 1)
	{
		fresh->next = fill_tetri_1(ft_strsplit(tab[k], '\n'), i, j, k);
		if (fresh->next)
			fresh = fresh->next;
		k++;
		nb--;
	}
	fresh->next = NULL;
	return (init);
}
