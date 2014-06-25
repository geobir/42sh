/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iscmd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbir <gbir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 14:36:59 by gbir              #+#    #+#             */
/*   Updated: 2014/04/27 14:37:11 by gbir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <shell.h>
#include <funct_base.h>

static int	st_is_already_cmd(char *cmd, char **way)
{
	char	cur_path[256];

	if (*cmd == '.')
	{
		getcwd(cur_path, sizeof(cur_path));
		*way = ft_strjoin(cur_path, &(cmd[1]));
	}
	else
		*way = cmd;
	if (access(*way, X_OK) < 0)
		return (0);
	return (1);
}

int			iscmd(char *cmd, char **way, t_env *env)
{
	if (*cmd == '.' || *cmd == '/')
	{
		if (st_is_already_cmd(cmd, way))
			return (1);
		return (0);
	}
	while (env && env->name && env->data)
	{
		if (ft_strcmp("PATH", env->name) == 0)
		{
			*way = shearchcmd(env->data, cmd);
			if (*way)
				return (1);
			return (0);
		}
		env = env->next;
	}
	return (0);
}
