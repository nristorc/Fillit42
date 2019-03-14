/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nristorc <nristorc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:02:42 by nristorc          #+#    #+#             */
/*   Updated: 2017/12/04 11:21:30 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_sqrt_higher(int n)
{
	int		size;

	size = 2;
	while (size * size < n * 4)
		size++;
	return (size);
}

int		ft_lstcount(t_tetri *list)
{
	int		i;

	i = 0;
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}

char	*str_fill_point(int size)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = (char *)malloc(sizeof(*str) * (size + 1))))
		return (NULL);
	while (i < (int)size)
	{
		str[i] = '.';
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**new_map(int size)
{
	int		i;
	char	**map;

	i = 0;
	if (!(map = (char **)ft_memalloc(sizeof(char *) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		map[i] = str_fill_point(size);
		i++;
	}
	map[i] = NULL;
	return (map);
}

void	free_map(char **map, int size)
{
	int		j;

	j = 0;
	while (j < size)
	{
		free(map[j]);
		map[j] = NULL;
		j++;
	}
	free(map);
	map = NULL;
}
