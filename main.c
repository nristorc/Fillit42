/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 16:14:00 by bvigne            #+#    #+#             */
/*   Updated: 2017/12/04 11:38:16 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		print_map(char **map)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			ft_putchar(map[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

t_tetri		*deroulement(char *capture)
{
	t_tetri	*chaine;
	char	**tab;

	tab = split_tetri(capture);
	if (tab == NULL || test_tab(tab))
	{
		ft_putstr("error\n");
		return (NULL);
	}
	chaine = convert_tetri(tab, tab_count(tab));
	return (chaine);
}

int			main(int argc, char **argv)
{
	char	*capture;
	t_tetri	*chaine;
	char	**map;

	capture = NULL;
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit <source_file>\n");
		return (0);
	}
	else
	{
		if (!(capture = open_source_file(argv[1])))
			return (0);
		if (!(chaine = deroulement(capture)))
			return (0);
		free(capture);
		capture = NULL;
		map = fill_map(chaine);
		print_map(map);
		free_map(map, ft_strlen(map[0]));
	}
	return (0);
}
