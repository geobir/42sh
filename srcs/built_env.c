/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbir <gbir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 00:45:20 by gbir              #+#    #+#             */
/*   Updated: 2014/04/27 00:45:21 by gbir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <funct_base.h>
#include <shell.h>

void	built_env(t_env *env)
{
	while (env && env->name && env->data)
	{
		ft_putstr(env->name);
		write(1, "=", 1);
		ft_putstr(env->data);
		write(1, "\n", 1);
		env = env->next;
	}
}
