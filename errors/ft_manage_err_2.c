/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_err_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 00:30:57 by rdel-olm          #+#    #+#             */
/*   Updated: 2025/01/25 00:47:20 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * The function "ft_manage_err_id" logs an error message related to an 
 * invalid or problematic identifier. It formats the error message using 
 * styles and macros for clarity and consistency.
 * 
 * @param const char *id				A pointer to the identifier string 
 * 										that caused the error.
 * 
 * @return void 
 * 
 */

void	ft_manage_err_id(const char *id)
{
	ft_printf(BDRED "Error: \n" RESET RED INIT_ERR RESET GREEN ARROW RESET \
	YELLOW IDENT_ERR RESET RED "%s" RESET YELLOW IDENT2_ERR RESET, id);
}
