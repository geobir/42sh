/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_cd.c                                         :+:      :+:    :+:   */
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
#include <built.h>
#include <stdio.h>

static void	st_err(char *path)
{
	ft_putstr(ER_B_PATH);
	ft_putstr(path);
	write(1, "\n", 1);
}

static int	st_cd_home(t_env *env)
{
	while (env && env->name && env->data)
	{
		if (ft_strcmp(env->name, "HOME") == 0)
		{
			if (chdir(env->data) < 0)
				st_err(env->data);
			break ;
		}
		env = env->next;
	}
	if (!env)
		write(1, ER_NOHOME);
	return (1);
}

void		built_cd(char *path, t_env *env)
{
	char	cur[256];
	char	*tmp;
	char	*fre;

	if ((!path || !*path) && st_cd_home(env))
		return ;
	if (*path == '/')
	{
		if (chdir(path) < 0)
			st_err(path);
		return ;
	}
	getcwd(cur, sizeof(cur));
	fre = ft_strjoin(cur, "/");
	tmp = ft_strjoin(fre, path);
	free(fre);
	if (chdir(tmp) < 0)
		st_err(path);
	free(tmp);
}
