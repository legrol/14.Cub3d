/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-20 19:43:20 by drosales          #+#    #+#             */
/*   Updated: 2025-01-20 19:43:20 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int ft_split_len(char **str)
{
    int i;

    i = 0;
    if (!str)
        return (NULL);
    while (str[i])
        i++;
    return (i);
}