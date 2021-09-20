/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnicolas <cnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 11:40:41 by cnicolas          #+#    #+#             */
/*   Updated: 2021/09/20 15:37:08 by cnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int child_one(int fd[0], char **argv, char **envp)
{
	dup2(fd[0], STDIN_FILENO); // we want fd[0] to be execve() input
	dup2(fd[1], STDOUT_FILENO); // we want fd[1] to be execve() stdout
	if (dup2(fd[0], STDIN_FILENO) < 0 || dup2(fd[1], STDOUT_FILENO) < 0)
	{
		perror("dup2 error");
		exit(EXIT_FAILURE);
	}
	close(fd[0]);
	close(fd[1]);
	if (good_path(argv) != NULL)
		execve(argv[1], &argv[2], NULL);
	else
		ft_parsing_path(argv[2], envp);
	return (0);
}

int child_two(int fd[1], char **argv, char **envp)
{
	dup2(fd[0], STDOUT_FILENO); // we want f1 to be execve() input
								//dup2(fd[1], STDOUT_FILENO); // we want end[1] to be execve() stdout
	if ((dup2(fd[0], STDOUT_FILENO)) < 0)
	{
		perror("dup2 error");
		exit(EXIT_FAILURE);
	}
	close(fd[1]);
	close(fd[0]);
	if (good_path(argv) != NULL)
		execve(argv[4], &argv[3], NULL);
	else
		ft_parsing_path(argv[3], envp);
	return (0);
}