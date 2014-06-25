/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbir <gbir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 17:45:40 by gbir              #+#    #+#             */
/*   Updated: 2014/04/27 17:45:41 by gbir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <funct_base.h>

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	char	*ret;

	if (!s1)
		return (NULL);
	if (!(cpy = malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	ret = cpy;
	while (*s1)
		*cpy++ = *s1++;
	*cpy = 0;
	return (ret);
}
