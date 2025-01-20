/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_analyser_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-20 19:29:59 by drosales          #+#    #+#             */
/*   Updated: 2025-01-20 19:29:59 by drosales         ###   ########.fr       */
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

int ft_map_spliting(t_cub3d *cub, char *map)
{
    int flag;

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