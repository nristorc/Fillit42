/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 15:50:55 by bvigne            #+#    #+#             */
/*   Updated: 2017/11/29 13:46:45 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri		*fill_tetri_4(char **tetri, int i, int j, t_tetri *fresh)
{
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tetri[i][j] == '#')
			{
				tetri[i][j] = '.';
				fresh->block_4.x = i;
				fresh->block_4.y = j;
				return (fresh);
			}
			j++;
		}
		i++;
	}
	return (fresh);
}

t_tetri		*fill_tetri_3(char **tetri, int i, int j, t_tetri *fresh)
{
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tetri[i][j] == '#')
			{
				tetri[i][j] = '.';
				fresh->block_3.x = i;
				fresh->block_3.y = j;
				fill_tetri_4(tetri, i, j, fresh);
				return (fresh);
			}
			j++;
		}
		i++;
	}
	return (fresh);
}

t_tetri		*fill_tetri_2(char **tetri, int i, int j, t_tetri *fresh)
{
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tetri[i][j] == '#')
			{
				tetri[i][j] = '.';
				fresh->block_2.x = i;
				fresh->block_2.y = j;
				fill_tetri_3(tetri, i, j, fresh);
				return (fresh);
			}
			j++;
		}
		i++;
	}
	return (fresh);
}

t_tetri		*fill_tetri_1(char **tetri, int i, int j, int k)
{
	t_tetri		*fresh;

	if (!(fresh = (t_tetri *)ft_memalloc(sizeof(t_tetri))))
		return (NULL);
	fresh->name = k + 65;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tetri[i][j] == '#')
			{
				tetri[i][j] = '.';
				fresh->block_1.x = i;
				fresh->block_1.y = j;
				fill_tetri_2(tetri, i, j, fresh);
				fresh = replace_all_blocks(fresh);
				return (fresh);
			}
			j++;
		}
		i++;
	}
	return (fresh);
}
