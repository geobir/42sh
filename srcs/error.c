/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbir <gbir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 18:16:06 by gbir              #+#    #+#             */
/*   Updated: 2014/06/25 18:16:55 by gbir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>
#include <unistd.h>
#include <funct_base.h>

void	errorCMD(char *cmd)
{
	ft_putstr(ER_CMD);
	ft_putstr(cmd);
	write(1, "\n", 1);
}
