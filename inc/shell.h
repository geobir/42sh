/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbir <gbir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 04:05:19 by gbir              #+#    #+#             */
/*   Updated: 2014/04/23 04:05:39 by gbir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# define ER_EXEC "Fork error."
# define PROMPT "\x1B[31m$>\033[00m", 12
# define ER_CMD "zsh: command not found: "

typedef struct s_env	t_env;

struct			s_env
{
	char		*name;
	char		*data;
	t_env		*next;
};

void			mainshell(void);
int				iscmd(char *cmd, char **way, t_env *env);
char			*shearchcmd(char *path, char *cmd);
int				isbuiltins(char *cmd);
void			builtins(int built, char **arg, t_env **env);
t_env			*makeenv(void);

#endif
