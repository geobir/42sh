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
#include <shell.h>
#include <funct_base.h>
#define ST_ENV extern char **environ

ST_ENV;

static void	st_data(t_env *cur, char *str)
{
	char	*tmp;

	tmp = str;
	while (*tmp && *tmp != '=')
		++tmp;
	cur->name = ft_strndup(str, (int)(tmp - str));
	if (*tmp)
		cur->data = ft_strdup(tmp + 1);
	else
	{
		cur->data = malloc(sizeof(char));
		cur->data = 0;
	}
}

t_env		*makeenv(void)
{
	t_env	*ret;
	t_env	*tmp;
	int		i;

	i = 0;
	if (!environ || !*environ)
		return (NULL);
	ret = malloc(sizeof(t_env));
	tmp = ret;
	while (42)
	{
		st_data(tmp, environ[i]);
		if (!environ[++i])
			break ;
		tmp->next = malloc(sizeof(t_env));
		tmp = tmp->next;
		tmp->next = NULL;
	}
	return (ret);
}
