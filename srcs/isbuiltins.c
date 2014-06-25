/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isbuiltins.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbir <gbir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 14:49:28 by gbir              #+#    #+#             */
/*   Updated: 2014/04/27 14:49:31 by gbir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <funct_base.h>
#include <built.h>

int		isbuiltins(char *cmd)
{
	const char	*(builtins[]) = {BUILIINS};
	int			i;

	i = 0;
	while (builtins[i])
	{
		if (ft_strcmp(builtins[i], cmd) == 0)
			return (i);
		++i;
	}
	return (-1);
}
