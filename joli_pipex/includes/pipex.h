/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarasso <tcarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 11:58:53 by tcarasso          #+#    #+#             */
/*   Updated: 2021/08/16 01:46:48 by tcarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <errno.h>
# include <fcntl.h>
# include <string.h>
# include <unistd.h>
# include <stdint.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <stdio.h>

char	*ft_get_cmd_path(char *cmd, char *env[]);
int		ft_put_error(char *s1, char *s2, char *s3, int ret);
int		ft_exec_pipe(char *argv[], char *env[]);

/*UTILS*/

int		ft_data_alloc(void **ptr, size_t size, int n);
char	**ft_split(char const *s, char c);
int		ft_strlenchr(const char *str, char c);
int		ft_strnlen(const char *s, unsigned int n);
char	*ft_strndup(const char *s, size_t n);
int		ft_strncmp(const char *s1, const char *s2, unsigned int n);
void	*is_free(char **tab);
void	ft_free(void **var);
#endif
