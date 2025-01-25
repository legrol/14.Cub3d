/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_analyzer_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 19:29:59 by drosales          #+#    #+#             */
/*   Updated: 2025/01/25 00:03:44 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_checking_lines(char	*map)
{
	int	i;

	if (!map || !map[0])
		return (ft_manage_err(MAP_ERR), EXIT_FAILURE);
	i = 0;
	while (map[i])
	{
		if (map[i] == '\n')
		{
			i++;
			while (map[i] == ' ')
				i++;
			if (map[i] == '\n' || map[i] == '\0')
				return (ft_manage_err(EXTRA_LINE_ERR), EXIT_FAILURE);
		}
		else
			i++;
	}
	return (EXIT_SUCCESS);
}

char	*ft_matrix_to_str(char	*c, int fd)
{
	char	*map;

	map = NULL;
	while (c)
	{
		if (!c)
			return (ft_manage_err(READ_ERR), NULL);
		map = ft_new_strjoin(map, c);
		if (!map)
			return (ft_manage_err(MATRIX_TO_STR_ERR), NULL);
		c = get_next_line(fd);
	}
	return (map);
}

int	ft_map_spliting(t_cub3d *cub, char *map)
{
	int	flag;

	flag = 0;
	if (ft_checking_lines(map))
		flag = 1;
	if (flag == 1)
		return (free(map), EXIT_FAILURE);
	cub->map.map = ft_split(map, '\n');
	free(map);
	if (!cub->map.map)
		return (ft_manage_err(FT_SPLIT_ERR), EXIT_FAILURE);
	cub->map.line_map = ft_split_len(cub->map.map);
	return (EXIT_SUCCESS);
}

void	ft_map_dimensions(t_map *map)
{
	int	i;
	int	j;
	int	len;

	if (!map->map || !map->map[0])
		return ;
	i = 0;
	j = 0;
	while (map->map[i])
	{
		len = ft_strlen(map->map[i]);
		if (len > j)
			j = len;
		i++;
	}
	map->x_map = j;
	map->y_map = i;
}
