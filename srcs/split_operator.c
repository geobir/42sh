/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_operator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbir <gbir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 19:54:02 by gbir              #+#    #+#             */
/*   Updated: 2014/06/25 19:54:12 by gbir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <shell.h>
#include <funct_base.h>

static void		st_loop(char **split, pid_t father, t_env **env)
{
	char	*cmd;
	char	**tmpenv;

	cmd = NULL;
	if (father < 0)
	{
		ft_putstr(ER_EXEC);
		exit(father);
	}
	else if (father > 0)
	{
		wait(&father);
		prompt(*env);
	}
	else
	{
		if (*env && iscmd(split[0], &cmd, *env) > 0)
		{
			tmpenv = takeenv(*env);
			execve(cmd, split, tmpenv);
		}
		else
			error_cmd(split[0]);
		exit(father);
	}
}

static void		st_launch(char *buff, t_env	**env)
{
	pid_t	father;
	int		built;
	char	**split;

	built = 0;
	split = NULL;
	split = ft_strsplit(buff, ' ');
	if (*split && (built = isbuiltins(*split)) >= 0)
	{
		builtins(built, split, env);
		prompt(*env);
	}
	else
	{
		father = fork();
		st_loop(split, father, env);
	}
}

char			**split_operator(char *ligne, t_env **env)
{
	char	**ret;
	int		i;

	i = 0;
	if (!(ret = malloc(sizeof(char*) * 2)))
		return (NULL);
	ret[0] = ligne;
	ret[1] = NULL;
	if (!ret[i])
		prompt(*env);
	while (ret[i])
	{
		st_launch(ret[i++], env);
	}
	return (ret);
}
