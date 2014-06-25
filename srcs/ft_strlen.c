/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbir <gbir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 01:44:05 by gbir              #+#    #+#             */
/*   Updated: 2014/04/23 01:44:30 by gbir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(const char *s)
{
	char	*tmp;

	tmp = (char *)s;
	while (*tmp)
		++tmp;
	return (tmp - s);
}