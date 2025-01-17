/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_err.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:21:03 by rdel-olm          #+#    #+#             */
/*   Updated: 2025/01/17 17:08:42 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * The function "ft_invalid_char" logs detailed information about an invalid 
 * character detected in the map. It specifies the invalid character, its 
 * line number, and its position within the line, helping with debugging.
 * 
 * @param char **map				A 2D array representing the map being 
 * 									verified.
 * @param int line					The line index in the map where the 
 * 									invalid character was found.
 * @param int pos					The column index in the line where the 
 * 									invalid character was found.
 * 
 * @return void
 * 
 * The function "ft_manage_err" handles the detection of errors by printing 
 * an error message to the screen. The error message is passed as an argument, 
 * typically defined in a header file (e.g., `macros.h`), and formatted for 
 * readability.
 * 
 * @param const char *err			A pointer to the error message string, 
 * 									passed as a macro.
 * 
 * @return void
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
