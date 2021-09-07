/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 07:25:23 by cnicolas          #+#    #+#             */
/*   Updated: 2021/09/07 11:21:14 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <unistd.h>

//split
char	**ft_split(char *s, char c);
char	**ft_free(char **dst);
size_t	count_char(char *s, char c);
size_t	count_charset(char *s, char c);
int	is_charset(char s, char c);
//utils
int	ft_strlen(char *s);
char	*ft_strchr(char *s, char *str);
char	*ft_strjoin(char *s1, char *s2);

#endif
