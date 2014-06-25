/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   takeenv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbir <gbir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 20:19:20 by gbir              #+#    #+#             */
/*   Updated: 2014/06/25 20:19:21 by gbir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <shell.h>
#include <funct_base.h>

char		**takeenv(t_env *env)
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
