/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_unsetenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbir <gbir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 00:45:20 by gbir              #+#    #+#             */
/*   Updated: 2014/04/27 00:45:21 by gbir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <funct_base.h>
#include <shell.h>
#include <built.h>

void	built_unsetenv(char *unset, t_env **env)
{
	t_env	*last;
	t_env	*tmp;

	tmp = *env;
	last = tmp;
	while (tmp && tmp->name && tmp->data)
	{
		if (ft_strcmp(tmp->name, unset) == 0)
		{
			if (tmp == *env)
				*env = tmp->next;
			else
				last->next = tmp->next;
			free(tmp->name);
			free(tmp->data);
			free(tmp);
			break ;
		}
		last = tmp;
		tmp = tmp->next;
	}
}
