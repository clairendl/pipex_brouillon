/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnicolas <cnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 07:25:23 by cnicolas          #+#    #+#             */
/*   Updated: 2021/09/20 11:49:00 by cnicolas         ###   ########.fr       */
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
# include <stddef.h>

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

//parsing
char *ft_parsing_path(char *cmd, char **envp);
char *good_path(char **argv);

//errors
int	ft_verif_input(int argc, char **argv);
int ft_verif_files(int fd[2], int check_path_argv2, int check_path_argv3);
int	ft_read_and_access(int droit_acces, ssize_t file);
int	ft_pipe_and_fork(int fd[2], int id);

//commands
int child_one(int fd[0], char **argv, char **envp);
int child_two(int fd[1], char **argv, char **envp);
#endif
