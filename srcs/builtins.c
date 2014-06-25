/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbir <gbir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 14:49:28 by gbir              #+#    #+#             */
/*   Updated: 2014/04/27 14:49:31 by gbir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <funct_base.h>
#include <built.h>

void		builtins(int built, char **arg, t_env **env)
{
	if (built == 3)
		built_env(*env);
	else if (built == 2 && arg[1])
		built_unsetenv(arg[1], env);
	else if (built == 1 && arg[1] && arg[2])
		built_setenv(arg[1], arg[2], env);
	else if (built == 0)
		built_cd(arg[1], *env);
	else if (built == 4)
		built_exit();
}
