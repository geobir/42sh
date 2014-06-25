/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchcmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbir <gbir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 14:41:05 by gbir              #+#    #+#             */
/*   Updated: 2014/04/27 14:41:06 by gbir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <funct_base.h>

char		*shearchcmd(char *path, char *cmd)
{
	char	**split;
	char	*way;
	char	*fre;

	split = ft_strsplit(path, ':');
	while (*split)
	{
		fre = ft_strjoin(*split, "/");
		way = ft_strjoin(fre, cmd);
		free(fre);
		if (access(way, X_OK) == 0)
			return (way);
		free (way);
		++split;
	}
	return (NULL);
}
