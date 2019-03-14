/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_capture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 13:57:19 by bvigne            #+#    #+#             */
/*   Updated: 2017/12/04 11:23:16 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		count_link(char **coord, int i, int j)
{
	int		link;

	link = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (coord[i][j] == '#')
			{
				if ((j + 1) < 4 && coord[i][j + 1] == '#')
					link++;
				if ((j - 1) >= 0 && coord[i][j - 1] == '#')
					link++;
				if ((i + 1) < 4 && coord[i + 1][j] == '#')
					link++;
				if ((i - 1) >= 0 && coord[i - 1][j] == '#')
					link++;
			}
			j++;
		}
		i++;
	}
	return (link);
}

int		test_symb_pos(char *tetri)
{
	char	**coord;
	int		link;
	int		i;
	int		j;

	i = 0;
	j = 0;
	link = 0;
	coord = ft_strsplit(tetri, '\n');
	link = count_link(coord, i, j);
	if (link != 6 && link != 8)
		return (1);
	return (0);
}

int		test_symb_nbr(char *tetri)
{
	char	**ligne;
	int		i;
	int		j;
	int		cpt;

	i = 0;
	j = 0;
	cpt = 0;
	ligne = ft_strsplit(tetri, '\n');
	while (ligne[i])
	{
		j = 0;
		while (ligne[i][j])
		{
			if (ligne[i][j] == '#')
				cpt++;
			j++;
		}
		i++;
	}
	if ((!(cpt == 4)) || ligne == NULL)
		return (1);
	return (0);
}

int		test_tab(char **tab)
{
	int		res;
	int		i;

	i = 0;
	res = 0;
	while (tab[i])
	{
		res += test_symb_nbr(tab[i]);
		res += test_symb_pos(tab[i]);
		i++;
	}
	if (res)
		return (1);
	return (0);
}
