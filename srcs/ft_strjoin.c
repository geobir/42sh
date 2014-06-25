/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbir <gbir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 02:37:10 by gbir              #+#    #+#             */
/*   Updated: 2014/04/23 02:37:10 by gbir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <funct_base.h>

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	char	*cur;
	int		n;

	if (s1 && s2)
	{
		n = ft_strlen(s1) + ft_strlen(s2);
		s = (char*)malloc(sizeof(char) * (n + 1));
		cur = s;
		if (s != NULL)
		{
			while (*s1 && n--)
				*cur++ = *s1++;
			while (*s2 && n--)
				*cur++ = *s2++;
			*cur = '\0';
			return (s);
		}
	}
	return (0);
}
