/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify_lines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:02:49 by rdel-olm          #+#    #+#             */
/*   Updated: 2025/01/17 13:46:32 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/****
 * 
 * 
 * 
 * 
 */

static int	ft_verify_chars(char c)
{
	if (c != 'N' && c != 'S' && c != 'E' && c != 'W' && \
		c != 10 && c != 32 && c != 48 && c != 49)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	ft_verify_core(char **map)
{
	int	i;
	int	j;
	int	output;

	i = 0;
	output = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_verify_chars(map[i][j]))
			{
				ft_invalid_char(map, i, j);
				output = 1;
			}
			j++;
		}
		i++;
	}
	if (output == 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	ft_verify_last_line(char **map, int end)
{
	int	i;

	i = 0;
	while (map[end - 1][i])
	{
		if (map[end - 1][i] != 49 && map[end - 1][i] != 32)
		{
			ft_manage_err(INV_CHAR2_ERR);
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

static int	ft_verify_first_line(char **map)
{
	int	i;

	i = 0;
	while (map[0][i])
	{
		if (map[0][i] != 49 && map[0][i] != 32)
		{
			ft_manage_err(INV_CHAR_ERR);
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	ft_verify_extremes(t_cub3d *details, char **map)
{
	int	flag;

	flag = 0;
	if (ft_verify_first_line(map))
		flag = 1;
	if (ft_verify_last_line(map, details->map.line_map))
		flag = 1;
	if (flag == 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
