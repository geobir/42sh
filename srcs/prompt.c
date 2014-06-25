/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbir <gbir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 18:29:50 by gbir              #+#    #+#             */
/*   Updated: 2014/06/25 18:30:25 by gbir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <shell.h>
#include <funct_base.h>

void		prompt(t_env *env)
{
	char*prompt;

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
