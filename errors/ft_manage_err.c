/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_err.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-15 16:21:03 by rdel-olm          #+#    #+#             */
/*   Updated: 2025-01-15 16:21:03 by rdel-olm         ###   ########.fr       */
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
	ft_printf("Error: %s\n", err);
	exit (EXIT_FAILURE);
}
