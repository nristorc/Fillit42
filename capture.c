/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 18:01:09 by bvigne            #+#    #+#             */
/*   Updated: 2017/12/04 11:20:10 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		tab_count(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int		test_symb(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (i == 0 || (i + 1) % 5)
		{
			if (str[i] != '#' && str[i] != '.')
				return (0);
		}
		else
		{
			if (str[i] != '\n')
				return (0);
		}
		i++;
	}
	return (1);
}

char	**split_tetri(char *capture)
{
	char	**tab;
	int		i;
	int		start;

	i = 0;
	start = 0;
	if ((int)ft_strlen(capture) == 0)
		return (NULL);
	if (!(tab = (char **)malloc(sizeof(char *) * 27)))
		return (NULL);
	while (start < (int)ft_strlen(capture))
	{
		if (!(test_symb(ft_strsub(capture, start, 20))))
			return (NULL);
		tab[i] = ft_strsub(capture, start, 20);
		i++;
		start = start + 21;
	}
	if (capture[start - 1])
		return (NULL);
	tab[i] = NULL;
	return (tab);
}

char	*capture_source_file(char *source, int len)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];
	char	*capture;
	int		i;

	i = 0;
	if (!(capture = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	fd = open(source, O_RDONLY);
	if (fd == -1)
		ft_putstr("error\n");
	ret = read(fd, buf, BUF_SIZE);
	while (ret)
	{
		buf[ret] = '\0';
		capture[i] = buf[0];
		ret = read(fd, buf, BUF_SIZE);
		i++;
	}
	capture[i] = '\0';
	if (close(fd) == -1)
		ft_putstr("error\n");
	return (capture);
}

char	*open_source_file(char *source)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];
	char	*capture;
	int		len;

	len = 0;
	fd = open(source, O_RDONLY);
	if (open(source, O_RDONLY) == -1)
	{
		ft_putstr("error\n");
		return (NULL);
	}
	ret = read(fd, buf, BUF_SIZE);
	while (ret)
	{
		ret = read(fd, buf, BUF_SIZE);
		len++;
		if (len > 545)
			return ("error\n");
	}
	if (close(fd) == -1)
		ft_putstr("error\n");
	capture = capture_source_file(source, len + 1);
	return (capture);
}
