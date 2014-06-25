/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funct_base.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbir <gbir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 01:38:46 by gbir              #+#    #+#             */
/*   Updated: 2014/04/23 01:39:27 by gbir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCT_BASE_H
# define FUNCT_BASE_H

void		ft_putchar(char c);
void		ft_putstr(char const *s);
int			ft_strclen(char *s, char c);
int			ft_strlen(const char *s);
void		ft_putnbr(int n);
int			ft_isdigit(int c);
int			ft_isalpha(int c);
int			ft_isalnum(int c);
int			ft_iswhispa(int c);
char		*ft_strjoin(char const *s1, char const *s2);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, int n);
char		**ft_strsplit(char const *s, char c);
char		*ft_strdup(const char *s1);
char		*ft_strndup(const char *s1, int n);

#endif
