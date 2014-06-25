/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbir <gbir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 01:43:29 by gbir              #+#    #+#             */
/*   Updated: 2014/04/23 01:50:20 by gbir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <funct_base.h>

static int	st_numlen(int c)
{
	int		i;

	i = 0;
	while (c)
	{
		c = c / 10;
		++i;
	}
	return (i);
}

static int	st_puiss(int u, int i)
{
	int		ret;

	ret = u;
	while (i-- > 0)
		ret *= u;
	return (ret);
}

void		ft_putnbr(int n)
{
	int	num;
	int	i;

	i = st_numlen(n);
	if (n < 0)
	{
		n *= -1;
		write(1, "-", 1);
	}
	while (i--)
	{
		num = st_puiss(10, i);
		ft_putchar(n / num + '0');
		n = n % num;
	}
}
