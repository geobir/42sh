/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbir <gbir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 01:36:28 by gbir              #+#    #+#             */
/*   Updated: 2014/04/23 01:44:49 by gbir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <funct_base.h>

void		ft_putstr(char const *s)
{
	write(1, s, ft_strlen(s));
}
