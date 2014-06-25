/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iswhispa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbir <gbir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 02:30:56 by gbir              #+#    #+#             */
/*   Updated: 2014/04/23 02:31:03 by gbir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iswhispa(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || \
			c == '\r')
		return (1);
	return (0);
}