/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_strjoin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-20 18:45:43 by drosales          #+#    #+#             */
/*   Updated: 2025-01-20 18:45:43 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*ft_new_strjoin(char const *s1, char const *s2)
{
	size_t		totallen;
	char		*buffer;

    if (!s2)
        return (s1);
    if (!s1)
        return (ft_strdup(s2));
	totallen = ft_strlen(s1) + ft_strlen(s2);
	buffer = (char *)malloc(sizeof(char) * (totallen + 1));
	if (!buffer)
		return (NULL);
	ft_memcpy(buffer, s1, ft_strlen(s1));
    ft_memcpy(buffer + ft_strlen(s1), s2, ft_strlen(s2));
	buffer[totallen] = '\0';
    free (s1);
	return (buffer);
}
