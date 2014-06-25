/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainshell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbir <gbir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 15:51:19 by gbir              #+#    #+#             */
/*   Updated: 2014/04/27 15:51:20 by gbir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <gnl.h>
#include <shell.h>
#include <funct_base.h>

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

void			mainshell(void)
{
	pid_t	father;
	char	*buff;
	char	**split;
	t_env	*env;
	int		built;

	buff = NULL;
	split = NULL;
	env = makeenv();
	prompt(env);
	while (g_n_l(1, &buff))
	{
		built = 0;
		split = ft_strsplit(buff, ' ');
		if (*split && (built = isbuiltins(*split)) >= 0)
		{
			builtins(built, split, &env);
			prompt(env);
		}
		else
		{
			father = fork();
			st_loop(split, father, &env);
		}
	}
}
