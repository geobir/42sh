/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_operator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbir <gbir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 19:54:02 by gbir              #+#    #+#             */
/*   Updated: 2014/06/25 19:54:12 by gbir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		**split_operator(char *ligne)
{
	char**ret;

	if (!(ret = malloc(sizeof(char*) * 2)))
		return (NULL);
	ret[0] = ligne;
	ret[1] = NULL;
	return (ret);
}
