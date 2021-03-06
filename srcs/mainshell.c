/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainshell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbir <gbir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 15:51:19 by gbir              #+#    #+#             */
/*   Updated: 2014/06/25 19:55:36 by gbir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gnl.h>
#include <shell.h>
#include <funct_base.h>

void			mainshell(void)
{
	char	*buff;
	t_env	*env;

	buff = NULL;
	env = makeenv();
	prompt(env);
	while (g_n_l(1, &buff))
	{
		split_operator(buff, &env);
	}
}
