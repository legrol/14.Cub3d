/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_erase.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 21:33:50 by rdel-olm          #+#    #+#             */
/*   Updated: 2025/01/24 23:32:48 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * The function "ft_trim_newline" reallocates memory for a string to remove 
 * any unused space after the string's actual content, effectively trimming 
 * it to its exact length. It uses "ft_realloc" to achieve this.
 * 
 * @param char *str				A pointer to the string to be trimmed.
 * 
 * @return char*				Returns the reallocated string without extra 
 * 								memory. Returns NULL if memory allocation 
 * 								fails. 
 * 
 */

char	*ft_trim_newline(char *str)
{
	char	*trimline;

	trimline = ft_realloc(str, ft_strlen(str));
	if (!trimline)
		return (NULL);
	return (trimline);
}
