/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:33:56 by rdel-olm          #+#    #+#             */
/*   Updated: 2025/01/17 12:58:09 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * The function "ft_control_args" This function checks that there are no more 
 * than one argument and and through the "ft_ext_valid" function that the name
 * of the function is correct as well as its extension.
 * 
 * @param int argc 		Number of arguments.
 * @param char **argv 		Arguments. 
 * 
 */

int	ft_control_args(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_manage_err(NUM_ARGV_ERR);
		return (EXIT_FAILURE);
	}
	else if (!ft_ext_valid(argv[1]))
	{
		printf("error en la extension del mapa joder\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
