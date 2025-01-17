/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_err.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:21:03 by rdel-olm          #+#    #+#             */
/*   Updated: 2025/01/17 16:46:17 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * The function "ft_manage_err" After detecting an error, prints the error on 
 * the screen (passed as an argument), extracted from macros.h.
 * 
 * @param const char *err error passed as macro.
 * 
 */

void	ft_manage_err(const char *err)
{
	ft_printf(BDRED "Error: \n" RESET RED INIT_ERR RESET GREEN ARROW RESET \
	YELLOW "%s\n" RESET, err);
}

void	ft_invalid_char(char **map, int line, int pos)
{
	char	letter;

	letter = map[line][pos];
	ft_printf(BDRED "Error: \n" RESET RED INIT_ERR RESET GREEN ARROW RESET \
	YELLOW CHAR1_ERR "\"" RESET BLUE "%c" RESET YELLOW "\" ...\n" RESET, \
	letter);
	ft_printf(YELLOW CHAR2_ERR RESET RED "%i" RESET YELLOW CHAR3_ERR RESET \
	RED "%i" RESET YELLOW "." RESET, line + 1, pos + 1);
}
