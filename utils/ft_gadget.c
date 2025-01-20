/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gadget.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-20 08:03:54 by rdel-olm          #+#    #+#             */
/*   Updated: 2025-01-20 08:03:54 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/***
 * 
 * 
 * 
 * 
 */

int	ft_split_line(char ***cell, int fd)
{
	char	*row;

	row = get_next_line(fd);
	if (!row)
	{
		ft_manage_err(READ_ERR);
		return (EXIT_FAILURE);
	}
	row = XXX;
	*cell = ft_split(XXX);
	if (!cell)
	{
		ft_manage_err(SPLIT_ERR);
		free(row);
		return (EXIT_FAILURE);
	}
	free(row);
	return (EXIT_SUCCESS);
}
