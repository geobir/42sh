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

#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <gnl.h>
#include <shell.h>
#include <funct_base.h>
#include <stdio.h>

static char		**st_takeenv(t_env *env)
{
	char	**ret;
	char	**tmp_ret;
	int		i;
	t_env	*tmp;
	char	*fre;

	i = 0;
	tmp = env;
	while (tmp && ++i)
		tmp = tmp->next;
	ret = malloc(sizeof(char*) * (i + 1));
	tmp_ret = ret;
	tmp = env;
	while (tmp)
	{
		fre = ft_strjoin(tmp->name, "=");
		*tmp_ret++ = ft_strjoin(fre, tmp->data);
		free(fre);
		tmp = tmp->next;
	}
	*tmp_ret = NULL;
	return (ret);
}

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
			tmpenv = st_takeenv(*env);
			execve(cmd, split, tmpenv);
		}
		else
			errorCMD(split[0]);
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

void			mainshell(void)
{
	char	*buff;
	t_env	*env;
	int		i;
	char	**split;

	buff = NULL;
	env = makeenv();
	prompt(env);
	while (g_n_l(1, &buff))
	{
		i = 0;
		split = split_operator(buff);
		if (!split[i])
			prompt(env);
		while (split[i])
		{
			st_launch(split[i++], &env);
		}
	}
}
