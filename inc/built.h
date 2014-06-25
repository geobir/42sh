/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbir <gbir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 00:47:22 by gbir              #+#    #+#             */
/*   Updated: 2014/04/27 00:47:53 by gbir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_H
# define BUILT_H

# include <shell.h>

# define BUILIINS "cd", "setenv", "unsetenv", "env", "exit", NULL
# define ER_B_PATH "cd: no such file or directory: "
# define ER_NOHOME "env: HOME not found\n", 20

void	built_cd(char *path, t_env *env);
void	built_exit(void);
void	built_env(t_env *env);
void	built_unsetenv(char *unset, t_env **env);
void	built_setenv(char *name, char *data, t_env **env);

#endif
