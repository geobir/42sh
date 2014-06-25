/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbir <gbir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 17:45:40 by gbir              #+#    #+#             */
/*   Updated: 2014/04/27 17:45:41 by gbir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <funct_base.h>

char	*ft_strndup(const char *s1, int n)
{
	int		len;
	char	*cpy;
	char	*ret;

	len = ft_strlen(s1);
	if (len > n)
	{
		if (!(cpy = malloc(sizeof(char) * (n + 1))))
			return (NULL);
		ret = cpy;
		while (n--)
			*cpy++ = *s1++;
		*cpy = 0;
	}
	else
		return (ft_strdup(s1));
	return (ret);
}
