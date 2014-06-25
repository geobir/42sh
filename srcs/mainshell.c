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

static void		st_prompt(t_env *env)
{
	char	*prompt;

	prompt = NULL;
	while (env && env->name && env->data)
	{
		if (ft_strcmp(env->name, "USER") == 0)
		{
			prompt = env->data;
			break ;
		}
		env = env->next;
	}
	if (!prompt)
	{
		write(1, PROMPT);
		return ;
	}
	write(1, "\x1B[31m", ft_strlen("\x1B[31m"));
	write(1, prompt, ft_strlen(prompt));
	write(1, ">\033[00m", ft_strlen(">\033[00m"));
}

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
		st_prompt(*env);
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
	st_prompt(env);
	while (g_n_l(1, &buff))
	{
		built = 0;
		split = ft_strsplit(buff, ' ');
		if (*split && (built = isbuiltins(*split)) >= 0)
		{
			builtins(built, split, &env);
			st_prompt(env);
		}
		else
		{
			father = fork();
			st_loop(split, father, &env);
		}
	}
}
