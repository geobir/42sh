/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_setenv.c                                     :+:      :+:    :+:   */
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

void	built_setenv(char *name, char *data, t_env **env)
{
	t_env	*tmp;

	tmp = *env;
	while (tmp && tmp->name && tmp->data)
	{
		if (ft_strcmp(tmp->name, name) == 0)
		{
			tmp->data = data;
			return ;
		}
		if (!tmp->next)
			break ;
		tmp = tmp->next;
	}
	if (!tmp)
	{
		*env = malloc(sizeof(t_env));
		(*env)->name = ft_strdup(name);
		(*env)->data = ft_strdup(data);
		(*env)->next = NULL;
		return ;
	}
	tmp->next = malloc(sizeof(t_env));
	tmp = tmp->next;
	tmp->name = ft_strdup(name);
	tmp->data = ft_strdup(data);
	tmp->next = NULL;
}
